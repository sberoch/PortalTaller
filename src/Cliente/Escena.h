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

//FD
class Evento;
class EventoCrearItem;
class EventoMover;
class EventoFlip;
class EventoCambioEstado;
class EventoEliminarItem;
class EventoRotacion;

class Escena {
private:
	Audio audio;
	SdlWindow window;
	bool fullscreen;

	CreadorTexturas creadorTexturas;
	std::map<int, VistaObjeto*> objetosDelJuego;

	ColaBloqueante<Evento*>& colaEnviar;
	Cola<Evento*>& colaRecibir;  

	SDL_Event event;
	bool terminado;
	bool ctrl;
	int deltaCamaraX, deltaCamaraY;
	
public:
	Escena(SdlWindow& window, ColaBloqueante<Evento*>& colaEnviar, 
		Cola<Evento*>& colaRecibir);
	bool termino();
	void recibirCambios();
	void actualizar();
	void manejarEventos();

	void actualizarCon(EventoCrearItem& evento);
	void actualizarCon(EventoMover& evento);
	void actualizarCon(EventoFlip& evento);
	void actualizarCon(EventoCambioEstado& evento);
	void actualizarCon(EventoEliminarItem& evento);
	void actualizarCon(EventoRotacion& evento);
	~Escena();

private:
	void crearTerreno();
};

#endif