#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include "request.hpp"

class Response
{

	char* status_line;

	char* status_code;
	char* reason_phrase;
	char* headers;
	char* body;

public:
	Response();
	void set_request(Request&);
	char* get_response_str();

};

#endif