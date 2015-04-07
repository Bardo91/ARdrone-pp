///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		ARdrone++: library
//			Author: Pablo R.S. (A.k.a. Bardo91)
//			Date:	2015-APR-07
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Telemetry


#include "Telemetry.h"

#include "../../core/time/Time.h"

using namespace std;

namespace ardronepp{
	//-----------------------------------------------------------------------------------------------------------------
	// Public interface
	Telemetry::Telemetry(): mTelemetrySocket("192.168.1.1", 5554), mAcquisitionThread(&Telemetry::acquisitionCallback, this) {

	}
	
	//-----------------------------------------------------------------------------------------------------------------
	Telemetry::~Telemetry(){
		mAcquire = false;
		if (mAcquisitionThread.joinable())
			mAcquisitionThread.join();	
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

		if(buffer.size() > 0){

		}

	}

}	//	namespace ardronepp