#ifndef VISTA_BOTON
#define VISTA_BOTON 

#include "VistaObjeto.h"

class VistaBoton : public VistaObjeto {
public:
	VistaBoton(SdlTexture& tex);
	virtual void dibujarEn(int x, int y);
};

#endif