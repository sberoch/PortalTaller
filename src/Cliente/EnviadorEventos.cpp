#include "EnviadorEventos.h"

EnviadorEventos::EnviadorEventos(ColaBloqueante<Evento>& cola) :
	cola(cola) {
	//Iniciar socket y eso
}

void EnviadorEventos::ejecutar() {
	while(!termino) {
		//Evento evento;
		//cola.get(evento);
		//socket << evento;
	}
}

void EnviadorEventos::detener() {
	termino = true;
	Thread::cerrar();
}

EnviadorEventos::~EnviadorEventos() {
	//Socket shutdown
}