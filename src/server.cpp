#include "server.hpp"


Server::Server()
{

	setup();
};


void Server::setup()
{
	int opt = 1;
	int addrlen = sizeof(sockaddr);


	socket = socket(AF_INET, SOCK_STREAM, 0);
	if(socket == 0)
	{
		perror("socket failure");
		exit(EXIT_FAILURE);
	}

	if(setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
	{
		perror("setsockopt SO_REUSEADDR failed");
		close(socket);
		exit(EXIT_FAILURE);
	};

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = port = htons(8080);

	if(bind(socket, (struct sockaddr*)&addr, addrlen) < 0)
	{
		perror("bind failed");
		close(socket);
		exit(EXIT_FAILURE);
	};

	if(listen(socket, 5) == -1)
	{
		perror("listen failed");
		close(socket);
		exit(EXIT_FAILURE);
	}
};