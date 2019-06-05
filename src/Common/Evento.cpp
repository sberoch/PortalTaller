#include "Evento.h"
#include "Constantes.h"

void Evento::enviarPorSocket(Socket& s) {
	s.enviarInt(tipo);
	for (auto& it : atributos) {
		s.enviarInt(it.second);
	}
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

EventoCorrer::EventoCorrer(int x, int y) {
	atributos["x"] = x;
	atributos["y"] = y;
}

EventoMover::EventoMover(int idLanzador) {
	atributos["idLanzador"] = idLanzador;
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

EventoFlip::EventoFlip(int flip, int idLanzador) {
	atributos["flip"] = flip;
	atributos["idLanzador"] = idLanzador;
}

EventoCambioEstado::EventoCambioEstado(int estado, int idLanzador) {
	atributos["estado"] = estado;
	atributos["idLanzador"] = idLanzador;
}

EventoEliminarItem::EventoEliminarItem(int idItem) {
	atributos["idItem"] = idItem;
}

EventoRotacion::EventoRotacion(int angulo, int idItem) {
	atributos["angulo"] = angulo;
	atributos["idItem"] = idItem;

}

void EventoPortalAzul::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoPortalNaranja::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoMover::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoPinTool::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoFlip::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoCambioEstado::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoEliminarItem::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoRotacion::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);} 