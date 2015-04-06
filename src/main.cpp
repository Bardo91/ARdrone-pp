///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		ARdrone++: main test-case
//			Author: Pablo R.S. (A.k.a. Bardo91)
//			Date:	2015-APR-06
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main to test library


#include "core/comm/UdpSocket.h"
#include "core/time/Time.h"

int main(int _argc, char **_argv){
	_argc;
	_argv;

	ardronepp::UdpSocket control("192.168.1.1", 5556);

	control.send("AT*REF=101,290718208\r");

	ardronepp::STime::get()->delay(1);

	control.send("AT*REF=102,290717696\r");



	system("PAUSE");

}