#ifndef EVENTO
#define EVENTO 

#include "../Cliente/Escena.h"
#include "Socket.h"
#include <map>

class Escena;

class Evento {
protected:
	int tipo;
public:
	std::map<std::string, int> atributos;
	virtual void actualizarEscena(Escena& escena) = 0;
	virtual void enviarPorSocket(Socket& s);
};

class EventoPortalAzul : public Evento {
public:
	EventoPortalAzul(int x, int y);
	EventoPortalAzul(Socket& s);
	virtual void actualizarEscena(Escena& escena);
};

class EventoPortalNaranja : public Evento {
public:
	EventoPortalNaranja(int x, int y);
	EventoPortalNaranja(Socket& s);
	virtual void actualizarEscena(Escena& escena);
};

class EventoResetPortales : public Evento {
public:
	EventoResetPortales() = default;
};

class EventoDejarDeMoverse : public Evento {
public:
	EventoDejarDeMoverse() = default;
};

class EventoMover : public Evento {
public:
	EventoMover(int idLanzador);
	virtual void actualizarEscena(Escena& escena);
};

class EventoCorrer : public Evento {
public:
	EventoCorrer(int x, int y);
};

class EventoPinTool : public Evento {
public:
	EventoPinTool(int x, int y);
	EventoPinTool(Socket& s);
	virtual void actualizarEscena(Escena& escena);
};

class EventoSalto : public Evento {
public:
	EventoSalto() = default;
};

class EventoFlip : public Evento {
public:
	EventoFlip(int flip, int idLanzador);
	virtual void actualizarEscena(Escena& escena);
};

class EventoCambioEstado : public Evento {
public:
	EventoCambioEstado(int estado, int idLanzador);
	virtual void actualizarEscena(Escena& escena);
};

class EventoEliminarItem : public Evento {
public:
	EventoEliminarItem(int idItem);
	virtual void actualizarEscena(Escena& escena);	
};

class EventoRotacion : public Evento {
public:
	EventoRotacion(int angulo, int idItem);
	virtual void actualizarEscena(Escena& escena);	
};
#endif