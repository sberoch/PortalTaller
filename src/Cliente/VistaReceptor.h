#ifndef VISTA_RECEPTOR
#define VISTA_RECEPTOR

#include "VistaObjeto.h"

class VistaReceptor : public VistaObjeto {
public:
	VistaReceptor(SdlTexture& tex);
	virtual void dibujarEn(int x, int y);
};

#endif