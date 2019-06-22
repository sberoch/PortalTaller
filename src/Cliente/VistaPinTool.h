#ifndef VISTA_PIN_TOOL
#define VISTA_PIN_TOOL 

#include "VistaObjeto.h"

class VistaPinTool : public VistaObjeto {
private:
	int color;
public:
	VistaPinTool(SdlTexture& tex, int playerId);
	virtual void dibujarEn(int x, int y);
	virtual ~VistaPinTool() {}
};

#endif