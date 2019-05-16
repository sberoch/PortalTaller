#ifndef VISTA_PUERTA
#define VISTA_PUERTA 

#include "VistaObjeto.h"
#include <vector>

class VistaPuerta : public VistaObjeto {

//TODO: que importe de una clase VistaObjetoInteractuable

private:
	std::vector<Area> clips;
public:
	VistaPuerta(SdlTexture& tex);
	virtual void dibujarEn(int x, int y);
	void dibujarAnimacionEn(int x, int y, int frame);	
};

#endif