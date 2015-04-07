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

namespace ardronepp{

	class Ardrone{
	public:
		Ardrone();

		void setGroundReference();

		void takeOff();
		void land();
		void hovering();
		void spin(float _yawSpeed);
		void lift(float _vSpeed);
		void translate(float _pitch, float _roll);

	private:
		UdpSocket mControlSocket, mNavDataSocket;
		unsigned mCommandCounter;
	};	//	class Ardrone

}	//	namespace ardronepp

#endif // ARDRONEPP_ARDRONE_H_

