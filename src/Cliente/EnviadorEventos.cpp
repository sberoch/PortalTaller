#include "EnviadorEventos.h"

EnviadorEventos::EnviadorEventos(ColaBloqueante<Evento*>& cola) :
	cola(cola) {
	termino = false;
	socket.conectar("localhost", "8888");
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
	Thread::cerrar();
}