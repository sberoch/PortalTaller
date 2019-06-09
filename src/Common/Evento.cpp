#include "Evento.h"
#include "Constantes.h"
#include "Socket.h"

#include <iostream>


EventoIniciarPartida::EventoIniciarPartida() {
	tipo = EVENTO_INICIAR_PARTIDA;
}
EventoIniciarPartida::EventoIniciarPartida(Socket& s) {
	tipo = EVENTO_INICIAR_PARTIDA;
}
void EventoIniciarPartida::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
}


EventoCreacionPersonaje::EventoCreacionPersonaje(int idPersonaje) {
	tipo = EVENTO_CREACION_PERSONAJE;
	atributos["idPersonaje"] = idPersonaje;
}
EventoCreacionPersonaje::EventoCreacionPersonaje(Socket& s) {
	tipo = EVENTO_CREACION_PERSONAJE;
	atributos["idPersonaje"] = s.recibirInt();
}
void EventoCreacionPersonaje::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["idPersonaje"]);
}


EventoPortalAzul::EventoPortalAzul(int x, int y) {
	tipo = EVENTO_PORTAL_AZUL;
	atributos["x"] = x;
	atributos["y"] = y;
}
EventoPortalAzul::EventoPortalAzul(Socket& s) {
	tipo = EVENTO_PORTAL_AZUL;
	atributos["x"] = s.recibirInt();
	atributos["y"] = s.recibirInt();
}
void EventoPortalAzul::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["x"]);
	s.enviarInt(atributos["y"]);
}


EventoPortalNaranja::EventoPortalNaranja(int x, int y) {
	tipo = EVENTO_PORTAL_NARANJA;
	atributos["x"] = x;
	atributos["y"] = y;
}
EventoPortalNaranja::EventoPortalNaranja(Socket& s) {
	tipo = EVENTO_PORTAL_NARANJA;
	atributos["x"] = s.recibirInt();
	atributos["y"] = s.recibirInt();
}
void EventoPortalNaranja::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["x"]);
	s.enviarInt(atributos["y"]);
}


EventoCrearItem::EventoCrearItem(int idItem, int x, int y, int angulo) {
	tipo = EVENTO_CREAR_ITEM;
	atributos["idItem"] = idItem;
	atributos["x"] = x;
	atributos["y"] = y;
	atributos["angulo"] = angulo;
}
EventoCrearItem::EventoCrearItem(Socket& s) {
	tipo = EVENTO_CREAR_ITEM;
	atributos["idItem"] = s.recibirInt();
	atributos["x"] = s.recibirInt();
	atributos["y"] = s.recibirInt();
	atributos["angulo"] = s.recibirInt();
}
void EventoCrearItem::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["idItem"]);
	s.enviarInt(atributos["x"]);
	s.enviarInt(atributos["y"]);
	s.enviarInt(atributos["angulo"]);
}


EventoResetPortales::EventoResetPortales(int idLanzador) {
	tipo = EVENTO_RESET_PORTALES;
	atributos["idLanzador"] = idLanzador;
}
EventoResetPortales::EventoResetPortales(Socket& s) {
	tipo = EVENTO_RESET_PORTALES;
	atributos["idLanzador"] = s.recibirInt();
}
void EventoResetPortales::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["idLanzador"]);
}


EventoDejarDeMoverse::EventoDejarDeMoverse(int idLanzador) {
	tipo = EVENTO_DEJAR_DE_MOVERSE;
	atributos["idLanzador"] = idLanzador;
}
EventoDejarDeMoverse::EventoDejarDeMoverse(Socket& s) {
	tipo = EVENTO_DEJAR_DE_MOVERSE;
	atributos["idLanzador"] = s.recibirInt();
}
void EventoDejarDeMoverse::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["idLanzador"]);
}


