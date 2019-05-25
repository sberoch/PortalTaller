#ifndef VISTA_BLOQUE_PIEDRA
#define VISTA_BLOQUE_PIEDRA 

#include "VistaObjeto.h"

class VistaBloquePiedra : public VistaObjeto {
public:
	VistaBloquePiedra(const SdlTexture& tex);
	void dibujarEn(int x, int y) override;
};

#endif
