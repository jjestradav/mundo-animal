#include "Exception.h"

Exception::Exception(std::string _message){
	message = _message;
}

Exception::~Exception(){
}

std::string Exception::getMessage()
{
	return message;
}

std::string Exception::toString(){
	std::stringstream s;
	s << "Error: " << message << std::endl;
	return s.str();
}
