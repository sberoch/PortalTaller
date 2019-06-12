#include "Menu.h"
#include "EnviadorEventos.h"
#include "RecibidorEventos.h"
#include "SdlWindow.h"
#include "../Common/Evento.h"
#include "../Common/Constantes.h"
#include <thread>
#include <chrono>
#include <iostream>

Menu::Menu(SdlWindow& window) : 
	window(window),
	imagenMenuTex("menu.png", window),
	fondo(imagenMenuTex) {
		window.setFullscreen(true);
		terminado = false;
		audio.reproducirMusica();
	}

bool Menu::termino() {
	return terminado;
}

void Menu::actualizar() {
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

void Menu::dibujar() {
	window.fill();
	window.getWindowSize(&xScreen, &yScreen);
	fondo.setDimensiones(xScreen, yScreen);
	fondo.dibujarEn(xScreen/2, yScreen/2);
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	window.render();
}

int Menu::manejarEventos() {
	siguienteEscena = ESCENA_MENU;
	while (SDL_PollEvent(&e) && !terminado) {
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
				siguienteEscena = ESCENA_JUEGO;
			}
		} else if (e.type == SDL_KEYDOWN) {
			SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) e;
			if (keyEvent.keysym.sym == SDLK_F11) window.setFullscreen(false);
		}
	}
	return siguienteEscena;
}


