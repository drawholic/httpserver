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

char* Request::get_startline()
{

};

void Request::set_request_str(char* req)
{
	if(request_str)
		delete[] request_str;
	request_str = new char[strlen(req)];
	strncpy(request_str, req, strlen(request_str));

};