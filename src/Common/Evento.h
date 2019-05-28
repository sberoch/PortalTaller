#ifndef EVENTO
#define EVENTO 

#include "Socket.h"

class Evento {
private:
	int x,y;
	int tipoEvento;
	int idItem;
public:
	Evento() = default;
	Evento(int x, int y, int tipoEvento, int idItem);
	void enviarMediante(Socket& socket);
	void recibirMediante(Socket& socket);
};

#endif