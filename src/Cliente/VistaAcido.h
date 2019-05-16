#ifndef VISTA_ACIDO
#define VISTA_ACIDO 

#include "VistaObjeto.h"
#include <vector>

class VistaAcido : public VistaObjeto {

//TODO: que importe de una clase VistaObjetoInteractuable

private:
	std::vector<Area> clips;
public:
	VistaAcido(SdlTexture& tex);
	virtual void dibujarEn(int x, int y);
	void dibujarAnimacionEn(int x, int y, int frame);	
};

#endif