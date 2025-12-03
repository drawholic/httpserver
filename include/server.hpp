#ifndef SERVER_HPP
#define SERVER_HPP


#include "sys/socket.h"
#include <netinet/in.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>

const int BUF_MAX = 1024;

class Server
{
	int fd;
	sockaddr_in addr;
	uint16_t port;

	void setup();

	char buffer[BUF_MAX];

	void handle_client();

	

public:
	Server();
	void loop();
};

#endif