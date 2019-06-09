#ifndef VISTA_BLOQUE_METAL_DIAGONAL
#define VISTA_BLOQUE_METAL_DIAGONAL 

#include "VistaObjeto.h"

class VistaBloqueMetalDiagonal : public VistaObjeto {
private:
	int angulo;
public:
	VistaBloqueMetalDiagonal(SdlTexture& tex, int angulo);
	virtual void dibujarEn(int x, int y);
	virtual ~VistaBloqueMetalDiagonal() {}
};

#endif