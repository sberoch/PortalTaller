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
	virtual void enviarPorSocket(Socket& s) = 0;
};

class EventoCreacionPersonaje : public Evento {
public:
	EventoCreacionPersonaje(int idPersonaje);
	EventoCreacionPersonaje(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena);
};

//TODO: cambiar a direccion
class EventoPortalAzul : public Evento {
public:
	EventoPortalAzul(int x, int y);
	EventoPortalAzul(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena) {}
};
//TODO: cambiar a direccion
class EventoPortalNaranja : public Evento {
public:
	EventoPortalNaranja(int x, int y);
	EventoPortalNaranja(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena) {}
};

class EventoCrearItem : public Evento {
public:
	EventoCrearItem(int idItem, int x, int y, int angulo);
	EventoCrearItem(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena);
};

class EventoResetPortales : public Evento {
public:
	EventoResetPortales(int idLanzador);
	EventoResetPortales(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena) {}
};

class EventoDejarDeMoverse : public Evento {
public:
	EventoDejarDeMoverse(int idLanzador);
	EventoDejarDeMoverse(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena) {}
};

class EventoMover : public Evento {
public:
	EventoMover(int x, int y, int idLanzador);
	EventoMover(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena);
};

class EventoCorrer : public Evento {
public:
	EventoCorrer(int direccion, int idLanzador);
	EventoCorrer(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena) {}
};

class EventoPinTool : public Evento {
public:
	EventoPinTool(int x, int y);
	EventoPinTool(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena) {}
};

class EventoSalto : public Evento {
public:
	EventoSalto(int idLanzador);
	EventoSalto(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena) {}
};

class EventoFlip : public Evento {
public:
	EventoFlip(int flip, int idItem);
	EventoFlip(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena);
};

class EventoCambioEstado : public Evento {
public:
	EventoCambioEstado(int estado, int idItem);
	EventoCambioEstado(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena);
};

class EventoEliminarItem : public Evento {
public:
	EventoEliminarItem(int idItem);
	EventoEliminarItem(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena);	
};

class EventoRotacion : public Evento {
public:
	EventoRotacion(int angulo, int idItem);
	EventoRotacion(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena);	
};

#endif