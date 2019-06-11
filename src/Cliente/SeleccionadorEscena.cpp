#include "SeleccionadorEscena.h"
#include "../Common/Constantes.h"
#include "Menu.h"

SeleccionadorEscena::SeleccionadorEscena(int xScreen, int yScreen) :
	window(xScreen, yScreen),
	recibidorEventos(colaRecibir, socket),
	enviadorEventos(colaEnviar, socket),
	escenaActual(ESCENA_MENU) {

	socket.conectar("localhost", "8888");

	Evento* eventoIniciar = new EventoIniciarPartida();
	colaEnviar.put(eventoIniciar);

	recibidorEventos.iniciar();
	enviadorEventos.iniciar();

	escenas[ESCENA_JUEGO] = new EscenaJuego(window, colaEnviar, colaRecibir);
	escenas[ESCENA_MENU] = new Menu(window);
}

void SeleccionadorEscena::ejecutar() {
	EscenaBase* escena;
	while(true) {
	    escena = escenas.at(escenaActual);
		escena->actualizar();
		escena->dibujar();
		escenaActual = escena->manejarEventos();
		if (escena->termino()) break;
	}
}

SeleccionadorEscena::~SeleccionadorEscena() {
	recibidorEventos.detener();
	enviadorEventos.detener();
	for (auto& it : escenas) {
		delete it.second;
	}
}

