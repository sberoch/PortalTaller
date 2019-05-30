#ifndef RECIBIR_EVENTOS
#define RECIBIR_EVENTOS 

#include "../Common/Thread.h"
#include "../Common/Cola.h"
#include "../Common/Evento.h"

class RecibidorEventos : public Thread {
private:
	bool termino;
	Cola<Evento*> cola;
	//Socket socket
public:
	RecibidorEventos(Cola<Evento*> cola);
	virtual void ejecutar();
	void detener();
	~RecibidorEventos();	
};

#endif