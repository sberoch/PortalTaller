#include "RecibidorEventos.h"

#include <iostream>

RecibidorEventos::RecibidorEventos(Cola<Evento*>& cola, Socket& socket) :
	cola(cola), socket(socket) {
	termino = false;
	}

void RecibidorEventos::ejecutar() {
	while(!termino) {
		Evento* evento = serializador.recibirEvento(socket);
		cola.put(evento);
	}
}

void RecibidorEventos::detener() {
	termino = true;
	socket.shutdown();
	Thread::cerrar();
}