#include <iostream>
#include "Escena.h"

int main(int argc, char** argv) {
	Escena escena(1000,800);

//	Tirar hilo recibir
//	Tirar hilo enviar
//	Crear mapa desde yaml
 
	while(!escena.termino()) {
		escena.recibirCambios();
		escena.actualizar();	
		escena.manejarEventos();   
	}
}
