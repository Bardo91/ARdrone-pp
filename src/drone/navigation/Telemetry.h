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

namespace ardronepp{
	class Telemetry{
	public:



	private:
		unsigned int				mMsgHeader;
		unsigned int				mState;
		unsigned int				mSequenceNumber;


		navdata::TimeStamp			mTimeStamp;
		navdata::EulerMat			mOrientation;
		navdata::Position			mPosition;
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
