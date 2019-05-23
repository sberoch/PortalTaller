#ifndef VISTA_PORTAL_NARANJA
#define VISTA_PORTAL_NARANJA 

#include "VistaObjeto.h"

class VistaPortalNaranja : public VistaObjeto {
public:
	VistaPortalNaranja(SdlTexture& tex);
	virtual void dibujarEn(int x, int y);
};

#endif