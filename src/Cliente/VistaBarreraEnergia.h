#ifndef VISTA_BARRERA_ENERGIA
#define VISTA_BARRERA_ENERGIA 

#include "VistaObjeto.h"

class VistaBarreraEnergia : public VistaObjeto {
public:
	VistaBarreraEnergia(SdlTexture& tex);
	virtual void dibujarEn(int x, int y);
};

#endif
