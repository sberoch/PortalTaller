#include "Escena.h"
#include "../Common/Evento.cpp"
#include <iostream>

#include <thread>
#include <chrono>

#include "yaml-cpp/yaml.h"
#include "../Common/Constantes.h"

Escena::Escena(int width, int heigth, ColaBloqueante<Evento*>& colaEnviar, Cola<Evento*>& colaRecibir) : 
	window(width, heigth),
	creadorTexturas(window),
	colaEnviar(colaEnviar),
	colaRecibir(colaRecibir) {

	audio.reproducirMusica();
	fullscreen = true;
	terminado = false;
	ctrl = false;
	deltaCamaraX = 0;
	deltaCamaraY = 0;
	window.fill();
	crearTerreno();
}

bool Escena::termino() {
	return terminado;
}

void Escena::recibirCambios() {
	Evento* evento;
	if (colaRecibir.get(evento)) {
		evento->actualizarEscena(*this);
		delete evento;
	}
	
}

void Escena::actualizar() {
	window.fill();
	std::this_thread::sleep_for(std::chrono::milliseconds(20));
	//Dibujar objetos moviles
	for (int i = 1; i <= objetosDelJuego.size(); ++i) {
		objetosDelJuego.at(i)->dibujarEn(deltaCamaraX, deltaCamaraY);
	}
	window.render();
}

void Escena::manejarEventos() {
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			terminado = true;

		} else if (event.type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState(&x, &y);
			if (ctrl) {
				Evento* evento = new EventoPinTool(x, y);
				colaRecibir.put(evento);
			}
			else if (event.button.button == SDL_BUTTON_LEFT) {
				Evento* evento = new EventoPortalAzul(x, y, 0);
				colaRecibir.put(evento); //test, meterlo en la cola enviar
				audio.reproducirEfecto(EFECTO_DISPARO);
			}
			else if (event.button.button == SDL_BUTTON_RIGHT) {
				Evento* evento = new EventoPortalNaranja(x, y, 90);
				colaRecibir.put(evento); //test, meterlo en la cola enviar
				audio.reproducirEfecto(EFECTO_DISPARO);
			}

		} else if (event.type == SDL_KEYDOWN) {
			SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
			switch (keyEvent.keysym.sym) {
				case SDLK_a: {
					Evento* evento = new EventoCorrer(-15, 0); //Server asigna velocidad, no hacerlo desde aca
					colaRecibir.put(evento);
					deltaCamaraX += 15;
					break;
				}
				case SDLK_d: {
					Evento* evento = new EventoCorrer(15, 0);
					colaRecibir.put(evento);
					deltaCamaraX -= 15;
					break;
				}
				case SDLK_w: {
					Evento* evento = new EventoArriba();
					colaRecibir.put(evento);
					audio.reproducirEfecto(EFECTO_SALTO);
					break;
				}
				case SDLK_q: {
					Evento* evento = new EventoResetPortales();
					colaRecibir.put(evento);
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
				Evento* evento = new EventoDejarDeMoverse();
				colaRecibir.put(evento);
			}
		}
	}
}

void Escena::actualizarCon(EventoPortalAzul& evento) {
	VistaObjeto* vo = creadorTexturas.crear(ID_PORTAL_AZUL, 
				evento.x - deltaCamaraX, evento.y - deltaCamaraY, evento.angulo);
	objetosDelJuego.insert(std::make_pair(vo->getId(), vo));
}

void Escena::actualizarCon(EventoPortalNaranja& evento) {
	VistaObjeto* vo = creadorTexturas.crear(ID_PORTAL_NARANJA, 
				evento.x - deltaCamaraX, evento.y - deltaCamaraY, evento.angulo);
	objetosDelJuego.insert(std::make_pair(vo->getId(), vo));
}

void Escena::actualizarCon(EventoResetPortales& evento) {
	//IDs hardcodeado
	//Supone que siempre estan los dos portales
	objetosDelJuego.erase(29);
	objetosDelJuego.erase(30);
}

void Escena::actualizarCon(EventoDejarDeMoverse& evento) {
	objetosDelJuego.at(28)->asignarEstado(ESTADO_IDLE);
}

void Escena::actualizarCon(EventoCorrer& evento) {
	VistaObjeto* vo = objetosDelJuego.at(28);
	vo->asignarEstado(ESTADO_CORRIENDO);
	vo->mover(evento.x, evento.y);
	//flip
}

void Escena::actualizarCon(EventoArriba& evento) {
	VistaObjeto* vo = objetosDelJuego.at(28);
	vo->asignarEstado(ESTADO_SALTANDO);
	vo->mover(0, -10);
	deltaCamaraY += 10;
}

void Escena::actualizarCon(EventoPinTool& evento) {
	VistaObjeto* vo = creadorTexturas.crear(ID_PIN_TOOL, 
				evento.x - deltaCamaraX, evento.y - deltaCamaraY, 0);
	objetosDelJuego.insert(std::make_pair(vo->getId(), vo));
}

Escena::~Escena() {
	for (auto it : objetosDelJuego) {
		delete it.second;
	}
}

void Escena::crearTerreno() {
	int id, x, y, angulo;
	YAML::Node escenaYaml = YAML::LoadFile("escenario.yaml");
	YAML::Node objetos = escenaYaml["objetos"];

	for (size_t i = 0; i < objetos.size(); ++i) {
		id = objetos[i]["tipo"].as<int>();
		x = objetos[i]["posX"].as<int>();
		y = objetos[i]["posY"].as<int>();
		angulo = objetos[i]["angulo"].as<int>();
		VistaObjeto* vo = creadorTexturas.crear(id, x, y, angulo);
		objetosDelJuego.insert(std::make_pair(vo->getId(), vo));
	}
}