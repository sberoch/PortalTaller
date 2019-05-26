#ifndef ESCENA
#define ESCENA

#include <SDL2/SDL.h>
#include <vector>
#include "SdlWindow.h"
#include "CreadorTexturas.h"

class Escena {
private:
	SdlWindow window;
	bool fullscreen;

	CreadorTexturas creadorTexturas;
	std::vector<VistaObjeto*> objetosDelJuego;
	//Lista/Mapa de objetos moviles, identificados por id

	int deltaCamaraX, deltaCamaraY;

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

private:
	void crearTerreno();	
};

#endif