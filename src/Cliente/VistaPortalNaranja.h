#ifndef VISTA_PORTAL_NARANJA
#define VISTA_PORTAL_NARANJA 

#include "VistaObjeto.h"

class VistaPortalNaranja : public VistaObjeto {
private:
	int angulo;
public:
	VistaPortalNaranja(SdlTexture& tex, int angulo);
	virtual void dibujarEn(int x, int y);
	virtual ~VistaPortalNaranja() {}
};

#endif