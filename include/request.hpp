#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <cstring>

class Request
{
	char* request_str;

	char* headers;
	char* method;
	char* url;
	char* startline;
	
public:
	Request();

	char* get_method();


	char* get_startline();
	char* get_headers();
	char* get_body();
	char* get_url();

	void set_request_str(const char*);
};

enum MethodEnum
{
	GET,
	POST,
	DELETE,
	HEAD,
	PATCH,
	PUT
};
MethodEnum get_method_enum(const char*);

#endif