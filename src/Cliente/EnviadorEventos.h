#ifndef ENVIADOR_EVENTOS
#define ENVIADOR_EVENTOS 

#include "../Common/Thread.h"
#include "../Common/cola_bloqueante.h"
#include "../Common/Evento.h"
#include "../Common/Socket.h"

class EnviadorEventos : public Thread {
private:
	ColaBloqueante<Evento*>& cola;
	Socket& socket;
	bool termino;
public:
	EnviadorEventos(ColaBloqueante<Evento*>& cola, Socket& socket);
	virtual void ejecutar();
	void detener();
};

#endif