#include "AnimalConcreto.h"

AnimalConcreto::AnimalConcreto(std::string dato) : Animal(dato) { }

AnimalConcreto::~AnimalConcreto() { }

std::string AnimalConcreto::toString() {
	return "El animal en el que estaba pensando es un(a) " + dato;
}
