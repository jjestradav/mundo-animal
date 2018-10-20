#include "Arbol.h"

Arbol::Arbol() : root(nullptr) {}

Arbol::~Arbol() { destruirArbol(root); }

void Arbol::preOrden() { recorridoPreOrden(root); }

void Arbol::crearArbol(std::ifstream& archivo) { root = cargarArbolArchivo(archivo); }

void Arbol::destruirArbol(Nodo* actual){
	if (actual) {
		destruirArbol(actual->left);
		destruirArbol(actual->right);
		delete actual;
	}
}

void Arbol::recorridoPreOrden(Nodo* actual) { 
	if (actual) {
		std::cout << actual->info->toString() << std::endl;
		std::cout << " ";
		recorridoPreOrden(actual->left);
		recorridoPreOrden(actual->right);
	}
}

Nodo* Arbol::cargarArbolArchivo(std::ifstream& archivo) {
	std::string palabraArchivo;
	Nodo* tmp;
	std::getline(archivo, palabraArchivo, '\n');
	if (palabraArchivo == "$")
		return nullptr;
	tmp = new Nodo;
	if (palabraArchivo[0] == '1') 
		tmp->info = new AnimalCaracteristica(palabraArchivo.substr(1, palabraArchivo.length())); // caracteristica
	else
		tmp->info = new AnimalConcreto(palabraArchivo.substr(1, palabraArchivo.length())); // animal
	tmp->left = cargarArbolArchivo(archivo);
	tmp->right = cargarArbolArchivo(archivo);
	return tmp;
}
