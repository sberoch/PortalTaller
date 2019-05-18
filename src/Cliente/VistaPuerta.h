#ifndef VISTA_PUERTA
#define VISTA_PUERTA 

#include "VistaObjeto.h"

class VistaPuerta : public VistaObjeto {
public:
	VistaPuerta(SdlTexture& tex);
	virtual void dibujarEn(int x, int y);
};

#endif