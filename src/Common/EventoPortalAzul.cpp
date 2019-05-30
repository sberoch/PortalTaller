#include "EventoPortalAzul.h"

EventoPortalAzul::EventoPortalAzul(int x, int y) {
	this->x = x;
	this->y = y;
	idItem = 0;
	tipoEvento = 0;
}

void EventoPortalAzul::actualizarEscena(Escena* escena) {
	escena->actualizarCon(*this);
}