#include "server.hpp"


Server::Server()
{

	setup();
};


void Server::setup()
{
	int opt = 1;
	int addrlen = sizeof(sockaddr);


	fd = socket(AF_INET, SOCK_STREAM, 0);
	if(fd == 0)
	{
		perror("socket failure");
		exit(EXIT_FAILURE);
	}

	if(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
	{
		perror("setsockopt SO_REUSEADDR failed");
		close(fd);
		exit(EXIT_FAILURE);
	};

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = port = htons(8080);

	if(bind(fd, (struct sockaddr*)&addr, addrlen) < 0)
	{
		perror("bind failed");
		close(fd);
		exit(EXIT_FAILURE);
	};

	if(listen(fd, 5) == -1)
	{
		perror("listen failed");
		close(fd);
		exit(EXIT_FAILURE);
	}
};

void Server::receive_message(int client)
{
	size_t bytes;

	while(bytes = recv(client, buffer, BUF_MAX-1, 0))
	{
		buffer[bytes] = 0;
	};

};

void Server::handle_client(int client)
{
	
	receive_message(client);

	Request r;
	get_request(client, r);

	respond_client(client, r);


};

void Server::get_request(int client, Request& r)
{

	r.set_request_str(buffer);
	
};

void Server::loop()
{
	int client;
	unsigned bytes;

	while(client = accept(fd, 0, 0))
	{
		handle_client(client);


		close(client);
	};
};