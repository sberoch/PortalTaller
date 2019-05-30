#ifndef VISTA_BARRERA_ENERGIA
#define VISTA_BARRERA_ENERGIA 

#include "VistaObjeto.h"

class VistaBarreraEnergia : public VistaObjeto {
private:
	int angulo;
public:
	VistaBarreraEnergia(SdlTexture& tex, int angulo);
	virtual void dibujarEn(int x, int y);
};

#endif
