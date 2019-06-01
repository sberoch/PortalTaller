#ifndef VISTA_BOTON
#define VISTA_BOTON 

#include "VistaObjeto.h"

class VistaBoton : public VistaObjeto {
private:
	int estado;
public:
	VistaBoton(SdlTexture& tex);
	virtual void asignarEstado(int estado) override;
	virtual void dibujarEn(int x, int y);
};

#endif