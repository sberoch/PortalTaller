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
class EventoCrearPartida;
class EventoUnirseAPartida;
class EventoActualizacionSala;

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

	virtual void manejar(EventoCrearPartida& evento) {}
	virtual void manejar(EventoUnirseAPartida& evento) {}
	virtual void manejar(EventoActualizacionSala& evento) {}
};

#endif
