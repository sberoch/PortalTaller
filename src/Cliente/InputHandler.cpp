#include "InputHandler.h"
#include <iostream>
#include "../Common/Evento.h"

InputHandler::InputHandler(SdlWindow& window, ColaBloqueante<Evento*>& colaEnviar, Audio& audio) :
	window(window),
	colaEnviar(colaEnviar),
	audio(audio),
	conv(100) {
	terminado = false;
	fullscreen = true;
	ctrl = false;
}

void InputHandler::setPlayerId(int playerId) {
	this->playerId = playerId;
}

bool InputHandler::termino() {
	return terminado;
}

void InputHandler::handle() {
	Evento* evento;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			terminado = true;
		} else if (event.type == SDL_MOUSEBUTTONDOWN) {
			int x, y, xScreen, yScreen;
			SDL_GetMouseState(&x, &y);
			window.getWindowSize(&xScreen, &yScreen);
			int dirX = x - (xScreen/2); 
			int dirY = y - (yScreen/2 + 50);
			if (ctrl) {
				evento = new EventoPinTool(conv.pixelABloque(x), conv.pixelABloque(y));
				colaEnviar.put(evento);
				//evento = new EventoCrearItem(ID_PIN_TOOL_4, x, y, 0);
				//colaEnviar.put(evento);
			}
			else if (event.button.button == SDL_BUTTON_LEFT) {
				evento = new EventoPortalAzul(dirX, dirY);
				colaEnviar.put(evento);
				//evento = new EventoCambioEstado(ESTADO_DISPARANDO, playerId);
				//colaEnviar.put(evento);
				//evento = new EventoCrearItem(ID_PORTAL_AZUL, x, y, 45);
				//colaEnviar.put(evento);
				audio.reproducirEfecto(EFECTO_DISPARO);
			}
			else if (event.button.button == SDL_BUTTON_RIGHT) {
				evento = new EventoPortalNaranja(dirX, dirY);
				colaEnviar.put(evento);
				//evento = new EventoCambioEstado(ESTADO_DISPARANDO, playerId);
				//colaEnviar.put(evento);
				//evento = new EventoCrearItem(ID_PORTAL_NARANJA, x, y, 135);
				//colaEnviar.put(evento);
				audio.reproducirEfecto(EFECTO_DISPARO);
			}

		} else if (event.type == SDL_KEYDOWN) {
			SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
			switch (keyEvent.keysym.sym) {
				case SDLK_a: {
					evento = new EventoCorrer(IZQUIERDA, playerId);
					colaEnviar.put(evento);
					//evento = new EventoMover(-3, 0, playerId);
					//colaEnviar.put(evento);
					//evento = new EventoCambioEstado(ESTADO_CORRIENDO, playerId);
					//colaEnviar.put(evento);
					//evento = new EventoFlip(IZQUIERDA, playerId);
					//colaEnviar.put(evento);
					break;
				}
				case SDLK_d: {
					evento = new EventoCorrer(DERECHA, playerId);
					colaEnviar.put(evento); 
					//evento = new EventoMover(3, 0, playerId);
					//colaEnviar.put(evento);
					//evento = new EventoCambioEstado(ESTADO_CORRIENDO, playerId);
					//colaEnviar.put(evento);
					//evento = new EventoFlip(DERECHA, playerId);
					//colaEnviar.put(evento);
					break;
				}
				case SDLK_w: {
					evento = new EventoSalto(playerId);
					colaEnviar.put(evento); 
					//evento = new EventoMover(0, -3, playerId);
					//colaEnviar.put(evento);
					//evento = new EventoCambioEstado(ESTADO_SALTANDO, playerId);
					//colaEnviar.put(evento);
					break;
				}
				case SDLK_k: {
					evento = new EventoSuicidio(playerId);
					colaEnviar.put(evento);
					//evento = new EventoCambioEstado(ESTADO_MUERTO, playerId);
					//colaEnviar.put(evento);
					break;
				}

				case SDLK_q: {
					evento = new EventoResetPortales(playerId);
					colaEnviar.put(evento);
				}

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
			if (keyEvent.keysym.sym == SDLK_LCTRL) {
				ctrl = false; 
			} else {
				evento = new EventoDejarDeMoverse(playerId);
				colaEnviar.put(evento);
				//evento = new EventoCambioEstado(ESTADO_IDLE, playerId);
				//colaEnviar.put(evento);
			}
		}
	}
}