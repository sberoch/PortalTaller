#include "Serializador.h"
#include "Constantes.h"

Evento* Serializador::recibirEvento(Socket& socket) {
	int tipoEvento = socket.recibirInt();
	switch(tipoEvento) {
		case(EVENTO_PORTAL_AZUL): return new EventoPortalAzul(socket); 
		case(EVENTO_PORTAL_NARANJA): return new EventoPortalNaranja(socket);
		case(EVENTO_PIN_TOOL): return new EventoPinTool(socket);
	}
}