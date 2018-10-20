#ifndef ARBOL_H
#define ARBOL_H
#include<string>
#include<iostream>
#include<fstream>
#include"AnimalCaracteristica.h"
#include"AnimalConcreto.h"

struct Nodo {
	Animal* info;
	Nodo* left;
	Nodo* right;
};

class Arbol {
public:
	Arbol();
	~Arbol();
	void preOrden();
	void crearArbol(std::ifstream&);
private:
	Nodo* root;
	void destruirArbol(Nodo*);
	void recorridoPreOrden(Nodo*);
	Nodo* cargarArbolArchivo(std::ifstream&);
};

#endif
