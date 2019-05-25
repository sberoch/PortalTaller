#ifndef TERENO
#define TERENO 

#include "SdlWindow.h"
#include "SdlTexture.h"
#include "VistaObjeto.h"
#include "CreadorTexturas.h"
#include <vector>

class Terreno {
private:
	std::vector<VistaObjeto*> objetosDelTerreno;
	SdlTexture bloqueTex;
	int x, y;
public:
	Terreno(const SdlWindow& window);
	void actualizar(int deltaX, int deltaY);
	~Terreno();
};

#endif