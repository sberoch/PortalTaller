#ifndef VISTA_BLOQUE_METAL
#define VISTA_BLOQUE_METAL 

#include "VistaObjeto.h"

class VistaBloqueMetal : public VistaObjeto {
public:
	VistaBloqueMetal(SdlTexture& tex);
	virtual void dibujarEn(int x, int y);
};

#endif