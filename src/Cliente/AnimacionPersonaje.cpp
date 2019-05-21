#include "AnimacionPersonaje.h"
#include "../Common/Constantes.h"

AnimacionPersonaje::AnimacionPersonaje() {
	//Idle
	std::vector<Area> clipsIdle;
	for (int i = 0; i < 7; ++i) {
		Area area(i*105, 2074, 105, 215);
		clipsIdle.push_back(area);
	}
	mapaAnimaciones.insert(std::make_pair("idle", clipsIdle));

	//Corriendo
	std::vector<Area> clipsCorriendo;
	for (int i = 0; i < 8; ++i) {
		Area area(1 + i*195, 4123, 195, 215);
		clipsCorriendo.push_back(area);
	}
	for (int i = 0; i < 4; ++i) {
		Area area(1 + i*195, 4330, 195, 215);
		clipsCorriendo.push_back(area);
	}
	mapaAnimaciones.insert(std::make_pair("corriendo", clipsCorriendo));

	//Disparando
	std::vector<Area> clipsDisparando;
	for (int i = 0; i < 5; ++i) {
		Area area(i*173, 2305, 173, 215);
		clipsDisparando.push_back(area);
	}
	mapaAnimaciones.insert(std::make_pair("disparando", clipsDisparando));

	//Muerto
	std::vector<Area> clipsMuerto;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 9; ++j) {
			Area area(1656 + 176*j, 3407 + 265*i, 170, 215);
			clipsMuerto.push_back(area);
		}
	}
	mapaAnimaciones.insert(std::make_pair("muerto", clipsMuerto));
}

Area AnimacionPersonaje::obtenerConEstado(int estado, int frame) {
	std::vector<Area> ret;
	switch (estado) {
		case ESTADO_IDLE: {
			ret = mapaAnimaciones.at("idle");
			break;	
		}
		case ESTADO_CORRIENDO: {
			ret = mapaAnimaciones.at("corriendo");
			break;
		}
		case ESTADO_DISPARANDO: {
			ret = mapaAnimaciones.at("disparando");
			break;
		}
		case ESTADO_MUERTO: {
			ret = mapaAnimaciones.at("muerto");
			break;
		}
	}
	actualSize = ret.size();
	return ret.at(frame);
}

int AnimacionPersonaje::size() const {
	return actualSize;
}