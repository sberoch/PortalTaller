#ifndef VISTA_BOTON
#define VISTA_BOTON 

#include "VistaObjeto.h"
#include "Audio.h"

class VistaBoton : public VistaObjeto {
private:
	int estado;
	Audio audio;
public:
	VistaBoton(SdlTexture& tex);
	virtual void asignarEstado(int estado) override;
	virtual void dibujarEn(int x, int y);
	virtual ~VistaBoton() {}
};

#endif