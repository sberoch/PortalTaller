#include "Escena.h"
#include "../Common/Evento.h"
#include <iostream>

#include <thread>
#include <chrono>

#include "yaml-cpp/yaml.h"
#include "../Common/Constantes.h"

Escena::Escena(SdlWindow& window, ColaBloqueante<Evento*>& colaEnviar, Cola<Evento*>& colaRecibir) : 
	window(window),
	creadorTexturas(window),
	colaEnviar(colaEnviar),
	colaRecibir(colaRecibir),
	conv(100) {

	audio.reproducirMusica();
	fullscreen = true;
	terminado = false;
	ctrl = false;
	miId = 0;
	deltaCamaraX = 0;
	deltaCamaraY = 0;
	window.fill();
	recibirMiIdentificador();
	crearTerreno();
}

bool Escena::termino() {
	return terminado;
}

void Escena::recibirCambios() {
	Evento* evento;
	while (colaRecibir.get(evento)) {
		evento->actualizarEscena(*this);
		delete evento;
	}
	
}

void Escena::actualizar() {
	window.fill();
	std::this_thread::sleep_for(std::chrono::milliseconds(20));
	for (auto& it : objetosDelJuego) {
		it.second->dibujarEn(deltaCamaraX, deltaCamaraY);
	}
	window.render();
}

void Escena::manejarEventos() {
	Evento* evento;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			terminado = true;
		} else if (event.type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState(&x, &y);
			if (ctrl) {
				//evento = new EventoPinTool(x, y);
				//colaEnviar.put(evento);
				evento = new EventoCrearItem(ID_PIN_TOOL, x, y, 0);
				colaEnviar.put(evento);
			}
			else if (event.button.button == SDL_BUTTON_LEFT) {
				//evento = new EventoPortalAzul(dirX, dirY);
				//colaEnviar.put(evento);
				evento = new EventoCambioEstado(ESTADO_DISPARANDO, miId);
				colaEnviar.put(evento);
				evento = new EventoCrearItem(ID_PORTAL_AZUL, x, y, 45);
				colaEnviar.put(evento);
				audio.reproducirEfecto(EFECTO_DISPARO);
			}
			else if (event.button.button == SDL_BUTTON_RIGHT) {
				//evento = new EventoPortalNaranja(dirX, dirY);
				//colaEnviar.put(evento);
				evento = new EventoCambioEstado(ESTADO_DISPARANDO, miId);
				colaEnviar.put(evento);
				evento = new EventoCrearItem(ID_PORTAL_NARANJA, x, y, 135);
				colaEnviar.put(evento);
				audio.reproducirEfecto(EFECTO_DISPARO);
			}

		} else if (event.type == SDL_KEYDOWN) {
			SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
			switch (keyEvent.keysym.sym) {
				case SDLK_a: {
					//evento = new EventoCorrer();
					//colaEnviar.put(evento); mando esto en realidad, pero simulo lo que me manda el server con lo de abajo
					evento = new EventoMover(-15, 0, miId);
					colaEnviar.put(evento);
					evento = new EventoCambioEstado(ESTADO_CORRIENDO, miId);
					colaEnviar.put(evento);
					evento = new EventoFlip(IZQUIERDA, miId);
					colaEnviar.put(evento);
					break;
				}
				case SDLK_d: {
					// evento = new EventoCorrer();
					//colaEnviar.put(evento); mando esto en realidad, pero simulo lo que me manda el server con lo de abajo
					evento = new EventoMover(15, 0, miId);
					colaEnviar.put(evento);
					evento = new EventoCambioEstado(ESTADO_CORRIENDO, miId);
					colaEnviar.put(evento);
					evento = new EventoFlip(DERECHA, miId);
					colaEnviar.put(evento);
					break;
				}
				case SDLK_w: {
					// evento = new EventoSalto();
					//colaEnviar.put(evento); mando esto en realidad, pero simulo lo que me manda el server con lo de abajo
					evento = new EventoMover(0, -10, miId);
					colaEnviar.put(evento);
					evento = new EventoCambioEstado(ESTADO_SALTANDO, miId);
					colaEnviar.put(evento);
					audio.reproducirEfecto(EFECTO_SALTO);
					break;
				}
				case SDLK_k: {
					evento = new EventoCambioEstado(ESTADO_MUERTO, miId);
					colaEnviar.put(evento);
					break;
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
				evento = new EventoCambioEstado(ESTADO_IDLE, miId);
				colaEnviar.put(evento);
			}
		}
	}
}

void Escena::actualizarCon(EventoCrearItem& evento) {
	VistaObjeto* vo = creadorTexturas.crear(evento.atributos["idItem"], 
							evento.atributos["x"] - deltaCamaraX, 
							evento.atributos["y"] - deltaCamaraY, 
							evento.atributos["angulo"]);
	objetosDelJuego.insert(std::make_pair(vo->getId(), vo));
}

void Escena::actualizarCon(EventoMover& evento) {
	objetosDelJuego.at(evento.atributos["idLanzador"])
			->mover(evento.atributos["x"], evento.atributos["y"]);
	if (evento.atributos["idLanzador"] == miId) {
		deltaCamaraX -= evento.atributos["x"];
		deltaCamaraY -= evento.atributos["y"];
	}
}

void Escena::actualizarCon(EventoFlip& evento) {
	objetosDelJuego.at(evento.atributos["idItem"])->flip(evento.atributos["flip"]);
}

void Escena::actualizarCon(EventoCambioEstado& evento) {
	objetosDelJuego.at(evento.atributos["idItem"])->asignarEstado(evento.atributos["estado"]);
}

void Escena::actualizarCon(EventoEliminarItem& evento) {
	objetosDelJuego.erase(evento.atributos["idItem"]);
}

void Escena::actualizarCon(EventoRotacion& evento) {
	objetosDelJuego.at(evento.atributos["idItem"])->asignarRotacion(evento.atributos["angulo"]);
}

void Escena::actualizarCon(EventoCreacionPersonaje& evento) {
	this->miId = evento.atributos["idPersonaje"];
}

Escena::~Escena() {
	for (auto& it : objetosDelJuego) {
		delete it.second;
	}
}

void Escena::recibirMiIdentificador() {
	Evento* eventoCreacionPersonaje;
	bool mandoId = false;
	while(!mandoId) {
		mandoId = colaRecibir.get(eventoCreacionPersonaje);
	}
	eventoCreacionPersonaje->actualizarEscena(*this);
	delete eventoCreacionPersonaje;
}

void Escena::crearTerreno() {
	int id, x, y, angulo;
	YAML::Node escenaYaml = YAML::LoadFile("escenario.yaml");
	YAML::Node objetos = escenaYaml["objetos"];

	for (size_t i = 0; i < objetos.size(); ++i) {
		id = objetos[i]["tipo"].as<int>();
		x = conv.bloqueAPixel(objetos[i]["posX"].as<int>());
		y = conv.bloqueAPixel(objetos[i]["posY"].as<int>());
		angulo = objetos[i]["angulo"].as<int>();
		VistaObjeto* vo = creadorTexturas.crear(id, x, y, angulo);

		if (vo->getId() == miId) {
			//Centrar camara en mi jugador
			int screenX, screenY;
			window.getWindowSize(&screenX, &screenY);
			deltaCamaraX = screenX/2 - x;
			deltaCamaraY = screenY/2 - y;
		}
		objetosDelJuego.insert(std::make_pair(vo->getId(), vo));
	}
}