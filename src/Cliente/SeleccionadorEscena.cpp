#include "SeleccionadorEscena.h"
#include "EscenaJuego.h"
#include "Menu.h"
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
	bool terminado = false;
	while(!terminado) {
	    escena = escenas.at(escenaActual);
		escena->actualizar();
		escena->dibujar();
		escenaActual = escena->manejarEventos();
		if (escena->termino()) 
			terminado = true;
	}
}

SeleccionadorEscena::~SeleccionadorEscena() {
	recibidorEventos.detener();
	enviadorEventos.detener();
	for (auto& it : escenas) {
		delete it.second;
	}
}

