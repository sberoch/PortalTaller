#include "Evento.h"
#include "Constantes.h"
#include "Socket.h"
#include "handler.h"

#include <iostream>

EventoIngresarASala::EventoIngresarASala() {
	tipo = EVENTO_INGRESAR_A_SALA;
}
EventoIngresarASala::EventoIngresarASala(Socket& s) {
	tipo = EVENTO_INGRESAR_A_SALA;
}
void EventoIngresarASala::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
}


EventoIniciarPartida::EventoIniciarPartida(int partidaSeleccionada) {
	tipo = EVENTO_INICIAR_PARTIDA;
	atributos["partidaSeleccionada"] = partidaSeleccionada;
}
EventoIniciarPartida::EventoIniciarPartida(Socket& s) {
	tipo = EVENTO_INICIAR_PARTIDA;
	atributos["partidaSeleccionada"] = s.recibirInt();
}
void EventoIniciarPartida::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["partidaSeleccionada"]);
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


EventoPortalAzul::EventoPortalAzul(int x, int y, int posObjetoEnLista) {
	tipo = EVENTO_PORTAL_AZUL;
	atributos["x"] = x;
	atributos["y"] = y;
	atributos["posObjetoEnLista"] = posObjetoEnLista;
}
EventoPortalAzul::EventoPortalAzul(Socket& s) {
	tipo = EVENTO_PORTAL_AZUL;
	atributos["x"] = s.recibirInt();
	atributos["y"] = s.recibirInt();
	atributos["posObjetoEnLista"] = s.recibirInt();
}
void EventoPortalAzul::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["x"]);
	s.enviarInt(atributos["y"]);
	s.enviarInt(atributos["posObjetoEnLista"]);
}


EventoPortalNaranja::EventoPortalNaranja(int x, int y, int posObjetoEnLista) {
	tipo = EVENTO_PORTAL_NARANJA;
	atributos["x"] = x;
	atributos["y"] = y;
	atributos["posObjetoEnLista"] = posObjetoEnLista;
}
EventoPortalNaranja::EventoPortalNaranja(Socket& s) {
	tipo = EVENTO_PORTAL_NARANJA;
	atributos["x"] = s.recibirInt();
	atributos["y"] = s.recibirInt();
	atributos["posObjetoEnLista"] = s.recibirInt();
}
void EventoPortalNaranja::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["x"]);
	s.enviarInt(atributos["y"]);
	s.enviarInt(atributos["posObjetoEnLista"]);
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


EventoPinTool::EventoPinTool(int x, int y, int posObjetoEnLista) {
	tipo = EVENTO_PIN_TOOL;
	atributos["x"] = x;
	atributos["y"] = y;
	atributos["posObjetoEnLista"] = posObjetoEnLista;
}
EventoPinTool::EventoPinTool(Socket& s) {
	tipo = EVENTO_PIN_TOOL;
	atributos["x"] = s.recibirInt();
	atributos["y"] = s.recibirInt();
	atributos["posObjetoEnLista"] = s.recibirInt();
}
void EventoPinTool::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["x"]);
	s.enviarInt(atributos["y"]);
	s.enviarInt(atributos["posObjetoEnLista"]);
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


EventoSuicidio::EventoSuicidio(int idLanzador) {
	tipo = EVENTO_SUICIDIO;
	atributos["idLanzador"] = idLanzador;
}
EventoSuicidio::EventoSuicidio(Socket& s) {
	tipo = EVENTO_SUICIDIO;
	atributos["idLanzador"] = s.recibirInt();
}
void EventoSuicidio::enviarPorSocket(Socket& s) {
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


EventoCrearPartida::EventoCrearPartida() {
	tipo = EVENTO_CREAR_PARTIDA;;
}
EventoCrearPartida::EventoCrearPartida(Socket& s) {
	tipo = EVENTO_CREAR_PARTIDA;
}
void EventoCrearPartida::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
}


EventoUnirseAPartida::EventoUnirseAPartida(int partidaSeleccionada) {
	tipo = EVENTO_UNIRSE_A_PARTIDA;
	atributos["partidaSeleccionada"] = partidaSeleccionada;
}
EventoUnirseAPartida::EventoUnirseAPartida(Socket& s) {
	tipo = EVENTO_UNIRSE_A_PARTIDA;
	atributos["partidaSeleccionada"] = s.recibirInt();
}
void EventoUnirseAPartida::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["partidaSeleccionada"]);
}


