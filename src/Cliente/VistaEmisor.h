#ifndef VISTA_EMISOR
#define VISTA_EMISOR 

#include "VistaObjeto.h"

class VistaEmisor : public VistaObjeto {
private:
	int angulo;
public:
	VistaEmisor(SdlTexture& tex, int angulo);
	virtual void dibujarEn(int x, int y);
	virtual ~VistaEmisor() {}
};

#endif
