#include <iostream>
#include "Escena.h"

int main(int argc, char** argv) {
	Escena escena(1000,800);

//	Tirar hilo recibir
//	Tirar hilo enviar

//	while(!escena.termino()) {
//		escena.recibirCambios(); <-------- Desencola en ColaRecibir los cambios recibidos por el thread recibir
//		escena.actualizar();	 <-------- Redibuja
//		escena.handleEvents();   <-------- ?
//		escena.enviarCambios();  <-------- Encola en ColaEnviar los cambios realizados, el thread enviar los manda
//	}
}
