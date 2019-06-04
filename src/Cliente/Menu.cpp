#include "Menu.h"

#include <thread>
#include <chrono>

Menu::Menu(int xScreen, int yScreen) : 
	xScreen(xScreen), yScreen(yScreen), 
	window(xScreen, yScreen),
	imagenMenuTex("menu.png", window),
	fondo(imagenMenuTex) {
		window.setFullscreen(true);
		terminado = false;
	}

void Menu::ejecutar() {
	while(!terminado) {
		SDL_Event e;
		while(SDL_PollEvent(&e)) {
		    handleEvents(e);
			dibujar();
		}
	}
	//En el handle de la escena va todo lo que ahora esta en main
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
		if (botonJugar.estaAdentro(x, y)) {
			//Jugar
		} else if (botonSalir.estaAdentro(x, y)) {
			terminado = true;
		}
	}
}

void Menu::asignarPosicionBotones() {
	//Poner los botones en posiciones relativas al tamaño total de la pantalla
}