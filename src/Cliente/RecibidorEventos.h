#ifndef RECIBIR_EVENTOS
#define RECIBIR_EVENTOS 

#include "../Common/Thread.h"

class RecibidorEventos : public Thread {
private:
	//Cola cola
	//Socket socket
public:
	RecibidorEventos();
	virtual void ejecutar();
	~RecibidorEventos();	
};

#endif