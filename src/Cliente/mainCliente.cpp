#include <iostream>
#include "Escena.h"

int main(int argc, char** argv) {
	Escena escena(1000,800);
	escena.recibirCambios();
	escena.actualizar();
	escena.enviarCambios();
}
