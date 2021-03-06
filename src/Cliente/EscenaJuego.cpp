#include "EscenaJuego.h"
#include <iostream>

#include <thread>
#include <chrono>

#include "yaml-cpp/yaml.h"
#include "../Common/Constantes.h"

EscenaJuego::EscenaJuego(SdlWindow& window, ColaBloqueante<Evento*>& colaEnviar, Cola<Evento*>& colaRecibir) : 
	window(window),
	conv(100),
	creadorTexturas(window),
	fondoTex("fondo.png", window),
	fondo(fondoTex),
	colaEnviar(colaEnviar),
	colaRecibir(colaRecibir),
	handler(window, colaEnviar, audio) {

	terminado = false;
	miId = 0;
	deltaCamaraX = 0;
	deltaCamaraY = 0;
	window.fill();
	fondoTex.setColor(80, 80, 80);
}

bool EscenaJuego::termino() {
	return terminado;
}

void EscenaJuego::actualizar() {
	Evento* evento;
	while (colaRecibir.get(evento)) {
		evento->actualizar(*this);
		delete evento;
	}
}

void EscenaJuego::dibujar() {
	window.fill();
	this->sleep(20);
	audio.reproducirMusica();
	actualizarFondo();
	for (auto& it : objetosDelJuego) {
		it.second->dibujarEn(deltaCamaraX, deltaCamaraY);
	}
	window.render();
}

int EscenaJuego::manejarEventos() {
	//Le paso idProximoItem por si necesita crear un objeto nuevo
	if (objetosDelJuego.size() != 0) {
		int idProximoItem = objetosDelJuego.rbegin()->first;
		handler.handle(idProximoItem);
		if (handler.termino()) {
			terminado = true;
		}
	}
	//Se retorna la escena siguiente, en el caso del juego
	// es la escena final, por lo que se devuelve esta constante.
	return ESCENA_JUEGO;
}

void EscenaJuego::manejar(Evento& evento) {
	evento.actualizar(*this);
}

void EscenaJuego::manejar(EventoCrearItem& evento) {
	VistaObjetoPtr vo = creadorTexturas.crear(
							evento.atributos["idItem"], 
							conv.bloqueAPixel(evento.atributos["x"]) - deltaCamaraX, 
							conv.bloqueAPixel(evento.atributos["y"]) - deltaCamaraY, 
							evento.atributos["angulo"]);
	objetosDelJuego.insert(std::make_pair(vo->getId(), vo));
}

void EscenaJuego::manejar(EventoMover& evento) {
	objetosDelJuego.at(evento.atributos["idLanzador"])
			->mover(evento.atributos["x"]*5, evento.atributos["y"]*5);
	if (evento.atributos["idLanzador"] == miId) {
		deltaCamaraX -= evento.atributos["x"]*5;
		deltaCamaraY -= evento.atributos["y"]*5;
	}
}

void EscenaJuego::manejar(EventoFlip& evento) {
	objetosDelJuego.at(evento.atributos["idItem"])->flip(evento.atributos["flip"]);
}

void EscenaJuego::manejar(EventoCambioEstado& evento) {
	objetosDelJuego.at(evento.atributos["idItem"])->asignarEstado(evento.atributos["estado"]);
}

void EscenaJuego::manejar(EventoEliminarItem& evento) {
	objetosDelJuego.erase(evento.atributos["idItem"]);
}

void EscenaJuego::manejar(EventoRotacion& evento) {
	objetosDelJuego.at(evento.atributos["idItem"])->asignarRotacion(evento.atributos["angulo"]);
}

void EscenaJuego::manejar(EventoCreacionPersonaje& evento) {
	this->miId = evento.atributos["idPersonaje"];
	handler.setPlayerId(miId);
	crearTerreno();
}

void EscenaJuego::crearTerreno() {
	int id, x, y, angulo;
	YAML::Node escenaYaml = YAML::LoadFile("escenario.yaml");
	YAML::Node objetos = escenaYaml["objetos"];

	for (size_t i = 0; i < objetos.size(); ++i) {
		id = objetos[i]["tipo"].as<int>();
		x = conv.bloqueAPixel(objetos[i]["posX"].as<int>());
		y = conv.bloqueAPixel(objetos[i]["posY"].as<int>());
		angulo = objetos[i]["angulo"].as<int>();
		VistaObjetoPtr vo = creadorTexturas.crear(id, x, y, angulo);

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

void EscenaJuego::actualizarFondo() {
	int xScreen, yScreen;
	window.getWindowSize(&xScreen, &yScreen);
	fondo.setDimensiones(xScreen, yScreen);
	for(int i = 0; i < 5; ++i) {
		for(int j = 0; j < 3; ++j) {
			fondo.dibujarEn(-xScreen*2 + xScreen*i + deltaCamaraX/2,
							-yScreen/2 + yScreen*j + deltaCamaraY/2);
		}
	}
}

void EscenaJuego::sleep(int tiempo) {
	std::this_thread::sleep_for(std::chrono::milliseconds(20));
}

EscenaJuego::~EscenaJuego() {}