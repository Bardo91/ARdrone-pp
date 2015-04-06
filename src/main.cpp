///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		ARdrone++: main test-case
//			Author: Pablo R.S. (A.k.a. Bardo91)
//			Date:	2015-APR-06
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main to test library


#include "Ardrone.h"
#include "core/time/Time.h"
#include <cstdint>

int main(int _argc, char **_argv){
	_argc;
	_argv;

	ardronepp::Ardrone drone;
	
	drone.takeOff();

	system("PAUSE"); 

	drone.spin(0.1f);

	system("PAUSE");
	drone.land();
	
	system("PAUSE"); 

}