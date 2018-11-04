#ifndef ANIMALCARACTERISTICA_H
#define ANIMALCARACTERISTICA_H

#include"Animal.h"

class AnimalCaracteristica : public Animal {
public:
	AnimalCaracteristica(std::string);
	~AnimalCaracteristica();
	std::string toString();
	std::string toStringV2();
};

#endif // !ANIMALCARACTERISTICA_H

