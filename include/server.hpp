#ifndef SERVER_HPP
#define SERVER_HPP


#include "sys/socket.h"
#include <netinet/in.h>
#include <unistd.h>

const int BUF_MAX = 2048;

class Server
{
	int socket;
	sockaddr_in addr;
	uint16_t port;

	void setup();

	char buffer[BUF_MAX];

public:
	Server();
	void loop();
};

#endif