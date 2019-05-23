#include "EventHandler.h"
#include "../Common/Evento.h"
#include "../Common/Constantes.h"

bool EventHandler::quit() const {
	return termino;
}

void EventHandler::poll() {
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			termino = true;
		}
	}
}