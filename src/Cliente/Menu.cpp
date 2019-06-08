#include "Menu.h"
#include "Escena.h"
#include "EnviadorEventos.h"
#include "RecibidorEventos.h"
#include "SdlWindow.h"
#include "../Common/Evento.h"
#include <thread>
#include <chrono>

Menu::Menu(int xScreen, int yScreen) : 
	xScreen(xScreen), yScreen(yScreen), 
	window(xScreen, yScreen),
	imagenMenuTex("menu.png", window),
	fondo(imagenMenuTex) {
		window.setFullscreen(true);
		terminado = false;
		audio.reproducirMusica();
	}

void Menu::ejecutar() {
	SDL_Event e;
	while(!terminado) {
		asignarPosicionBotones();
		while(SDL_PollEvent(&e)) {
		    handleEvents(e);
			dibujar();
		}
	}
}

void Menu::dibujar() {
	window.fill();
	window.getWindowSize(&xScreen, &yScreen);
	fondo.setDimensiones(xScreen, yScreen);
	fondo.dibujarEn(0, 0);
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	window.render();
}

void Menu::handleEvents(SDL_Event& e) {
	if (e.type == SDL_QUIT) {
		terminado = true;
	} else if (e.type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		if (botonSalir.estaAdentro(x, y)) {
			terminado = true;
		}
		if (botonJugar.estaAdentro(x, y)) {
			audio.pararMusica();
			iniciarJuego();
			terminado = true;
		}
	} else if (e.type == SDL_KEYDOWN) {
		SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) e;
		if (keyEvent.keysym.sym == SDLK_F11) window.setFullscreen(false);
	}
}

void Menu::iniciarJuego() {
	ColaBloqueante<Evento*> colaEnviar;
	Cola<Evento*> colaRecibir;

	RecibidorEventos recibidorEventos(colaRecibir); 
	EnviadorEventos enviadorEventos(colaEnviar);
	recibidorEventos.iniciar();
	enviadorEventos.iniciar();

	Escena escena(window, colaEnviar, colaRecibir);
 
	while(!escena.termino()) {
		escena.manejarEventos();
		escena.recibirCambios();
		escena.actualizar();
	}

	recibidorEventos.detener();
	enviadorEventos.detener();
}

void Menu::asignarPosicionBotones() {
	//Poner los botones en posiciones relativas al tamaño total de la pantalla
	int xJugar = 0.75*(xScreen/2); 
	int yJugar = 0.6*(yScreen); 
	int wJugar = 0.5*(xScreen/2);
	int hJugar = 0.12*(yScreen);
	botonJugar.set(xJugar, yJugar, wJugar, hJugar);

	int xSalir = 0.79*(xScreen/2);
	int ySalir = 0.74*(yScreen);
	int wSalir = 0.2*(xScreen);
	int hSalir = 0.1*(yScreen);
	botonSalir.set(xSalir, ySalir, wSalir, hSalir);
}