EventoCorrer::EventoCorrer(int direccion, int idLanzador) {
	tipo = EVENTO_CORRER;
	atributos["direccion"] = direccion;
	atributos["idLanzador"] = idLanzador;
}
EventoCorrer::EventoCorrer(Socket& s) {
	tipo = EVENTO_CORRER;
	atributos["direccion"] = s.recibirInt();
	atributos["idLanzador"] = s.recibirInt();
}
void EventoCorrer::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["direccion"]);
	s.enviarInt(atributos["idLanzador"]);
}


EventoMover::EventoMover(int x, int y, int idLanzador) {
	tipo = EVENTO_MOVER;
	atributos["x"] = x;
	atributos["y"] = y;
	atributos["idLanzador"] = idLanzador;
}
EventoMover::EventoMover(Socket& s) {
	tipo = EVENTO_MOVER;
	atributos["x"] = s.recibirInt();
	atributos["y"] = s.recibirInt(); 
	atributos["idLanzador"] = s.recibirInt();
}
void EventoMover::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["x"]);
	s.enviarInt(atributos["y"]);
	s.enviarInt(atributos["idLanzador"]);
}


EventoPinTool::EventoPinTool(int x, int y) {
	tipo = EVENTO_PIN_TOOL;
	atributos["x"] = x;
	atributos["y"] = y;
}
EventoPinTool::EventoPinTool(Socket& s) {
	tipo = EVENTO_PIN_TOOL;
	atributos["x"] = s.recibirInt();
	atributos["y"] = s.recibirInt();
}
void EventoPinTool::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["x"]);
	s.enviarInt(atributos["y"]);
}


EventoSalto::EventoSalto(int idLanzador) {
	tipo = EVENTO_SALTO;
	atributos["idLanzador"] = idLanzador;
}
EventoSalto::EventoSalto(Socket& s) {
	tipo = EVENTO_SALTO;
	atributos["idLanzador"] = s.recibirInt();
}
void EventoSalto::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["idLanzador"]);
}


EventoFlip::EventoFlip(int flip, int idItem) {
	tipo = EVENTO_FLIP;
	atributos["flip"] = flip;
	atributos["idItem"] = idItem;
}
EventoFlip::EventoFlip(Socket& s) {
	tipo = EVENTO_FLIP;
	atributos["flip"] = s.recibirInt();
	atributos["idItem"] = s.recibirInt();
}
void EventoFlip::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["flip"]);
	s.enviarInt(atributos["idItem"]);
}


EventoCambioEstado::EventoCambioEstado(int estado, int idItem) {
	tipo = EVENTO_CAMBIO_ESTADO;
	atributos["estado"] = estado;
	atributos["idItem"] = idItem;
}
EventoCambioEstado::EventoCambioEstado(Socket& s) {
	tipo = EVENTO_CAMBIO_ESTADO;
	atributos["estado"] = s.recibirInt();
	atributos["idItem"] = s.recibirInt();
}
void EventoCambioEstado::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["estado"]);
	s.enviarInt(atributos["idItem"]);
}


EventoEliminarItem::EventoEliminarItem(int idItem) {
	tipo = EVENTO_ELIMINAR_ITEM;
	atributos["idItem"] = idItem;
}
EventoEliminarItem::EventoEliminarItem(Socket& s) {
	tipo = EVENTO_ELIMINAR_ITEM;
	atributos["idItem"] = s.recibirInt();
}
void EventoEliminarItem::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["idItem"]);
}


EventoRotacion::EventoRotacion(int angulo, int idItem) {
	tipo = EVENTO_ROTACION;
	atributos["angulo"] = angulo;
	atributos["idItem"] = idItem;
}
EventoRotacion::EventoRotacion(Socket& s) {
	tipo = EVENTO_ROTACION;
	atributos["angulo"] = s.recibirInt();
	atributos["idItem"] = s.recibirInt();
}
void EventoRotacion::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["angulo"]);
	s.enviarInt(atributos["idItem"]);
}

void EventoMover::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoFlip::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoCambioEstado::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoEliminarItem::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoRotacion::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);} 
void EventoCrearItem::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoCreacionPersonaje::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}