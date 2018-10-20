#include "AnimalCaracteristica.h"

AnimalCaracteristica::AnimalCaracteristica(std::string dato) : Animal(dato) { }

AnimalCaracteristica::~AnimalCaracteristica() { }

std::string AnimalCaracteristica::toString() {
	return "El animal " + dato + "?";
}
