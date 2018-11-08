#include "Arbol.h"

Arbol::Arbol() : root(nullptr) {}

Arbol::~Arbol() { destruirArbol(root); }

void Arbol::preOrden() { recorridoPreOrden(root); }

void Arbol::crearArbol(std::ifstream& archivo) { root = cargarArbolArchivo(archivo); }

void Arbol::juego() { root = recorridoJuego(root); }

void Arbol::bajarCaracteristica(int alto, int bajo) { root = recorridoCaracteristica(root, alto, bajo - alto); }

void Arbol::mostrarEspeciales() { recorridoIzquierda(root); }

void Arbol::save()
{
	std::fstream file;
	std::string ruta = "animales.txt";
	file.open(ruta.c_str(), std::ios::out);
	this->save(file, root);
	file.close();
}

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

Nodo* Arbol::nuevaCaracteristica(Nodo* animalIzq, std::string caracteristica , std::string animalDer) {
	// Declarar y crear la nueva caracteristica
	Nodo* nuevaCaracteristica = new Nodo; 
	// Declarar y crear el nuevo animal
	Nodo* nuevoAnimal = new Nodo;

	// Establecer los atributos del animal
	nuevoAnimal->info = new AnimalConcreto(animalDer);
	nuevoAnimal->left = nullptr;
	nuevoAnimal->right = nullptr;

	// Establecer los atributos de la caracteristica
	nuevaCaracteristica->info = new AnimalCaracteristica(caracteristica);
	nuevaCaracteristica->left = animalIzq;
	nuevaCaracteristica->right = nuevoAnimal;

	return nuevaCaracteristica;
}

Nodo * Arbol::recorridoJuego(Nodo* actual) {

	Animal* animal = actual->info;
	std::string tipo = typeid(*animal).name();
	char e;

	std::cout << animal->toString() << std::endl;
	std::cout << "RESPUESTA [S/N]: ";
	std::cin >> e;
	actual->respuesta = e;
	std::cin.clear();
	std::cin.ignore(255, '\n');
	if ((actual->respuesta != 'N') && (actual->respuesta != 'S')) { throw Exception(" Debe de digitar S o N"); return nullptr; }
	else if (e == 'S' && tipo == "class AnimalConcreto") 
		return actual;
	else if (e == 'N' && tipo == "class AnimalConcreto") {
		std::string animalt = preguntarAnimal(std::cin);
		std::string caracteristica = preguntarCaracteristica(std::cin);
		return nuevaCaracteristica(actual, caracteristica, animalt);
	}
	else if (e == 'N')
		actual->left = recorridoJuego(actual->left);
	else 
		actual->right = recorridoJuego(actual->right);
	
	return actual;
}

std::string Arbol::preguntarAnimal(std::istream& entrada) {
	std::string expresion;
	std::cout << "Digite el nombre del nuevo animal: ";

	if (entrada) {
		expresion.clear();
		getline(entrada, expresion);
		entrada.clear();
	}
	return expresion;
}

std::string Arbol::preguntarCaracteristica(std::istream& entrada) {
	std::string expresion;
	std::cout << "Digite una caracteristica del animal: ";

	if (entrada) {
		expresion.clear();
		getline(entrada, expresion);
		entrada.clear();
	}
	return expresion;
}

Nodo * Arbol::buscarNIzquierda(Nodo* actual, int nivel) {
	if (!actual || nivel == 1)
		return actual;
	else
		return buscarNIzquierda(actual->left, nivel - 1);
}

Nodo * Arbol::recorridoCaracteristica(Nodo* actual, int alto, int bajo) {
	if (!actual)
		actual = nullptr;
	else if (alto == 1) {
		Nodo* posicionar = buscarNIzquierda(actual->left, bajo); // busco desde el nivel del elemento que hay que bajar, hasta el nivel que quiere bajar
		Nodo* bajar = actual; // respaldar al que hay que bajar
		actual = actual->left; // subir el sub-arbol que se encuentra a la izquierda,
		bajar->left = posicionar->left; // colocar al que hay que bajar
		posicionar->left = bajar; // subir 
	}
	else
		actual->left = recorridoCaracteristica(actual->left, alto - 1, bajo);

	return actual;	
}

void Arbol::save(std::fstream & file, Nodo * actual)
{
	if (!actual) {
		file << "$\n";
		return;
	}
	file << actual->info->toStringV2();

	save(file, actual->left);
	save(file, actual->right);

}

// Recorre el sub-arbol izquierdo de la raiz con el fin
// de imprimir todas las caracteristicas especiales
void Arbol::recorridoIzquierda(Nodo* actual , int i) {
	if (actual->left) { // si tiene izquierda es porque no he llegado al final, el final de la izquierda es un animal
		std::cout << i << "->" << actual->info->getDato() << std::endl;
		recorridoIzquierda(actual->left, i + 1);
	}
}




