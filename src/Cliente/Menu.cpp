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
	fondo(imagenMenuTex),
	botonJugar("Jugar", 70, window),
	botonSalir("Salir", 60, window) {
		window.setFullscreen(true);
		terminado = false;
		audio.reproducirMusica();
	}

bool Menu::termino() {
	return terminado;
}

void Menu::dibujar() {
	window.fill();

	window.getWindowSize(&xScreen, &yScreen);
	fondo.setDimensiones(xScreen, yScreen);
	fondo.dibujarEn(xScreen/2, yScreen/2);

	dibujarBotones();

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
			if (botonSalir.estaCursorAdentro(x, y)) {
				audio.reproducirEfecto(EFECTO_BOTON_CLICK);
				terminado = true;
			}
			if (botonJugar.estaCursorAdentro(x, y)) {
				audio.reproducirEfecto(EFECTO_BOTON_CLICK);
				siguienteEscena = ESCENA_SALA;
			}
		} else if (e.type == SDL_KEYDOWN) {
			SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) e;
			if (keyEvent.keysym.sym == SDLK_F11) window.setFullscreen(false);
		}
	}
	return siguienteEscena;
}

void Menu::dibujarBotones() {
	//Poner los botones en posiciones relativas al tamaño total de la pantalla
	int xJugar = xScreen/2; 
	int yJugar = 0.6*(yScreen); 
	botonJugar.dibujarEn(xJugar, yJugar);

	int xSalir = xScreen/2;
	int ySalir = 0.74*(yScreen);
	botonSalir.dibujarEn(xSalir, ySalir);
}

void Menu::actualizar() {
	//No se reciben eventos del servidor en el menu
}