#ifndef VISTA_OBJETO
#define VISTA_OBJETO

#include "Area.h"
#include "SdlTexture.h"
#include <vector>

class VistaObjeto {
protected:
	SdlTexture textura;
	std::vector<Area> clips;
	int frame;
	int tamanioHorizontal;
	int tamanioVertical;
public:
	virtual void dibujarEn(int x, int y) = 0;
};

#endif