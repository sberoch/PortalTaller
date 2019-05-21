#ifndef VISTA_BLOQUE_METAL_DIAGONAL
#define VISTA_BLOQUE_METAL_DIAGONAL 

#include "VistaObjeto.h"

class VistaBloqueMetalDiagonal : public VistaObjeto {
private:
	double rotacion;
public:
	VistaBloqueMetalDiagonal(SdlTexture& tex);
	virtual void dibujarEn(int x, int y);
};

#endif