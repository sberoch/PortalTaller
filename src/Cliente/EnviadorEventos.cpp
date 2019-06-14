#include "EnviadorEventos.h"
#include <iostream>

EnviadorEventos::EnviadorEventos(ColaBloqueante<Evento*>& cola, Socket& socket) :
	cola(cola), socket(socket) {
	termino = false;
}

void EnviadorEventos::ejecutar() {
	while(!termino) {
		Evento* evento;
		cola.get(evento);
		evento->enviarPorSocket(socket);
		delete evento;
	}
}

void EnviadorEventos::detener() {
	socket.shutdown();
	termino = true;
}