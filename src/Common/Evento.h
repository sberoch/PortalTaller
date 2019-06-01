#ifndef EVENTO
#define EVENTO 

#include "../Cliente/Escena.h"

class Escena;

class Evento {
public:
	int x,y;
	int angulo;
	int flip;
	int tipoEvento;
	int estado;
	int idLanzador;
	virtual void actualizarEscena(Escena& escena) = 0;
};

class EventoPortalAzul : public Evento {
public:
	EventoPortalAzul(int x, int y, int angulo);
	virtual void actualizarEscena(Escena& escena);
};

class EventoPortalNaranja : public Evento {
public:
	EventoPortalNaranja(int x, int y, int angulo);
	virtual void actualizarEscena(Escena& escena);
};

class EventoResetPortales : public Evento {
public:
	EventoResetPortales() = default;
	virtual void actualizarEscena(Escena& escena);	
};

class EventoDejarDeMoverse : public Evento {
public:
	EventoDejarDeMoverse() = default;
	virtual void actualizarEscena(Escena& escena);	
};

class EventoCorrer : public Evento {
public:
	EventoCorrer(int x, int y);
	virtual void actualizarEscena(Escena& escena);
};

class EventoPinTool : public Evento {
public:
	EventoPinTool(int x, int y);
	virtual void actualizarEscena(Escena& escena);
};

class EventoArriba : public Evento {
public:
	EventoArriba() = default;
	virtual void actualizarEscena(Escena& escena);
};

class EventoFlipPersonaje : public Evento {
public:
	EventoFlipPersonaje(int flip);
	virtual void actualizarEscena(Escena& escena);
};

class EventoCambioEstado : public Evento {
public:
	EventoCambioEstado(int estado);
	virtual void actualizarEscena(Escena& escena);
};
#endif