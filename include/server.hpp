#ifndef SERVER_HPP
#define SERVER_HPP


#include "sys/socket.h"
#include <netinet/in.h>
#include <unistd.h>



class Server
{
	int socket;
	sockaddr_in addr;
	uint16_t port;

	void setup();

public:
	Server();
	void loop();
};

#endif