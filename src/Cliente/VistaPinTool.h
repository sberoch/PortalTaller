#ifndef VISTA_PIN_TOOL
#define VISTA_PIN_TOOL 

#include "VistaObjeto.h"

class VistaPinTool : public VistaObjeto {
private:
	int color;
public:
	VistaPinTool(SdlTexture& tex);
	virtual void dibujarEn(int x, int y);
	virtual void asignarColorSegunPlayer(int playerId) override;
};

#endif