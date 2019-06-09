#include "Menu.h"
#include <iostream>

int main(int argc, char** argv) {

	try {
		Menu menu(1000, 800);
		menu.ejecutar();
	} catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
