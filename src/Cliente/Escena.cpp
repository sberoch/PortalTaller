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
	for (int i = 0; i < objetosDelJuego.size(); ++i) {
		objetosDelJuego[i]->dibujarEn(deltaCamaraX, deltaCamaraY);
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
			if (ctrl) std::cout << "Evento: pin tool \n";
			else if (event.button.button == SDL_BUTTON_LEFT) {
				Evento* evento = new EventoPortalAzul(x, y);
				colaRecibir.put(evento); //test, meterlo en la cola enviar
				audio.reproducirEfecto(EFECTO_DISPARO);
			}
			else if (event.button.button == SDL_BUTTON_RIGHT) std::cout << "Evento: disparando portal naranja \n";

		} else if (event.type == SDL_KEYDOWN) {
			SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
			switch (keyEvent.keysym.sym) {
				case SDLK_a:
					std::cout << "Evento: moviendo izquierda\n";
					deltaCamaraX += 5;
					break;
				case SDLK_d:
					std::cout << "Evento: moviendo derecha\n";
					deltaCamaraX -= 5;
					break;
				case SDLK_w:
					audio.reproducirEfecto(EFECTO_SALTO);
					std::cout << "Evento: salto \n";
					deltaCamaraY += 5;
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

void Escena::actualizarCon(EventoPortalAzul& evento) {
	VistaObjeto* vo = creadorTexturas.crear(ID_PORTAL_AZUL, 
				evento.x - deltaCamaraX, evento.y - deltaCamaraY, 90);
	objetosDelJuego.push_back(vo);
}

Escena::~Escena() {
	for (auto it : objetosDelJuego) {
		delete it;
	}
	objetosDelJuego.clear();
}

void Escena::crearTerreno() {
	//TODO: cargar elementos con estados en lista diferente
	//TODO: cargar elementos moviles en lista diferente
	int id, x, y, angulo;
	YAML::Node escenaYaml = YAML::LoadFile("escenario.yaml");
	YAML::Node objetos = escenaYaml["objetos"];

	for (size_t i = 0; i < objetos.size(); ++i) {
		id = objetos[i]["tipo"].as<int>();
		x = objetos[i]["posX"].as<int>();
		y = objetos[i]["posY"].as<int>();
		angulo = objetos[i]["angulo"].as<int>();
		VistaObjeto* vo = creadorTexturas.crear(id, x, y, angulo);
		objetosDelJuego.push_back(vo);
	} 
	/*int x,y, x2,y2;
	for (int i = 0; i < 27; i++) {
        x2 = -400 + i*100;
        for (int j = 0; j < 7; j++) {
            y2 = -10 + j*100;
            VistaObjeto* vo = creadorTexturas.crear(ID_BLOQUE_PIEDRA, x2, y2);
            objetosDelJuego.push_back(vo);
        }           
    }
	for (int i = 0; i < 27; i++) {
        x = -400 + i*85;
        for (int j = 0; j < 5; j++) {
            y = 500 + j*85;
            VistaObjeto* vo = creadorTexturas.crear(ID_BLOQUE_METAL, x, y);
            objetosDelJuego.push_back(vo);
        }           
    }
    VistaObjeto* vo = creadorTexturas.crear(ID_ACIDO, 620, 487); 
    objetosDelJuego.push_back(vo);
	vo = creadorTexturas.crear(ID_RECEPTOR, 195, 160); 
    objetosDelJuego.push_back(vo);
    vo = creadorTexturas.crear(ID_EMISOR, 195, 245); 
    objetosDelJuego.push_back(vo);
    vo = creadorTexturas.crear(ID_BOTON, 960, 475); 
    objetosDelJuego.push_back(vo);
    vo = creadorTexturas.crear(ID_PUERTA, 1130, 330); 
    objetosDelJuego.push_back(vo);
    vo = creadorTexturas.crear(ID_PIEDRA_MOVIL, 1300, 425);
    objetosDelJuego.push_back(vo);
    vo = creadorTexturas.crear(ID_BARRERA_ENERGIA, 1470, 450); 
    objetosDelJuego.push_back(vo);
    vo = creadorTexturas.crear(ID_BOLA_ENERGIA, 195, 160); 
    objetosDelJuego.push_back(vo);
    vo = creadorTexturas.crear(ID_TORTA, 1725, 435); 
    objetosDelJuego.push_back(vo);
    vo = creadorTexturas.crear(ID_BLOQUE_DIAGONAL_METAL, 450, 330); 
    objetosDelJuego.push_back(vo);
    vo = creadorTexturas.crear(ID_PORTAL_AZUL, 450, 415); 
    objetosDelJuego.push_back(vo);
    vo = creadorTexturas.crear(ID_PORTAL_NARANJA, 450, 330); 
    objetosDelJuego.push_back(vo);
    vo = creadorTexturas.crear(ID_PERSONAJE, 620, 395); 
    objetosDelJuego.push_back(vo);*/
}