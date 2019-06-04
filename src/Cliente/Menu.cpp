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
	while(!terminado) {
		asignarPosicionBotones();
		SDL_Event e;
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
	}
}

void Menu::iniciarJuego() {
	ColaBloqueante<Evento*> colaEnviar;
	Cola<Evento*> colaRecibir;

	Escena escena(window, colaEnviar, colaRecibir);
	//Anda bien, pero no usar hasta no tener los socket, come 100% cpu sino (while true)
	RecibidorEventos recibidorEventos(colaRecibir); 
	EnviadorEventos enviadorEventos(colaEnviar);
	recibidorEventos.iniciar();
	enviadorEventos.iniciar();
 
	while(!escena.termino()) {
		escena.recibirCambios();
		escena.actualizar();
		escena.manejarEventos();
	}

	recibidorEventos.detener();
	enviadorEventos.detener();
}

void Menu::asignarPosicionBotones() {
	//Poner los botones en posiciones relativas al tamaño total de la pantalla
	int xJugar = 0.75*(xScreen/2); 
	int yJugar = 0.6*(yScreen); 
	int wJugar = 390;
	int hJugar = 110;
	botonJugar.set(xJugar, yJugar, wJugar, hJugar);

	int xSalir = 0.79*(xScreen/2);
	int ySalir = 0.74*(yScreen);
	int wSalir = 330;
	int hSalir = 90;
	botonSalir.set(xSalir, ySalir, wSalir, hSalir);
}