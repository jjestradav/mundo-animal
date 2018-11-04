#include "AnimalCaracteristica.h"

AnimalCaracteristica::AnimalCaracteristica(std::string dato) : Animal(dato) { }

AnimalCaracteristica::~AnimalCaracteristica() { }

std::string AnimalCaracteristica::toString() {
	return "El animal " + dato + "?";
}

std::string AnimalCaracteristica::toStringV2()
{
	return "1" + dato + "\n";
}
