#ifndef ESCENA_JUEGO_H
#define ESCENA_JUEGO_H

#include "EscenaBase.h"
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

class EscenaJuego : public EscenaBase {
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
	EscenaJuego(SdlWindow& window, ColaBloqueante<Evento*>& colaEnviar, 
		Cola<Evento*>& colaRecibir);
	virtual bool termino() override;
	virtual void actualizar() override;
	virtual void dibujar() override;
	virtual int manejarEventos() override;
	virtual ~EscenaJuego();

	virtual void manejar(Evento& evento) override;
	virtual void manejar(EventoCrearItem& evento) override;
	virtual void manejar(EventoMover& evento) override;
	virtual void manejar(EventoFlip& evento) override;
	virtual void manejar(EventoCambioEstado& evento) override;
	virtual void manejar(EventoEliminarItem& evento) override;
	virtual void manejar(EventoRotacion& evento) override;
	virtual void manejar(EventoCreacionPersonaje& evento) override;
private:
	void crearTerreno();
	void recibirMiIdentificador();
	void actualizarFondo();
};

#endif