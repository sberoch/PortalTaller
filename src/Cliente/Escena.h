#ifndef ESCENA
#define ESCENA

#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "VistaFondo.h"
#include "CreadorTexturas.h"
#include "../Common/Cola.h"
#include "../Common/cola_bloqueante.h"
#include "../Common/Evento.h"
#include "Audio.h"
#include "../Common/Conversor.h"
#include "InputHandler.h"

typedef std::shared_ptr<VistaObjeto> VistaObjetoPtr;

//FD
class Evento;
class EventoCrearItem;
class EventoMover;
class EventoFlip;
class EventoCambioEstado;
class EventoEliminarItem;
class EventoRotacion;
class EventoCreacionPersonaje;

class Escena {
private:
	Audio audio;
	SdlWindow window;

	Conversor conv;
	CreadorTexturas creadorTexturas;
	std::map<int, VistaObjetoPtr> objetosDelJuego;
	SdlTexture fondoTex;
	VistaFondo fondo;

	ColaBloqueante<Evento*>& colaEnviar;
	Cola<Evento*>& colaRecibir;  

	InputHandler handler;
	bool terminado;

	int miId;
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
	void actualizarCon(EventoCreacionPersonaje& evento);
private:
	void crearTerreno();
	void recibirMiIdentificador();
	void actualizarFondo();
};

#endif