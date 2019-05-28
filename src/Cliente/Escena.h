#ifndef ESCENA
#define ESCENA

#include <SDL2/SDL.h>
#include <vector>
#include "SdlWindow.h"
#include "CreadorTexturas.h"
#include "../Common/Cola.h"
#include "../Common/cola_bloqueante.h"
#include "../Common/Evento.h"
#include "Audio.h"

class Escena {
private:
	Audio audio;

	SdlWindow window;
	bool fullscreen;

	CreadorTexturas creadorTexturas;
	std::vector<VistaObjeto*> objetosDelJuego;
	//Lista/Mapa de objetos moviles, identificados por id

	ColaBloqueante<Evento>& colaEnviar;
	Cola<Evento>& colaRecibir;  

	SDL_Event event;
	bool terminado;
	bool ctrl;
	int deltaCamaraX, deltaCamaraY;
public:
	Escena(int width, int heigth, ColaBloqueante<Evento>& colaEnviar, Cola<Evento>& colaRecibir);
	bool termino();
	void recibirCambios();
	void actualizar();
	void manejarEventos();
	~Escena();

private:
	void crearTerreno();	
};

#endif