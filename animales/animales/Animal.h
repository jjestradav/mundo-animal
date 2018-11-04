#ifndef ANIMAL_H
#define ANIMAL_H
#include<string>
#include<sstream>

class Animal {
protected:
	std::string dato;
public:
	Animal(std::string);
	virtual ~Animal();
	virtual std::string toString() = 0;
	virtual std::string toStringV2()= 0;
};

#endif
