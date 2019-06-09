#ifndef VISTA_OBJETO_MOVIL
#define VISTA_OBJETO_MOVIL

#include "VistaObjeto.h"

class VistaObjetoMovil : public VistaObjeto {
protected:
	int posX, posY;
public:
	virtual void dibujarEn(int x, int y) = 0;
	virtual void mover(int x, int y) = 0;
	virtual ~VistaObjetoMovil() {}
};

#endif