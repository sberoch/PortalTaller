#ifndef EVENTO
#define EVENTO 

#include <map>

class Handler;
class Socket;

class Evento {
protected:
	int tipo;
public:
	std::map<std::string, int> atributos;
	virtual void enviarPorSocket(Socket& s) = 0;
	virtual void actualizar(Handler& handler) = 0;
	virtual ~Evento() {}
};

class EventoIniciarPartida : public Evento {
public:
	EventoIniciarPartida();
	EventoIniciarPartida(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizar(Handler& handler) override {}
	virtual ~EventoIniciarPartida() {}	
};

class EventoCreacionPersonaje : public Evento {
public:
	EventoCreacionPersonaje(int idPersonaje);
	EventoCreacionPersonaje(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizar(Handler& handler) override;
	virtual ~EventoCreacionPersonaje() {}
};

//TODO: cambiar a direccion
class EventoPortalAzul : public Evento {
public:
	EventoPortalAzul(int x, int y);
	EventoPortalAzul(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizar(Handler& handler) override {}
	virtual ~EventoPortalAzul() {}
};
//TODO: cambiar a direccion
class EventoPortalNaranja : public Evento {
public:
	EventoPortalNaranja(int x, int y);
	EventoPortalNaranja(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizar(Handler& handler) override {}
	virtual ~EventoPortalNaranja() {}
};

class EventoCrearItem : public Evento {
public:
	EventoCrearItem(int idItem, int x, int y, int angulo);
	EventoCrearItem(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizar(Handler& handler) override;
	virtual ~EventoCrearItem() {}
};

class EventoResetPortales : public Evento {
public:
	EventoResetPortales(int idLanzador);
	EventoResetPortales(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizar(Handler& handler) override {}
	virtual ~EventoResetPortales() {}
};

class EventoDejarDeMoverse : public Evento {
public:
	EventoDejarDeMoverse(int idLanzador);
	EventoDejarDeMoverse(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizar(Handler& handler) override {}
	virtual ~EventoDejarDeMoverse() {}
};

class EventoMover : public Evento {
public:
	EventoMover(int x, int y, int idLanzador);
	EventoMover(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizar(Handler& handler) override;
	virtual ~EventoMover() {}
};

class EventoCorrer : public Evento {
public:
	EventoCorrer(int direccion, int idLanzador);
	EventoCorrer(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizar(Handler& handler) override {}
	virtual ~EventoCorrer() {}
};

class EventoPinTool : public Evento {
public:
	EventoPinTool(int x, int y);
	EventoPinTool(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizar(Handler& handler) override {}
	virtual ~EventoPinTool() {}
};

class EventoSuicidio : public Evento {
public:
	EventoSuicidio(int idLanzador);
	EventoSuicidio(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizar(Handler& handler) override {}
	virtual ~EventoSuicidio() {}
};

class EventoSalto : public Evento {
public:
	EventoSalto(int idLanzador);
	EventoSalto(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizar(Handler& handler) override {}
	virtual ~EventoSalto() {}
};

class EventoFlip : public Evento {
public:
	EventoFlip(int flip, int idItem);
	EventoFlip(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizar(Handler& handler) override;
	virtual ~EventoFlip() {}
};

class EventoCambioEstado : public Evento {
public:
	EventoCambioEstado(int estado, int idItem);
	EventoCambioEstado(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizar(Handler& handler) override;
	virtual ~EventoCambioEstado() {}
};

class EventoEliminarItem : public Evento {
public:
	EventoEliminarItem(int idItem);
	EventoEliminarItem(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizar(Handler& handler) override;	
	virtual ~EventoEliminarItem() {}
};

class EventoRotacion : public Evento {
public:
	EventoRotacion(int angulo, int idItem);
	EventoRotacion(Socket& s);
	virtual void enviarPorSocket(Socket& s);
	virtual void actualizar(Handler& handler) override;	
	virtual ~EventoRotacion() {}
};

#endif