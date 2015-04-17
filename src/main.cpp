///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		ARdrone++: main test-case
//			Author: Pablo R.S. (A.k.a. Bardo91)
//			Date:	2015-APR-06
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main to test library


#include <drone/Ardrone.h>
#include <core/time/TimeTools.h>

#include <iostream>

int main(int _argc, char **_argv){
	_argc;
	_argv;
	
	ardronepp::Ardrone drone;
	drone.setGroundReference();
	
	int cmd = 0;
	do{
		std::cout << "Choose command: " << std::endl;
		std::cout << "\t 0--> Land: " << std::endl;
		std::cout << "\t 1--> Take off: " << std::endl;
		std::cout << "\t 2--> Turn right: " << std::endl;
		std::cout << "\t 3--> Turn left: " << std::endl;
		std::cout << "\t 4--> Move front: " << std::endl;
		std::cout << "\t 5--> Move back: " << std::endl;
		std::cout << "\t 6--> Move right: " << std::endl;
		std::cout << "\t 7--> Move left: " << std::endl;

		std::cin >> cmd;
		
		double t0 = ardronepp::STime::get()->getTime();

		switch (cmd){
		case 0:	// Landing
			drone.land();	
			break;
		case 1:	// Take off
			drone.takeOff();
			drone.hovering();
			break;
		case 2:	// Spin left
			while (ardronepp::STime::get()->getTime() - t0 < 2){
				drone.spin(0.1f);
			}
			break;
		case 3:	// Spin right
			while (ardronepp::STime::get()->getTime() - t0 < 2){
				drone.spin(-0.1f);
			}
			break;
		case 4:	// Move front
			while (ardronepp::STime::get()->getTime() - t0 < 1){
				drone.translate(0.1f, 0.0f);
			}
			break;
		case 5:	// Move back
			while (ardronepp::STime::get()->getTime() - t0 < 1){
				drone.translate(-0.1f, 0.0f);
			}
			break;
		case 6:	// Move Right
			while (ardronepp::STime::get()->getTime() - t0 < 1){
				drone.translate(0.0f, 0.1f);
			}
			break;
		case 7:	// Move left
			while (ardronepp::STime::get()->getTime() - t0 < 1){
				drone.translate(0.0f, -0.1f);
			}
			break;
		}
	} while (cmd != 8);
}