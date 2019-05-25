#ifndef ESCENA
#define ESCENA

#include <SDL2/SDL.h>
#include "SdlWindow.h"
#include "Terreno.h"

class Escena {
private:
	SdlWindow window;
	bool fullscreen;

	Terreno terreno;
	int deltaCamaraX, deltaCamaraY;
	//Lista/Mapa de objetos moviles, identificados por id

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