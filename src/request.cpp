#include "request.hpp"

Request::Request()
{

};

char* Request::get_method()
{

};

char* Request::get_headers()
{

};

char* Request::get_body()
{

};

#include <iostream>
char* Request::get_startline()
{
	if(!request_str) return 0;

	char* newline = strchr(request_str, '\n');

	if(!newline) return 0;

	size_t len = newline - request_str;

	if(len > 0 && request_str[len-1] == '\r') len--;	

	char* startline = new char[len + 1];
	memcpy(startline, request_str, len);
	startline[len] = 0;

	return startline;
};

void Request::set_request_str(const char* req)
{
	if(!request_str)
		delete[] request_str;

	request_str = new char[strlen(req)];

	strncpy(request_str, req, strlen(req));
	request_str[strlen(req)] = 0;
};	