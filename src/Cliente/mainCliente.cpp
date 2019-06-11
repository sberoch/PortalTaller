#include "SeleccionadorEscena.h"
#include <iostream>

int main(int argc, char** argv) {
	try {
		SeleccionadorEscena seleccionadorEscena(1000, 800);
		seleccionadorEscena.ejecutar();
	} catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
