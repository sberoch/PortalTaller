#include "Serializador.h"
#include "Constantes.h"
#include <iostream>

Evento* Serializador::recibirEvento(Socket& socket) {
	int tipoEvento = socket.recibirInt();
	std::cout << tipoEvento << std::endl;
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
		case(EVENTO_CREACION_PERSONAJE): return new EventoCreacionPersonaje(socket);
		case(EVENTO_INICIAR_PARTIDA): return new EventoIniciarPartida(socket);
		case(EVENTO_SUICIDIO): return new EventoSuicidio(socket);
		case(EVENTO_CREAR_PARTIDA): return new EventoCrearPartida(socket);
		case(EVENTO_UNIRSE_A_PARTIDA): return new EventoUnirseAPartida(socket);
		case(EVENTO_ACTUALIZACION_SALA): return new EventoActualizacionSala(socket);
		case(EVENTO_SELECCIONAR_PARTIDA): return new EventoSeleccionarPartida(socket);
		case(EVENTO_INGRESAR_A_SALA): return new EventoIngresarASala(socket);
		case(EVENTO_FIN_DEL_JUEGO): return new EventoFinDelJuego(socket);
		case(EVENTO_JUGADOR_DESCONECTADO): return new EventoJugadorDesconectado(socket);
		default: throw std::runtime_error("Error: se intento recuperar evento con tipo no definido.");
	}
}