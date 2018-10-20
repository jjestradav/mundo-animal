#ifndef ANIMALCARACTERISTICA_H
#define ANIMALCARACTERISTICA_H

#include"Animal.h"

class AnimalCaracteristica : public Animal {
public:
	AnimalCaracteristica(std::string);
	~AnimalCaracteristica();
	std::string toString();
};

#endif // !ANIMALCARACTERISTICA_H

