#include "Evento.h"

EventoPortalAzul::EventoPortalAzul(int x, int y, int angulo) {
	this->x = x; this->y = y;
	this->angulo = angulo;
	idItem = 0;
	tipoEvento = 0;
}

EventoPortalNaranja::EventoPortalNaranja(int x, int y, int angulo) {
	this->x = x; this->y = y;
	this->angulo = angulo;
	idItem = 0;
	tipoEvento = 0;
}

EventoCorrer::EventoCorrer(int x, int y) {
	this->x = x; this->y = y;
	angulo = 0;
	idItem = 0;
	tipoEvento = 0;
}

EventoPinTool::EventoPinTool(int x, int y) {
	this->x = x; this->y = y;
	angulo = 0;
	idItem = 0;
	tipoEvento = 0;
}

void EventoPortalAzul::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoPortalNaranja::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoResetPortales::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoDejarDeMoverse::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoCorrer::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoPinTool::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoArriba::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}