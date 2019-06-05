#include "RecibidorEventos.h"

#include <iostream>

RecibidorEventos::RecibidorEventos(Cola<Evento*>& cola) :
	cola(cola) {
	termino = false;
	socket.conectar("localhost", "8888");
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