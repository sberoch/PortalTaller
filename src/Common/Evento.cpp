#include "Evento.h"

EventoPortalAzul::EventoPortalAzul(int x, int y) {
	atributos["x"] = x;
	atributos["y"] = y;
}

EventoPortalNaranja::EventoPortalNaranja(int x, int y) {
	atributos["x"] = x;
	atributos["y"] = y;
}

EventoCorrer::EventoCorrer(int x, int y) {
	atributos["x"] = x;
	atributos["y"] = y;
}

EventoMover::EventoMover(int idLanzador) {
	atributos["idLanzador"] = idLanzador;
}

EventoPinTool::EventoPinTool(int x, int y) {
	atributos["x"] = x;
	atributos["y"] = y;
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