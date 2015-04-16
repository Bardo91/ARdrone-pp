///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		ARdrone++: library
//			Author: Pablo R.S. (A.k.a. Bardo91)
//			Date:	2015-APR-07
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Telemetry


#ifndef ARDRONEPP_DRONE_NAVIGATION_TELEMETRY_H_
#define ARDRONEPP_DRONE_NAVIGATION_TELEMETRY_H_

#include "NavigationData.h"
#include "../../core/comm/UdpSocket.h"

#include <array>
#include <mutex>
#include <string>
#include <thread>

namespace ardronepp{
	class Telemetry{
	public:		// Public interface
		Telemetry(UdpSocket *_telemetrySocket, UdpSocket *_controlSocket);
		~Telemetry();

		std::array<std::array<float, 3>, 3>		orientation();
		std::array<float, 3>					position();
		std::array<float, 3>					speed();

	private:	// Private methods
		void acquisitionCallback();
		void update();

	private:	// Private members
		UdpSocket					*mControlSocket;
		UdpSocket					*mTelemetrySocket;
		bool						mAcquire;
		std::thread					*mAcquisitionThread;
		std::mutex					mSecureAcquisition;

		//	ARdrone telemetry
		unsigned int				mMsgHeader;
		unsigned int				mState;
		unsigned int				mSequenceNumber;


		navdata::TimeStamp			mTimeStamp;
		navdata::EulerMat			mOrientation;
		navdata::Position			mPosition;
		navdata::Altitude			mAltitude;
		navdata::Speeds				mSpeeds;

		navdata::RawImu				mRawImu;
		navdata::RawPressure		mRawPressure;
		navdata::PressureFiltered	mPressureFiltered;
		navdata::Magneto			mMagneto;
		navdata::Wind				mWind;

		navdata::WatchDog			mWatchDog;
		navdata::Wifi				mWifiStatus;
		navdata::CheckSum			mCheckSum;

	};
}


#endif // ARDRONEPP_DRONE_NAVIGATION_TELEMETRY_H_
