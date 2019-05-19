#include "AnimacionPersonaje.h"

#define ESTADO_IDLE 0
#define ESTADO_CORRIENDO 1

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
}

Area& AnimacionPersonaje::obtenerConEstado(int estado, int frame) {
	switch (estado) {
		case ESTADO_IDLE: {
			std::vector<Area> ret = mapaAnimaciones.at("idle");
			actualSize = ret.size();
			return ret.at(frame); 
		}
		case ESTADO_CORRIENDO: {
			std::vector<Area> ret = mapaAnimaciones.at("corriendo");
			actualSize = ret.size();
			return ret.at(frame);
		}
	}
}

int AnimacionPersonaje::size() const {
	return actualSize;
}