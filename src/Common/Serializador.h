#ifndef SERIALIZADOR_H
#define SERIALIZADOR_H

#include "Socket.h"
#include "Evento.h"

class Serializador {
public:
	Evento* recibirEvento(Socket& socket);
};

#endif // SERIALIZADOR_H

