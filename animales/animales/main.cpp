#include"Arbol.h"

int main() {
	int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	flag |= _CRTDBG_LEAK_CHECK_DF;
	_CrtSetDbgFlag(flag);
	std::ifstream archivo("animales.txt", std::ios::in);
	if (!archivo) {
		std::cout << "Error al encontrar el archivo" << std::endl;
		system("pause");
		return -1;
	}
	Arbol a;
	a.crearArbol(archivo);
	archivo.close();
	int op,nivel1,nivel2;
	char continuar = 'S';
	do {
		std::cout << " BIenvenido al Mundo de los animales " << std::endl;
		std::cout << "===============Menu====================" << std::endl;
		std::cout << " 1-____________Jugar___________________" << std::endl;
		std::cout << " 2- __Bajar nivel de caracteristicas___" << std::endl;
		std::cout << " 3- __________Salir____________________" << std::endl;
		std::cout << " ________Digite un opcion______________" << std::endl;
		std::cin >> op;
		switch (op) {
		case 1: do {
			try {
				a.juego();
				std::cout << " Desea continuar" << std::endl;
				std::cout << " Digite S para SI" << std::endl;
				std::cin >> continuar;
				if (continuar != 'S'&&continuar != 'N') { throw Exception("Debe de digitar S o N"); }
			}
			catch (Exception e) {
				std::cout << e.toString() << std::endl;
				system("pause");
			}
		} while ((continuar == 'S'&& continuar!='N'));
			break;
		case 2: 
			try {
				std::cout << " Bienvenido usted a ingresado a la opcion de intercambiar caracteristicas " << std::endl;
				std::cout << " A continuacion usted vera las caracteristicas principales y podra intercambiarlas" << std::endl;
				a.mostrarEspeciales();
				std::cout << "Digite el numero de nivel" << std::endl;
				std::cin >> nivel1;
				std::cout << "Digite el numero de el otro nivel" << std::endl;
				std::cin >> nivel2;
			
			if (nivel1 == nivel2) {
				throw Exception("No puede ser el mismo nivel"); 
			}else{
				a.bajarCaracteristica(nivel1, nivel2);
			}
			}
			catch (Exception e) {
				std::cout << e.toString() << std::endl;
			}
			system("pause"); 
			break;
		case 3: a.save(); 
			break;
		}
	} while (op != 3);
	
	return 0;
}