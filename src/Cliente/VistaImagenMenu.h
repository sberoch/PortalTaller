#ifndef VISTA_IMAGEN_MENU_H
#define VISTA_IMAGEN_MENU_H

#include "VistaObjeto.h"

class VistaImagenMenu : public VistaObjeto {
public:
	VistaImagenMenu(const SdlTexture& tex);
	void setDimensiones(int x, int y);
 	virtual void dibujarEn(int x, int y) override;
};

#endif // VISTA_IMAGEN_MENU_H
