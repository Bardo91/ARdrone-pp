///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		ARdrone++: main test-case
//			Author: Pablo R.S. (A.k.a. Bardo91)
//			Date:	2015-APR-06
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main to test library


#include <drone/Ardrone.h>
#include <core/time/Time.h>

int main(int _argc, char **_argv){
	_argc;
	_argv;

	ardronepp::Ardrone drone;
	system("PAUSE");
	drone.setGroundReference();
	drone.takeOff();
	drone.hovering();
	system("PAUSE"); 
	double t0 = ardronepp::STime::get()->getTime();
	while (ardronepp::STime::get()->getTime() - t0 < 2){
		drone.spin(0.5f);
	}
	system("PAUSE");
	drone.land();
	system("PAUSE"); 

}