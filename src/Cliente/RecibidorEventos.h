#ifndef RECIBIR_EVENTOS
#define RECIBIR_EVENTOS 

#include "../Common/Thread.h"
#include "../Common/Cola.h"
#include "../Common/Evento.h"
#include "../Common/Serializador.h"
#include "../Common/Socket.h"

class RecibidorEventos : public Thread {
private:
	bool termino;
	Cola<Evento*>& cola;
	Serializador serializador;
	Socket& socket;
public:
	RecibidorEventos(Cola<Evento*>& cola, Socket& socket);
	virtual void ejecutar();
	void detener();
};

#endif