#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
#include <sstream>
class Exception{
private:
	std::string message;
public:
	Exception(std::string);
	~Exception();
	std::string getMessage();
	std::string toString();
};
#endif


