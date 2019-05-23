#include "Escena.h"
#include "../Common/Evento.cpp"
#include <iostream>

Escena::Escena(int width, int heigth) : window(width, heigth) {
	fullscreen = true;
	terminado = false;
	ctrl = false;
}

bool Escena::termino() {
	return terminado;
}

void Escena::recibirCambios() {
	//Suponiendo que la cola devuelve null si no tiene eventos
	//Evento* evento = colaRecibir.pop();
	//if (evento) actualizarCon(evento);
}

void Escena::actualizar() {
	//Loop de dibujado
}

void Escena::manejarEventos() {
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			terminado = true;
			//Evento* evento = new Evento(0, 0, EVENTO_SALIR, 0);
			//colaEnvios.push(evento);

		} else if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (ctrl) std::cout << "Evento: pin tool \n";
			else if (event.button.button == SDL_BUTTON_LEFT) std::cout << "Evento: disparando portal azul \n";
			else if (event.button.button == SDL_BUTTON_RIGHT) std::cout << "Evento: disparando portal naranja \n";

		} else if (event.type == SDL_KEYDOWN) {
			SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
			switch (keyEvent.keysym.sym) {
				case SDLK_a:
					std::cout << "Evento: moviendo izquierda\n";
					break;
				case SDLK_d:
					std::cout << "Evento: moviendo derecha\n";
					break;
				case SDLK_w:
					std::cout << "Evento: salto \n";
					break;
				case SDLK_q:
					std::cout << "Evento: reset portales \n";
					 break;
				case SDLK_F11:
					if (fullscreen) {
						window.setFullscreen(false);
						fullscreen = false;
					} else {
						window.setFullscreen(true);
						fullscreen = true;
					}
					break;
				case SDLK_LCTRL: ctrl = true; break;
			}

		} else if (event.type == SDL_KEYUP) {
			SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
			if (keyEvent.keysym.sym == SDLK_LCTRL) ctrl = false; 
			else std::cout << "Evento: dejar de moverse  \n";
		}
	}
}

Escena::~Escena() {

}