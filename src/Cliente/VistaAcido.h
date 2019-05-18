#ifndef VISTA_ACIDO
#define VISTA_ACIDO 

#include "VistaObjeto.h"
#include <vector>

class VistaAcido : public VistaObjeto {
public:
	VistaAcido(SdlTexture& tex);
	virtual void dibujarEn(int x, int y);
};

#endif