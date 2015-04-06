///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		ARdrone++: library
//			Author: Pablo R.S. (A.k.a. Bardo91)
//			Date:	2015-APR-06
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Main Ardrone class


#include "Ardrone.h"

#include <sstream>

namespace ardronepp{
	//---------------------------------------------------------------------------------------------------------------------
	Ardrone::Ardrone() : mControlSocket("192.168.1.1", 5556), mCommandCounter(1) {
		
	}

	//---------------------------------------------------------------------------------------------------------------------
	void Ardrone::takeOff(){
		std::stringstream ATstream;
		ATstream << "AT*PCMD=" << mCommandCounter << ",290718208\r";
		
		mControlSocket.send(ATstream.str().c_str());
		mCommandCounter++;
	}

	//---------------------------------------------------------------------------------------------------------------------
	void Ardrone::land(){
		std::stringstream ATstream;
		ATstream << "AT*PCMD=" << mCommandCounter << ",290717696\r";

		mControlSocket.send(ATstream.str().c_str());
		mCommandCounter++;
	}

	//---------------------------------------------------------------------------------------------------------------------
	void Ardrone::hovering(){
		std::stringstream ATstream;
		ATstream << "AT*PCMD=" << mCommandCounter << ",1,0,0,0,0\r";

		mControlSocket.send(ATstream.str().c_str());
		mCommandCounter++;
	}

	//---------------------------------------------------------------------------------------------------------------------
	void Ardrone::spin(float _yawSpeed){
		int yawSpeed;
		memcpy(&yawSpeed, &_yawSpeed, sizeof(float));
		
		std::stringstream ATstream;
		ATstream << "AT*PCMD=" << mCommandCounter << ", 1, 0, 0, 0, " << yawSpeed << "\r";

		mControlSocket.send(ATstream.str().c_str());
		mCommandCounter++;
	}

	//---------------------------------------------------------------------------------------------------------------------
	void Ardrone::lift(float _vSpeed){
		int vSpeed;
		memcpy(&vSpeed, &_vSpeed, sizeof(float));

		std::stringstream ATstream;
		ATstream << "AT*PCMD=" << mCommandCounter << ",1,0,0," << vSpeed << ",0\r";

		mControlSocket.send(ATstream.str().c_str());
		mCommandCounter++;
	}

	//---------------------------------------------------------------------------------------------------------------------
	void Ardrone::translate(float _pitch, float _roll){
		int pitch, roll;
		memcpy(&pitch, &_pitch, sizeof(float));
		memcpy(&roll, &_roll, sizeof(float));

		std::stringstream ATstream;
		ATstream << "AT*PCMD=" << mCommandCounter << ",1," << pitch << "," << roll << ",0,0\r";

		mControlSocket.send(ATstream.str().c_str());
		mCommandCounter++;
	}

}	//	namespace ardronepp