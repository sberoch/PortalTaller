#include "EscenaSala.h"
#include <thread>
#include <chrono>
#include <string>
#include <iostream>
#include "../Common/Constantes.h"

EscenaSala::EscenaSala(SdlWindow& window, ColaBloqueante<Evento*>& colaEnviar, 
		Cola<Evento*>& colaRecibir) :
	window(window),
	fondoTex("sala.png", window),
	fondo(fondoTex),
	colaEnviar(colaEnviar),
	colaRecibir(colaRecibir),
	botonUnirse("Unirse", 60, window),
	botonCrear("Crear", 60, window),
	botonJugar("Jugar", 60, window) {
		terminado = false;
		cantidadPartidas = 0;
		jugadores = {0,0,0,0};
		partidaSeleccionada = 1;
		cargarTextosPartidasYJugadores();
	}

bool EscenaSala::termino() {
	return terminado;
}

void EscenaSala::actualizar() {
	Evento* evento;
	while (colaRecibir.get(evento)) {
		evento->actualizar(*this);
		delete evento;
	}
}

void EscenaSala::dibujar() {
	window.fill();

	window.getWindowSize(&xScreen, &yScreen);
	fondo.setDimensiones(xScreen, yScreen);
	fondo.dibujarEn(xScreen/2, yScreen/2);

	dibujarBotones();
	dibujarPartidas();
	dibujarJugadoresEnPartida();

	std::this_thread::sleep_for(std::chrono::milliseconds(20));
	window.render();
}

int EscenaSala::manejarEventos() {
	siguienteEscena = ESCENA_SALA;
	Evento* evento;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			terminado = true;
		} else if (e.type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState(&x, &y);
			if (botonJugar.estaCursorAdentro(x, y)) {
				audio.reproducirEfecto(EFECTO_BOTON_CLICK);
				//En realidad, mandar evento iniciar partida y cuando lo recibis te cambia la escena
				siguienteEscena = ESCENA_JUEGO;

			} else if (botonUnirse.estaCursorAdentro(x, y)) {
				audio.reproducirEfecto(EFECTO_BOTON_CLICK);
				evento = new EventoUnirseAPartida(partidaSeleccionada);
				colaEnviar.put(evento);

			} else if (botonCrear.estaCursorAdentro(x, y)) {
				audio.reproducirEfecto(EFECTO_BOTON_CLICK);
				evento = new EventoCrearPartida();
				colaEnviar.put(evento);

			} else if (clickEnAlgunaPartida(x, y)) {
				audio.reproducirEfecto(EFECTO_BOTON_CLICK);
			}
		}
	}
	return siguienteEscena;
}

void EscenaSala::dibujarBotones() {
	//Poner los botones en posiciones relativas al tamaño total de la pantalla
	int xJugar = 0.9*xScreen; 
	int yJugar = 0.9*yScreen; 
	botonJugar.dibujarEn(xJugar, yJugar);

	int xUnirse = xScreen/2;
	int yUnirse = 0.9*yScreen;
	botonUnirse.dibujarEn(xUnirse, yUnirse);

	int xCrear = 0.1*xScreen;
	int yCrear = 0.9*yScreen;
	botonCrear.dibujarEn(xCrear, yCrear);
}

void EscenaSala::dibujarPartidas() {
	for (int i = 0; i < cantidadPartidas; ++i) {
		partidasTextos.at(i)->dibujarEn(0.27*xScreen, 0.15*yScreen + i*0.1*yScreen);
		if (partidaSeleccionada == i+1)
			partidasTextos.at(i)->setSeleccionado(true);
		else
			partidasTextos.at(i)->setSeleccionado(false);
	}
}

void EscenaSala::dibujarJugadoresEnPartida() {
	for (int i = 0; i < jugadores[partidaSeleccionada-1]; ++i) {
		jugadoresTextos.at(i)->dibujarEn(0.72*xScreen, 0.15*yScreen + i*0.1*yScreen);
	}
}

void EscenaSala::cargarTextosPartidasYJugadores() {
	for (int i = 1; i <= 4; ++i) {
		std::string textoStr = "Partida " + std::to_string(i);
		Texto* texto = new Texto(textoStr, 40, window);
		partidasTextos.push_back(texto);
	}
	for (int i = 1; i <= 4; ++i) {
		std::string textoStr = "Jugador " + std::to_string(i);
		Texto* texto = new Texto(textoStr, 40, window);
		jugadoresTextos.push_back(texto);
	}
}

bool EscenaSala::clickEnAlgunaPartida(int x, int y) {
	bool click = false;
	for (int i = 0; i < cantidadPartidas; ++i) {
		if (partidasTextos.at(i)->estaCursorAdentro(x, y)) {
			partidaSeleccionada = i+1;
			click = true;
		}
	}
	return click;
}

void EscenaSala::manejar(Evento& evento) {
	evento.actualizar(*this);
}

void EscenaSala::manejar(EventoActualizacionSala& evento) {
	cantidadPartidas = evento.atributos["cantidadPartidas"];
	jugadores.at(evento.atributos["partidaSeleccionada"]) = 
						evento.atributos["jugadoresEnPartida"];
}

EscenaSala::~EscenaSala() {
	for (auto& it : partidasTextos) {
		delete it;
	}
	for (auto& it : jugadoresTextos) {
		delete it;
	}
}