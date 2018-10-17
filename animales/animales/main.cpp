#include"Arbol.h"

int main() {
	std::ifstream archivo("animales.txt", std::ios::in);
	if (!archivo) {
		std::cout << "Error al encontrar el archivo" << std::endl;
		system("pause");
		return -1;
	}
	Arbol a;
	a.crearArbol(archivo);
	a.preOrden();
	
	return 0;
}