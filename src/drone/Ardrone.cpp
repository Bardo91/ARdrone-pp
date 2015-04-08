///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		ARdrone++: library
//			Author: Pablo R.S. (A.k.a. Bardo91)
//			Date:	2015-APR-06
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Main Ardrone class


#include "Ardrone.h"

#include <cstring>
#include <sstream>

namespace ardronepp{
	//---------------------------------------------------------------------------------------------------------------------
	Ardrone::Ardrone() : mControlSocket("192.168.1.1", 5556), mCommandCounter(1) {
		
	}

	//---------------------------------------------------------------------------------------------------------------------
	void Ardrone::setGroundReference(){
		// assert(not flying);
		std::stringstream ATstream;
		ATstream << "AT*FTRIM=" << mCommandCounter++ << "\r";

		mControlSocket.send(ATstream.str());
	}

	//---------------------------------------------------------------------------------------------------------------------
	void Ardrone::takeOff(){
		std::stringstream ATstream;
		ATstream << "AT*REF=" << mCommandCounter++ << ",290718208\r";
		
		mControlSocket.send(ATstream.str());
	}

	//---------------------------------------------------------------------------------------------------------------------
	void Ardrone::land(){
		std::stringstream ATstream;
		ATstream << "AT*REF=" << mCommandCounter++ << ",290717696\r";

		mControlSocket.send(ATstream.str());
	}

	//---------------------------------------------------------------------------------------------------------------------
	void Ardrone::hovering(){
		std::stringstream ATstream;
		ATstream << "AT*PCMD=" << mCommandCounter++ << ",1,0,0,0,0\r";

		mControlSocket.send(ATstream.str());
	}

	//---------------------------------------------------------------------------------------------------------------------
	void Ardrone::spin(float _yawSpeed){
		int yawSpeed;
		memcpy(&yawSpeed, &_yawSpeed, sizeof(float));
		
		std::stringstream ATstream;
		ATstream << "AT*PCMD=" << mCommandCounter++ << ",1,0,0,0," << yawSpeed << "\r";

		mControlSocket.send(ATstream.str());
	}

	//---------------------------------------------------------------------------------------------------------------------
	void Ardrone::lift(float _vSpeed){
		int vSpeed;
		memcpy(&vSpeed, &_vSpeed, sizeof(float));

		std::stringstream ATstream;
		ATstream << "AT*PCMD=" << mCommandCounter++ << ",1,0,0," << vSpeed << ",0\r";

		mControlSocket.send(ATstream.str());
	}

	//---------------------------------------------------------------------------------------------------------------------
	void Ardrone::translate(float _pitch, float _roll){
		_pitch = -_pitch;	// Negative value get nose down, so move forward.

		int pitch, roll;
		memcpy(&pitch, &_pitch, sizeof(float));
		memcpy(&roll, &_roll, sizeof(float));

		std::stringstream ATstream;
		ATstream << "AT*PCMD=" << mCommandCounter++ << ",1," << roll << "," << pitch << ",0,0\r";

		mControlSocket.send(ATstream.str());
	}

}	//	namespace ardronepp