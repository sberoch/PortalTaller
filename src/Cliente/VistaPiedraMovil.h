#ifndef VISTA_PIEDRA_MOVIL
#define VISTA_PIEDRA_MOVIL 

#include "VistaObjetoMovil.h"

class VistaPiedraMovil : public VistaObjetoMovil {
public:
	VistaPiedraMovil(SdlTexture& tex);
	void dibujarEn(int x, int y);
	void mover(int x, int y);
};

#endif