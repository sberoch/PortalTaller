#ifndef ENVIADOR_EVENTOS
#define ENVIADOR_EVENTOS 

#include "../Common/Thread.h"

class EnviadorEventos : public Thread {
private:
	//Cola cola
	//Socket socket
	bool termino;
public:
	EnviadorEventos();
	virtual void ejecutar();
	void detener();
	~EnviadorEventos();	
};

#endif