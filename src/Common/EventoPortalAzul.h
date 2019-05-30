#ifndef EVENTO_PORTAL_AZUL
#define EVENTO_PORTAL_AZUL

#include "Evento.h"

class EventoPortalAzul : public Evento {
public:
	EventoPortalAzul(int x, int y);
	virtual void actualizarEscena(Escena* escena);
};

#endif