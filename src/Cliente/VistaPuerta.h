#ifndef VISTA_PUERTA
#define VISTA_PUERTA 

#include "VistaObjeto.h"
#include "Audio.h"

class VistaPuerta : public VistaObjeto {
private:
	int estado;
	Audio audio;
public:
	VistaPuerta(SdlTexture& tex);
	virtual void asignarEstado(int estado) override;
	virtual void dibujarEn(int x, int y);
	virtual ~VistaPuerta() {}
};

#endif