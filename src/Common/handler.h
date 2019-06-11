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

class Handler {
    public:
    virtual void actualizarCon(Evento& evento) = 0;
    virtual void actualizarCon(EventoCrearItem& evento) {}
	virtual void actualizarCon(EventoMover& evento) {}
	virtual void actualizarCon(EventoFlip& evento) {}
	virtual void actualizarCon(EventoCambioEstado& evento) {}
	virtual void actualizarCon(EventoEliminarItem& evento) {}
	virtual void actualizarCon(EventoRotacion& evento) {}
	virtual void actualizarCon(EventoCreacionPersonaje& evento) {}
};

#endif
