#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <cstring>

class Request
{
	char* request_str;


public:
	Request();

	char* get_method();


	char* get_startline();
	char* get_headers();
	char* get_body();
	char* get_url();

	void set_request_str(const char*);
};

enum RequestEnum
{
	GET,
	POST,
	DELETE,
	HEAD,
	PATCH,
	PUT
};
RequestEnum get_request_enum(const char*);

#endif