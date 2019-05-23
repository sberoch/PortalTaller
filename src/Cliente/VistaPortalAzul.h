#ifndef VISTA_PORTAL_AZUL
#define VISTA_PORTAL_AZUL 

#include "VistaObjeto.h"

class VistaPortalAzul : public VistaObjeto {
public:
	VistaPortalAzul(SdlTexture& tex);
	virtual void dibujarEn(int x, int y);
};

#endif