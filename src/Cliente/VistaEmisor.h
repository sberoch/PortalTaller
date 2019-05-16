#ifndef VISTA_EMISOR
#define VISTA_EMISOR 

#include "VistaObjeto.h"

class VistaEmisor : public VistaObjeto {
public:
	VistaEmisor(SdlTexture& tex);
	virtual void dibujarEn(int x, int y);
};

#endif
