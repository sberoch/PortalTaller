#ifndef _THREAD_
#define _THREAD_

#include <thread>

class Thread {
private:
	std::thread thread;

public:
	Thread();

	Thread(Thread&& origen); 

	Thread& operator=(Thread&& origen); 

	Thread(const Thread&) = delete;

	Thread& operator=(const Thread&) = delete;

	//Inicia la ejecucion en un thread nuevo
	void iniciar();

	//Hace un join del thread
	virtual void cerrar();

	//Ejecucion del thread a ser implementada por quien herede esta clase
	virtual void ejecutar() = 0;

	virtual ~Thread();
};

#endif 
