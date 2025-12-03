#ifndef REQUEST_HPP
#define REQUEST_HPP

class Request
{
	char* request_str;


public:
	Request();

	char* get_method();


	char* get_startline();
	char* get_headers();
	char* get_body();
};

#endif