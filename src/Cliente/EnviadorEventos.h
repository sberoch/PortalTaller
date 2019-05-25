#ifndef ENVIADOR_EVENTOS
#define ENVIADOR_EVENTOS 

#include "../Common/Thread.h"

class EnviadorEventos : public Thread {
private:
	//Cola cola
	//Socket socket
public:
	EnviadorEventos();
	virtual void ejecutar();
	~EnviadorEventos();	
};

#endif