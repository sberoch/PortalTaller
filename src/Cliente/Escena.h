#ifndef ESCENA
#define ESCENA

#include <SDL2/SDL.h>
#include <vector>
#include "SdlWindow.h"
#include "CreadorTexturas.h"
#include "../Common/Cola.h"
#include "../Common/Evento.h"

class Escena {
private:
	SdlWindow window;
	bool fullscreen;

	CreadorTexturas creadorTexturas;
	std::vector<VistaObjeto*> objetosDelJuego;
	//Lista/Mapa de objetos moviles, identificados por id

	int deltaCamaraX, deltaCamaraY;

	Cola<Evento>& colaRecibir;  

	SDL_Event event;
	bool terminado;
	bool ctrl;
public:
	Escena(int width, int heigth, Cola<Evento>& colaRecibir);
	bool termino();
	void recibirCambios();
	void actualizar();
	void manejarEventos();
	~Escena();

private:
	void crearTerreno();	
};

#endif