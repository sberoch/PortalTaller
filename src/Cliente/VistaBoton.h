#ifndef VISTA_BOTON
#define VISTA_BOTON 

#include "VistaObjeto.h"
#include <vector>

class VistaBoton : public VistaObjeto {

//TODO: que importe de una clase VistaObjetoInteractuable

private:
	std::vector<Area> clips;
public:
	VistaBoton(SdlTexture& tex);
	virtual void dibujarEn(int x, int y);
	void dibujarAnimacionEn(int x, int y, int frame);	
};

#endif