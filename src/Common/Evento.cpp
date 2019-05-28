#include "Evento.h"

Evento::Evento(int x, int y, int tipoEvento, int idItem) : 
	x(x), y(y), tipoEvento(tipoEvento), idItem(idItem) {}

void Evento::enviarMediante(Socket& socket) {

}

void Evento::recibirMediante(Socket& socket) {

}

