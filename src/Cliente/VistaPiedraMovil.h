#ifndef VISTA_PIEDRA_MOVIL
#define VISTA_PIEDRA_MOVIL 

#include "VistaObjeto.h"

class VistaPiedraMovil : public VistaObjeto {
public:
	VistaPiedraMovil(SdlTexture& tex);
	virtual void dibujarEn(int x, int y);
};

#endif