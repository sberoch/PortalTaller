#ifndef VISTA_RECEPTOR
#define VISTA_RECEPTOR

#include "VistaObjeto.h"

class VistaReceptor : public VistaObjeto {
private:
	int angulo;
public:
	VistaReceptor(SdlTexture& tex, int angulo);
	virtual void dibujarEn(int x, int y);
};

#endif