#ifndef EVENTO
#define EVENTO 

#include "../Cliente/Escena.h"
#include <map>

class Escena;
class Socket;

class Evento {
protected:
	int tipo;
public:
	std::map<std::string, int> atributos;
	virtual void enviarPorSocket(Socket& s) = 0;
	virtual void actualizarEscena(Escena& escena) = 0;
	virtual ~Evento() {}
};

class EventoIniciarPartida : public Evento {
public:
	EventoIniciarPartida();
	EventoIniciarPartida(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena) {}
	virtual ~EventoIniciarPartida() {}	
};

class EventoCreacionPersonaje : public Evento {
public:
	EventoCreacionPersonaje(int idPersonaje);
	EventoCreacionPersonaje(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena);
	virtual ~EventoCreacionPersonaje() {}
};

//TODO: cambiar a direccion
class EventoPortalAzul : public Evento {
public:
	EventoPortalAzul(int x, int y);
	EventoPortalAzul(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena) {}
	virtual ~EventoPortalAzul() {}
};
//TODO: cambiar a direccion
class EventoPortalNaranja : public Evento {
public:
	EventoPortalNaranja(int x, int y);
	EventoPortalNaranja(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena) {}
	virtual ~EventoPortalNaranja() {}
};

class EventoCrearItem : public Evento {
public:
	EventoCrearItem(int idItem, int x, int y, int angulo);
	EventoCrearItem(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena);
	virtual ~EventoCrearItem() {}
};

class EventoResetPortales : public Evento {
public:
	EventoResetPortales(int idLanzador);
	EventoResetPortales(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena) {}
	virtual ~EventoResetPortales() {}
};

class EventoDejarDeMoverse : public Evento {
public:
	EventoDejarDeMoverse(int idLanzador);
	EventoDejarDeMoverse(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena) {}
	virtual ~EventoDejarDeMoverse() {}
};

class EventoMover : public Evento {
public:
	EventoMover(int x, int y, int idLanzador);
	EventoMover(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena);
	virtual ~EventoMover() {}
};

class EventoCorrer : public Evento {
public:
	EventoCorrer(int direccion, int idLanzador);
	EventoCorrer(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena) {}
	virtual ~EventoCorrer() {}
};

class EventoPinTool : public Evento {
public:
	EventoPinTool(int x, int y);
	EventoPinTool(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena) {}
	virtual ~EventoPinTool() {}
};

class EventoSuicidio : public Evento {
public:
	EventoSuicidio(int idLanzador);
	EventoSuicidio(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena) {}
	virtual ~EventoSuicidio() {}
};

class EventoSalto : public Evento {
public:
	EventoSalto(int idLanzador);
	EventoSalto(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena) {}
	virtual ~EventoSalto() {}
};

class EventoFlip : public Evento {
public:
	EventoFlip(int flip, int idItem);
	EventoFlip(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena);
	virtual ~EventoFlip() {}
};

class EventoCambioEstado : public Evento {
public:
	EventoCambioEstado(int estado, int idItem);
	EventoCambioEstado(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena);
	virtual ~EventoCambioEstado() {}
};

class EventoEliminarItem : public Evento {
public:
	EventoEliminarItem(int idItem);
	EventoEliminarItem(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena);	
	virtual ~EventoEliminarItem() {}
};

class EventoRotacion : public Evento {
public:
	EventoRotacion(int angulo, int idItem);
	EventoRotacion(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizarEscena(Escena& escena);	
	virtual ~EventoRotacion() {}
};

#endif