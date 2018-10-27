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
	char respuesta;
};

class Arbol {
public:
	Arbol();
	~Arbol();
	void preOrden();
	void crearArbol(std::ifstream&);
	void juego();
	void bajarCaracteristica(int, int);
private:
	Nodo* root;
	void destruirArbol(Nodo*);
	void recorridoPreOrden(Nodo*);
	Nodo* cargarArbolArchivo(std::ifstream&);
	Nodo* nuevaCaracteristica(Nodo*, std::string, std::string);
	Nodo* recorridoJuego(Nodo*);
	std::string preguntarAnimal(std::istream&);
	std::string preguntarCaracteristica(std::istream&);
	Nodo* buscarNIzquierda(Nodo*, int);
	Nodo* recorridoCaracteristica(Nodo*, int, int);
};

#endif
