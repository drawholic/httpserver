#include "request.hpp"

Request::Request()
{
	request_str = 0;
};

char* Request::get_method()
{
	if(!request_str) return 0;
	char* space = strchr(request_str, ' ');

	if(!space) return 0;

	size_t len = space - request_str;

	char* method = new char[len+1];
	memcpy(method, request_str, len);
	method[len] = 0;

	return method;
};

char* Request::get_body()
{

};

char* Request::get_url()
{
	if(!request_str) return 0;

	char* space1 = strchr(request_str, ' ');
	if(!space1) return 0;

	char* space2 = strchr(space1 + 1, ' ');

	if(!space2) return 0;

	size_t len = space2 - (space1 + 1);

	char* url = new char[len+1];
	memcpy(url, space1+1, len);
	url[len] = 0;

	return url;
};
#include <iostream>

char* Request::get_headers()
{
	const char* start_of_headers = strstr(request_str, "\r\n")+2;
	
	if(!start_of_headers) return 0;

	const char* end_of_headers = strstr(request_str, "\r\n\r\n");

	if(!end_of_headers) return 0;

	size_t len = end_of_headers - start_of_headers;

	char* headers = new char[len+1];

	memcpy(headers, start_of_headers, len);
	headers[len] = 0;
	return headers;
};

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
	if(request_str)
		delete[] request_str;

	request_str = new char[strlen(req)];

	strncpy(request_str, req, strlen(req));
	request_str[strlen(req)] = 0;
};	

MethodEnum get_method_enum(const char* method)
{
	if(!strcmp(method, "GET"))
		return GET;
	if(!strcmp(method, "POST"))
		return POST;
	if(!strcmp(method, "DELETE"))
		return DELETE;
	if(!strcmp(method, "HEAD"))
		return HEAD;
	if(!strcmp(method, "PATCH"))
		return PATCH;
	if(!strcmp(method, "PUT"))
		return PUT;
};