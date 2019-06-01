#include "Evento.h"

EventoPortalAzul::EventoPortalAzul(int x, int y, int angulo) {
	this->x = x; this->y = y;
	this->angulo = angulo;
}

EventoPortalNaranja::EventoPortalNaranja(int x, int y, int angulo) {
	this->x = x; this->y = y;
	this->angulo = angulo;
}

EventoCorrer::EventoCorrer(int x, int y) {
	this->x = x; this->y = y;
}

EventoPinTool::EventoPinTool(int x, int y) {
	this->x = x; this->y = y;
}

EventoFlipPersonaje::EventoFlipPersonaje(int flip) {
	this->flip = flip;
}

EventoCambioEstado::EventoCambioEstado(int estado) {
	this->estado = estado;
}

void EventoPortalAzul::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoPortalNaranja::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoResetPortales::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoDejarDeMoverse::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoCorrer::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoPinTool::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoArriba::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoFlipPersonaje::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}
void EventoCambioEstado::actualizarEscena(Escena& escena) {escena.actualizarCon(*this);}