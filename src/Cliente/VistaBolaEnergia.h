#ifndef VISTA_BOLA_ENERGIA
#define VISTA_BOLA_ENERGIA

#include "VistaObjetoMovil.h"

class VistaBolaEnergia : public VistaObjetoMovil {
private:
	int angulo;
public:
	VistaBolaEnergia(SdlTexture& tex, int angulo);
	virtual void asignarRotacion(int rotacion) override;
	void dibujarEn(int x, int y);
	void mover(int x, int y);
	virtual ~VistaBolaEnergia() {}
};

#endif