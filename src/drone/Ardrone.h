///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		ARdrone++: library
//			Author: Pablo R.S. (A.k.a. Bardo91)
//			Date:	2015-APR-06
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Main Ardrone class

#ifndef ARDRONEPP_ARDRONE_H_

#include "../core/comm/UdpSocket.h"
#include "navigation/Telemetry.h"

namespace ardronepp{

	class Ardrone{
	public:
		Ardrone();

		void setGroundReference();

		void takeOff();
		void land();
		void hovering();
		void spin(float _yawSpeed);					// _yawSpeed	= [-1, 1]	left - right
		void lift(float _vSpeed);					// _vSpeed		= [-1, 1]	ip - down
		void translate(float _pitch, float _roll);	// _pitch		= [-1, 1]	front - back
													// _roll		= [-1, 1]	left - right

	private:
		UdpSocket mControlSocket;
		unsigned mCommandCounter;

		Telemetry mTelemeter;
		
	};	//	class Ardrone

}	//	namespace ardronepp

#endif // ARDRONEPP_ARDRONE_H_

