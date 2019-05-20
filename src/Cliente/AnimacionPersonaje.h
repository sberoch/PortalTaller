#ifndef ANIMACION_PERSONAJE
#define ANIMACION_PERSONAJE

#include "Area.h"
#include "SdlTexture.h"
#include <vector>
#include <map>
#include <string>

class AnimacionPersonaje {
private:
	std::map<std::string, std::vector<Area>> mapaAnimaciones;
	int actualSize;
public:
	AnimacionPersonaje();
	Area obtenerConEstado(int estado, int frame);
	int size() const;
};

#endif