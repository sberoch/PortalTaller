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
class EventoPortalAzul;
class EventoPortalNaranja;
class EventoResetPortales;
class EventoDejarDeMoverse;
class EventoCorrer;
class EventoPinTool;
class EventoArriba;
class EventoFlipPersonaje;
class EventoCambioEstado;

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
	Escena(int width, int heigth, 
		ColaBloqueante<Evento*>& colaEnviar, 
		Cola<Evento*>& colaRecibir);
	bool termino();
	void recibirCambios();
	void actualizar();
	void manejarEventos();

	void actualizarCon(EventoPortalAzul& evento);
	void actualizarCon(EventoPortalNaranja& evento);
	void actualizarCon(EventoResetPortales& evento);
	void actualizarCon(EventoDejarDeMoverse& evento);
	void actualizarCon(EventoCorrer& evento);
	void actualizarCon(EventoPinTool& evento);
	void actualizarCon(EventoArriba& evento);
	void actualizarCon(EventoFlipPersonaje& evento);
	void actualizarCon(EventoCambioEstado& evento);
	~Escena();

private:
	void crearTerreno();
};

#endif