#include "RecibidorEventos.h"

RecibidorEventos::RecibidorEventos(Cola<Evento> cola) :
	cola(cola) {
	//Iniciar socket y eso
}

void RecibidorEventos::ejecutar() {
	while(!termino) {
		//Evento evento;
		//socket >> evento;
		//cola.push(evento);
	}	
}

void RecibidorEventos::detener() {
	termino = true;
	Thread::cerrar();
}

RecibidorEventos::~RecibidorEventos() {
	//Socket
}