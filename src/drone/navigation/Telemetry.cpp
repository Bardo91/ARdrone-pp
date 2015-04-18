///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		ARdrone++: library
//			Author: Pablo R.S. (A.k.a. Bardo91)
//			Date:	2015-APR-07
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Telemetry


#include "Telemetry.h"

#include "../../core/time/TimeTools.h"

using namespace std;
using namespace ardronepp::navdata;

namespace ardronepp{
	//-----------------------------------------------------------------------------------------------------------------
	// Public interface
	Telemetry::Telemetry(UdpSocket *_controlSocket):	mTelemetrySocket("192.168.1.1",5554),
														mControlSocket(_controlSocket),
														mAcquire(true) {
		mTelemetrySocket.send("\x01\x00\x00\x00");

		// AR.Drone 2.0
		// Disable BOOTSTRAP mode
		mControlSocket->send("AT*CONFIG=2,\"general:navdata_demo\",\"FALSE\"\r");
		STime::get()->mDelay(100);

		// Seed ACK
		mControlSocket->send("AT*CTRL=3,0\r");
		
		mAcquisitionThread = new thread(&Telemetry::acquisitionCallback, this);
		
	}
	
	//-----------------------------------------------------------------------------------------------------------------
	Telemetry::~Telemetry(){
		mAcquire = false;
		if (mAcquisitionThread->joinable())
			mAcquisitionThread->join();	
	}
	//-----------------------------------------------------------------------------------------------------------------
	array<array<float, 3>, 3> Telemetry::orientation(){
		lock_guard<mutex> lock(mSecureAcquisition);
		return array<array<float, 3>, 3>{{ 
			array<float, 3>{{ mOrientation.m11, mOrientation.m12, mOrientation.m13 }},
			array<float, 3>{{ mOrientation.m21, mOrientation.m22, mOrientation.m23 }},
			array<float, 3>{{ mOrientation.m31, mOrientation.m32, mOrientation.m33 }} 
		}};
	}

	//-----------------------------------------------------------------------------------------------------------------
	array<float, 3> Telemetry::position(){
		lock_guard<mutex> lock(mSecureAcquisition);
		return array<float, 3>{{ mPosition.x, mPosition.y, mPosition.z }};
	}

	//-----------------------------------------------------------------------------------------------------------------
	array<float, 3> Telemetry::speed(){
		lock_guard<mutex> lock(mSecureAcquisition);
		return array<float, 3>{{ mSpeeds.x, mSpeeds.y, mSpeeds.z }};
	}

	//-----------------------------------------------------------------------------------------------------------------
	// Private methods
	void Telemetry::acquisitionCallback(){
		while(mAcquire){
			update();
			STime::get()->delay(100);
		}
	}

	//-----------------------------------------------------------------------------------------------------------------
	void Telemetry::update(){
		mTelemetrySocket.send("\x01\x00\x00\x00");	// Send request

		std::string buffer = mTelemetrySocket.receive();

		int size = buffer.size();

		if(buffer.size() > 0){
			mSecureAcquisition.lock();
			int index = 0;
			memcpy((void*)&(mMsgHeader), (const void*)(buffer.c_str() + index), 4); index += 4;
			memcpy((void*)&(mState), (const void*)(buffer.c_str() + index), 4); index += 4;
			memcpy((void*)&(mSequenceNumber), (const void*)(buffer.c_str() + index), 4); index += 4;
			index += 4;

			// Parse navdata
			while (index < size) {
				// Tag and data size
				unsigned short tmp_tag, tmp_size;
				memcpy((void*)&tmp_tag, (const void*)(buffer.c_str() + index), 2); index += 2;  // tag
				memcpy((void*)&tmp_size, (const void*)(buffer.c_str() + index), 2); index += 2;  // size
				index -= 4;

				// Copy to NAVDATA structure
				switch (tmp_tag) {
				case NAVDATA_TAG::TIME_TAG:
					memcpy((void*)&(mTimeStamp), (const void*)(buffer.c_str() + index), tmp_size < sizeof(mTimeStamp) ? tmp_size : sizeof(mTimeStamp));
					break;
				case NAVDATA_TAG::PHYS_MEASURES_TAG:
					memcpy((void*)&(mRawImu), (const void*)(buffer.c_str() + index), tmp_size < sizeof(mRawImu) ? tmp_size : sizeof(mRawImu));
					break;
				case NAVDATA_TAG::EULER_ANGLES_TAG:
					memcpy((void*)&(mOrientation), (const void*)(buffer.c_str() + index), tmp_size < sizeof(mRawImu) ? tmp_size : sizeof(mOrientation));
					break;
				case NAVDATA_TAG::ALTITUDE_TAG:
					memcpy((void*)&(mAltitude), (const void*)(buffer.c_str() + index), tmp_size < sizeof(mRawImu) ? tmp_size : sizeof(mAltitude));
					break;
				case NAVDATA_TAG::WATCHDOG_TAG:
					memcpy((void*)&(mWatchDog), (const void*)(buffer.c_str() + index), tmp_size < sizeof(mRawImu) ? tmp_size : sizeof(mWatchDog));
					break;
				case NAVDATA_TAG::PRESSURE_RAW_TAG:
					memcpy((void*)&(mRawPressure), (const void*)(buffer.c_str() + index), tmp_size < sizeof(mRawImu) ? tmp_size : sizeof(mRawPressure));
					break;
				case NAVDATA_TAG::MAGNETO_TAG:
					memcpy((void*)&(mMagneto), (const void*)(buffer.c_str() + index), tmp_size < sizeof(mRawImu) ? tmp_size : sizeof(mMagneto));
					break;
				case NAVDATA_TAG::WIND_TAG:
					memcpy((void*)&(mWind), (const void*)(buffer.c_str() + index), tmp_size < sizeof(mRawImu) ? tmp_size : sizeof(mWind));
					break;
				case NAVDATA_TAG::KALMAN_PRESSURE_TAG:
					memcpy((void*)&(mPressureFiltered), (const void*)(buffer.c_str() + index), tmp_size < sizeof(mRawImu) ? tmp_size : sizeof(mPressureFiltered));
					break;
				case NAVDATA_TAG::WIFI_TAG:
					memcpy((void*)&(mWifiStatus), (const void*)(buffer.c_str() + index), tmp_size < sizeof(mRawImu) ? tmp_size : sizeof(mWifiStatus));
					break;
				}
				index += tmp_size;
			mSecureAcquisition.unlock();
			}
		}

	}

}	//	namespace ardronepp