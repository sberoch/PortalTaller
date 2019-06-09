#ifndef VISTA_TORTA
#define VISTA_TORTA 

#include "VistaObjeto.h"

class VistaTorta : public VistaObjeto {
public:
	VistaTorta(SdlTexture& tex);
	virtual void dibujarEn(int x, int y);
	virtual ~VistaTorta() {}
};

#endif