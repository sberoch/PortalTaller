#ifndef VISTA_PUERTA
#define VISTA_PUERTA 

#include "VistaObjeto.h"

class VistaPuerta : public VistaObjeto {
private:
	int estado;
public:
	VistaPuerta(SdlTexture& tex);
	virtual void asignarEstado(int estado) override;
	virtual void dibujarEn(int x, int y);
	virtual ~VistaPuerta() {}
};

#endif