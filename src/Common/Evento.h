#ifndef EVENTO
#define EVENTO 

#include "Socket.h"
#include "../Cliente/Escena.h"

class Evento {
public:
	int x,y;
	int tipoEvento;
	int idItem;
	Evento() = default;
	virtual void actualizarEscena(Escena& escena) = 0;
};

#endif