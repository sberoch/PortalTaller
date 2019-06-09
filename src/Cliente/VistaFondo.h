#ifndef VISTA_FONDO_H
#define VISTA_FONDO_H

#include "VistaObjeto.h"

class VistaFondo : public VistaObjeto {
public:
	VistaFondo(const SdlTexture& tex);
	void setDimensiones(int x, int y);
 	virtual void dibujarEn(int x, int y) override;
};

#endif // VISTA_FONDO_H
