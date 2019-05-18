#ifndef VISTA_BOLA_ENERGIA
#define VISTA_BOLA_ENERGIA

#include "VistaObjetoMovil.h"

class VistaBolaEnergia : public VistaObjetoMovil {
public:
	VistaBolaEnergia(SdlTexture& tex);
	void dibujarEn(int x, int y);
	void mover(int x, int y);
	
};

#endif