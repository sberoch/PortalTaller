#include "Serializador.h"
#include "Constantes.h"

Evento* Serializador::recibirEvento(Socket& socket) {
	int tipoEvento = socket.recibirInt();
	switch(tipoEvento) {
		case(EVENTO_PORTAL_AZUL): return new EventoPortalAzul(socket); 
		case(EVENTO_PORTAL_NARANJA): return new EventoPortalNaranja(socket);
		case(EVENTO_PIN_TOOL): return new EventoPinTool(socket);
		case(EVENTO_MOVER): return new EventoMover(socket);
		case(EVENTO_CAMBIO_ESTADO): return new EventoCambioEstado(socket);
		case(EVENTO_FLIP): return new EventoFlip(socket);
		case(EVENTO_CORRER): return new EventoCorrer(socket);
		case(EVENTO_ELIMINAR_ITEM): return new EventoEliminarItem(socket); 
		case(EVENTO_ROTACION): return new EventoRotacion(socket);
		case(EVENTO_RESET_PORTALES): return new EventoResetPortales(socket);
		case(EVENTO_SALTO): return new EventoSalto(socket);
		case(EVENTO_DEJAR_DE_MOVERSE): return new EventoDejarDeMoverse(socket);
		case(EVENTO_CREAR_ITEM): return new EventoCrearItem(socket);
	}
}