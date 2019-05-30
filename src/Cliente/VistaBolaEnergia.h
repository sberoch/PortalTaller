#ifndef VISTA_BOLA_ENERGIA
#define VISTA_BOLA_ENERGIA

#include "VistaObjetoMovil.h"

class VistaBolaEnergia : public VistaObjetoMovil {
private:
	int angulo;
public:
	VistaBolaEnergia(SdlTexture& tex, int angulo);
	void dibujarEn(int x, int y);
	void mover(int x, int y);
	
};

#endif