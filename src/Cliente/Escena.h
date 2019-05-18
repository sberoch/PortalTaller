#ifndef ESCENA
#define ESCENA

#include "SdlWindow.h"

class Escena {
private:
	SdlWindow window;
public:
	Escena(int width, int heigth);
	void recibirCambios();
	void actualizar();
	void enviarCambios();
	~Escena();
	
};

#endif