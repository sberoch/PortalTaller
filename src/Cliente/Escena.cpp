#include "Escena.h"
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
	conv(100),
	handler(window, colaEnviar, audio) {

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
	handler.handle();
	if (handler.termino()) {
		terminado = true;
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
	handler.setPlayerId(miId);
}

Escena::~Escena() {
	for (auto& it : objetosDelJuego) {
		delete it.second;
	}
}

void Escena::recibirMiIdentificador() {
	Evento* eventoCreacionPersonaje;
	bool recibiId = false;
	while(!recibiId) {
		recibiId = colaRecibir.get(eventoCreacionPersonaje);
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