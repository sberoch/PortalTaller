#ifndef ESCENA
#define ESCENA

#include <SDL2/SDL.h>
#include "SdlWindow.h"

class Escena {
private:
	SdlWindow window;
	bool fullscreen;

	//ColaEnviar colaEnviar;  (bloqueante)
	//ColaRecibir colaRecibir;  (no bloqueante)

	SDL_Event event;
	bool terminado;
	bool ctrl;
public:
	Escena(int width, int heigth);
	bool termino();
	void recibirCambios();
	void actualizar();
	void manejarEventos();
	~Escena();
	
};

#endif