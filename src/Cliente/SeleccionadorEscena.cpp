#include "SeleccionadorEscena.h"
#include "EscenaJuego.h"
#include "EscenaSala.h"
#include "Menu.h"
#include "../Common/Constantes.h"
#include "Menu.h"
#include <iostream>

SeleccionadorEscena::SeleccionadorEscena(char* host, char* port, int xScreen, int yScreen) :
	window(xScreen, yScreen),
	recibidorEventos(colaRecibir, socket),
	enviadorEventos(colaEnviar, socket),
	escenaActual(ESCENA_MENU) {

	socket.conectar(host, port);

	recibidorEventos.iniciar();
	enviadorEventos.iniciar();

	escenas.insert(std::make_pair(ESCENA_JUEGO, new EscenaJuego(window, colaEnviar, colaRecibir)));
	escenas.insert(std::make_pair(ESCENA_SALA, new EscenaSala(window, colaEnviar, colaRecibir)));
	escenas.insert(std::make_pair(ESCENA_MENU, new Menu(window, colaEnviar)));
}

void SeleccionadorEscena::ejecutar() {
	EscenaBase* escena;
	bool avisado = false;
	bool terminado = false;
	while(!terminado) {
	    escena = escenas.at(escenaActual);
		escena->actualizar();
		escena->dibujar();
		escenaActual = escena->manejarEventos();
		if (escena->termino()) {
			terminado = true;
			terminar();
		}
		if ((escenaActual == ESCENA_JUEGO) && !avisado) {
			avisarComienzoJuego();
			avisado = true;
		}	
	}
}

void SeleccionadorEscena::avisarComienzoJuego() {
	Evento* eventoSolicitarId = new EventoSolicitarId();
	colaEnviar.put(eventoSolicitarId);
}

void SeleccionadorEscena::terminar() {
	//Esto cierra pero por un fallo, creo que por doble join.
	//Si lo saco no cierra
	recibidorEventos.detener();
	recibidorEventos.cerrar();
	enviadorEventos.detener();
	enviadorEventos.cerrar();
	for (auto& it : escenas) {
		delete it.second;
	}
	escenas.clear();
}

