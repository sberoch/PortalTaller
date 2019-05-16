#ifndef VISTA_OBJETO
#define VISTA_OBJETO

#include "Area.h"
#include "SdlTexture.h"

class VistaObjeto {
protected:
	SdlTexture textura;
	Area srcArea;
	int tamanioHorizontal;
	int tamanioVertical;
public:
	VistaObjeto();
	virtual void dibujarEn(int x, int y) = 0;
};

#endif