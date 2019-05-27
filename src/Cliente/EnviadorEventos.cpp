#include "EnviadorEventos.h"

EnviadorEventos::EnviadorEventos() {
	//Iniciar socket y eso
}

void EnviadorEventos::ejecutar() {
	//while(!termino) {
		//Evento evento = cola.pop();
		//socket << evento;
	//}	
}

void EnviadorEventos::detener() {
	termino = true;
	Thread::cerrar();
}

EnviadorEventos::~EnviadorEventos() {
	//Socket shutdown
}