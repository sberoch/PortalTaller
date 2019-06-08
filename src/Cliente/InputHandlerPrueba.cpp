#include "InputHandler.h"
#include <iostream>
#include "../Common/Evento.h"

InputHandler::InputHandler(ColaBloqueante<Evento*>& colaEnviar) :
	colaEnviar(colaEnviar) {
	terminado = false;
}

void InputHandler::setPlayerId(int playerId) {
	this->playerId = playerId;
	//Test, poner los metodos que voy a mandar efectivamente
	eventosTeclado.insert(std::make_pair(SDLK_a, 
						new EventoCambioEstado(ESTADO_CORRIENDO, playerId)));
	eventosTeclado.insert(std::make_pair(SDLK_d, 
						new EventoCambioEstado(ESTADO_MUERTO, playerId)));
	eventosTeclado.insert(std::make_pair(SDLK_w, 
						new EventoCambioEstado(ESTADO_SALTANDO, playerId)));

}

bool InputHandler::termino() {
	return terminado;
}

void InputHandler::handle() {
	while(SDL_PollEvent(&event)) {
	    if (event.type == SDL_QUIT) {
			terminado = true;

		} else if (esKeyDown(event)) {
			SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
			handleTeclado(keyEvent.keysym.sym);

		} else if (esMouse(event)) {
			handleMouse(event.button.button);

		} else if (esKeyUp(event)) {
			Evento* evento = new EventoCambioEstado(ESTADO_IDLE, playerId);
			colaEnviar.put(evento);
		}
	}
}

bool InputHandler::esKeyDown(SDL_Event event) const {
	return (event.type == SDL_KEYDOWN);
}

bool InputHandler::esKeyUp(SDL_Event event) const {
	return (event.type == SDL_KEYUP);
}

bool InputHandler::esMouse(SDL_Event event) const {
	return (event.type == SDL_MOUSEBUTTONDOWN);
}

void InputHandler::handleTeclado(int button) {
	if (eventosTeclado.find(button) != eventosTeclado.end()) {
		Evento* evento = eventosTeclado[button];
		colaEnviar.put(evento);
	}
}

void InputHandler::handleMouse(uint8_t button) {
}