EventoSeleccionarPartida::EventoSeleccionarPartida(int partidaSeleccionada) {
	tipo = EVENTO_SELECCIONAR_PARTIDA;
	atributos["partidaSeleccionada"] = partidaSeleccionada;
}
EventoSeleccionarPartida::EventoSeleccionarPartida(Socket& s) {
	tipo = EVENTO_UNIRSE_A_PARTIDA;
	atributos["partidaSeleccionada"] = s.recibirInt();
}
void EventoSeleccionarPartida::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["partidaSeleccionada"]);
}


EventoActualizacionSala::EventoActualizacionSala(int cantidadPartidas, 
					int partidaSeleccionada, int jugadoresEnPartida) {
	tipo = EVENTO_ACTUALIZACION_SALA;
	atributos["cantidadPartidas"] = cantidadPartidas;
	atributos["partidaSeleccionada"] = partidaSeleccionada;
	atributos["jugadoresEnPartida"] = jugadoresEnPartida;

}
EventoActualizacionSala::EventoActualizacionSala(Socket& s) {
	tipo = EVENTO_ACTUALIZACION_SALA;
	atributos["cantidadPartidas"] = s.recibirInt();
	atributos["partidaSeleccionada"] = s.recibirInt();
	atributos["jugadoresEnPartida"] = s.recibirInt();
}
void EventoActualizacionSala::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["cantidadPartidas"]);
	s.enviarInt(atributos["partidaSeleccionada"]);
	s.enviarInt(atributos["jugadoresEnPartida"]);
}

EventoFinDelJuego::EventoFinDelJuego(int idPersonaje) {
	tipo = EVENTO_FIN_DEL_JUEGO;
	atributos["idPersonaje"] = idPersonaje;
}
EventoFinDelJuego::EventoFinDelJuego(Socket& s) {
	tipo = EVENTO_FIN_DEL_JUEGO;
	atributos["idPersonaje"] = s.recibirInt();
}
void EventoFinDelJuego::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["idPersonaje"]);
}

EventoJugadorDesconectado::EventoJugadorDesconectado(int uuidDelDesconectado) {
	tipo = EVENTO_JUGADOR_DESCONECTADO;
	atributos["uuidDelDesconectado"] = uuidDelDesconectado;
}

EventoJugadorDesconectado::EventoJugadorDesconectado(Socket& s) {
	tipo = EVENTO_JUGADOR_DESCONECTADO;
	atributos["uuidDelDesconectado"] = s.recibirInt();
}

void EventoJugadorDesconectado::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	s.enviarInt(atributos["uuidDelDesconectado"]);
}

void EventoMover::actualizar(Handler& handler) {handler.manejar(*this);}
void EventoFlip::actualizar(Handler& handler) {handler.manejar(*this);}
void EventoCambioEstado::actualizar(Handler& handler) {handler.manejar(*this);}
void EventoEliminarItem::actualizar(Handler& handler) {handler.manejar(*this);}
void EventoRotacion::actualizar(Handler& handler) {handler.manejar(*this);} 
void EventoCrearItem::actualizar(Handler& handler) {handler.manejar(*this);}

void EventoCreacionPersonaje::actualizar(Handler& handler) {handler.manejar(*this);}
void EventoCrearPartida::actualizar(Handler& handler) {handler.manejar(*this);}
void EventoUnirseAPartida::actualizar(Handler& handler) {handler.manejar(*this);}
void EventoActualizacionSala::actualizar(Handler& handler) {handler.manejar(*this);}
void EventoIniciarPartida::actualizar(Handler& handler) {handler.manejar(*this);}
void EventoSeleccionarPartida::actualizar(Handler& handler) {handler.manejar(*this);}
void EventoIngresarASala::actualizar(Handler& handler) {handler.manejar(*this);}
void EventoFinDelJuego::actualizar(Handler& handler) {handler.manejar(*this);}
void EventoJugadorDesconectado::actualizar(Handler& handler) {handler.manejar(*this);}

void EventoPortalAzul::actualizar(Handler& handler) {handler.manejar(*this);}
void EventoPortalNaranja::actualizar(Handler& handler) {handler.manejar(*this);}
void EventoResetPortales::actualizar(Handler& handler) {handler.manejar(*this);}
void EventoSalto::actualizar(Handler& handler) {handler.manejar(*this);}
void EventoSuicidio::actualizar(Handler& handler) {handler.manejar(*this);}
void EventoCorrer::actualizar(Handler& handler) {handler.manejar(*this);}
void EventoDejarDeMoverse::actualizar(Handler& handler) {handler.manejar(*this);}
void EventoPinTool::actualizar(Handler& handler) {handler.manejar(*this);}