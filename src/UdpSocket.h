///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		ARdrone++: library
//			Author: Pablo R.S. (A.k.a. Bardo91)
//			Date:	2015-APR-06
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	UdpSocket is an UDP socket implementation that fits ARdrone needs.


#ifndef ARDRONEPP_CORE_COMM_UDP_SOCKET_H_
#define ARDRONEPP_CORE_COMM_UDP_SOCKET_H_

#if defined(_WIN32)
	#define WIN32_LEAN_AND_MEAN

	#include <Windows.h>
	#include <winsock2.h>
	#include <ws2tcpip.h>

	#pragma comment (lib, "Ws2_32.lib")
	#pragma comment (lib, "Mswsock.lib")
	#pragma comment (lib, "AdvApi32.lib")
#endif

#include <string>

namespace ardronepp{

	class UdpSocket{
	public:	// Public interface
		UdpSocket(const std::string &_droneIp, unsigned _port);

		int send(const std::string &_msg);
		std::string receive();

	private:	// Private methods
		void configureAddrs(const std::string &_droneIp, unsigned _port);

	private:	// Private members
		SOCKET mSocket;
		sockaddr_in mDroneAddr, mClientAddr;

	};	//	 Class UdpSocket
}	//	namespace ardronepp

#endif	//	ARDRONEPP_CORE_COMM_UDP_SOCKET_H_
