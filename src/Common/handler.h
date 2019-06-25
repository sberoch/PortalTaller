#ifndef __HANDLER_H__
#define __HANDLER_H__

// Forward declaration
class Evento;
class EventoCrearItem;
class EventoMover;
class EventoFlip;
class EventoCambioEstado;
class EventoEliminarItem;
class EventoRotacion;

class EventoCreacionPersonaje;
class EventoIniciarPartida;
class EventoCrearPartida;
class EventoUnirseAPartida;
class EventoSeleccionarPartida;
class EventoActualizacionSala;
class EventoIngresarASala;
class EventoFinDelJuego;
class EventoJugadorDesconectado;

class EventoPortalAzul;
class EventoPortalNaranja;
class EventoDejarDeMoverse;
class EventoResetPortales;
class EventoSuicidio;
class EventoSalto;
class EventoCorrer;
class EventoPinTool;

class Handler {
    public:
    virtual void manejar(Evento& evento) = 0;
    virtual void manejar(EventoCrearItem& evento) {}
	virtual void manejar(EventoMover& evento) {}
	virtual void manejar(EventoFlip& evento) {}
	virtual void manejar(EventoCambioEstado& evento) {}
	virtual void manejar(EventoEliminarItem& evento) {}
	virtual void manejar(EventoRotacion& evento) {}
	virtual void manejar(EventoCreacionPersonaje& evento) {}

	virtual void manejar(EventoIniciarPartida& evento) {}
	virtual void manejar(EventoCrearPartida& evento) {}
	virtual void manejar(EventoUnirseAPartida& evento) {}
	virtual void manejar(EventoSeleccionarPartida& evento) {}
	virtual void manejar(EventoActualizacionSala& evento) {}
	virtual void manejar(EventoIngresarASala& evento) {}
	virtual void manejar(EventoFinDelJuego& evento) {}
	virtual void manejar(EventoJugadorDesconectado& evento) {}

	virtual void manejar(EventoPortalAzul& evento) {}
	virtual void manejar(EventoPortalNaranja& evento) {}
	virtual void manejar(EventoResetPortales& evento) {}
	virtual void manejar(EventoDejarDeMoverse& evento) {}
	virtual void manejar(EventoSalto& evento) {}
	virtual void manejar(EventoSuicidio& evento) {}
	virtual void manejar(EventoCorrer& evento) {}
	virtual void manejar(EventoPinTool& evento) {}
};

#endif
