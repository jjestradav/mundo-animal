#include "Animal.h"

Animal::Animal(std::string _dato) : dato(_dato) { }

Animal::~Animal() { }

std::string Animal::getDato() {
	return dato;
}
