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
		std::cout << actual->palabra;
		std::cout << " ";
		recorridoPreOrden(actual->left);
		recorridoPreOrden(actual->right);
	}
}

Nodo* Arbol::cargarArbolArchivo(std::ifstream& archivo) {
	std::string palabraArchivo;
	Nodo* tmp;
	archivo >> palabraArchivo;
	if (palabraArchivo == "$")
		return nullptr;
	tmp = new Nodo;
	tmp->palabra = palabraArchivo;
	tmp->left = cargarArbolArchivo(archivo);
	tmp->right = cargarArbolArchivo(archivo);
	return tmp;
}
