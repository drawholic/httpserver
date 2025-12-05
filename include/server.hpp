#ifndef SERVER_HPP
#define SERVER_HPP


#include "sys/socket.h"
#include <netinet/in.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "request.hpp"

const int BUF_MAX = 1024;

class Server
{
	int fd;
	sockaddr_in addr;
	uint16_t port;

	void setup();

	char buffer[BUF_MAX];

	void handle_client(int);
	void get_request(int);
	void respond_client(int, Request);
	void receive_message(int);

public:
	Server();
	void loop();
};

#endif