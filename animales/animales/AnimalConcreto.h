#ifndef ANIMALCONCRETO_H
#define ANIMALCONCRETOR_H
#include"Animal.h"

class AnimalConcreto : public Animal {
public:
	AnimalConcreto(std::string);
	~AnimalConcreto();
	std::string toString();
};

#endif 

