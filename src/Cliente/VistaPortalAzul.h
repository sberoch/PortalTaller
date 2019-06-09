#ifndef VISTA_PORTAL_AZUL
#define VISTA_PORTAL_AZUL 

#include "VistaObjeto.h"

class VistaPortalAzul : public VistaObjeto {
private:
	int angulo;
public:
	VistaPortalAzul(SdlTexture& tex, int angulo);
	virtual void dibujarEn(int x, int y);
	virtual ~VistaPortalAzul() {}
};

#endif