#ifndef CREADOR_TEXTURAS
#define CREADOR_TEXTURAS 

#include "SdlWindow.h"
#include "SdlTexture.h"
#include "VistaObjeto.h"

class CreadorTexturas {
private:
	int contadorID;
	SdlTexture bloqueTex;
	SdlTexture emisRecpTex;
	SdlTexture p1Tex, p2Tex, p3Tex, p4Tex;
	SdlTexture miscTex;
	SdlTexture puertaTex;
	SdlTexture efectosTex;
	SdlTexture pinToolTex;
	SdlTexture tortaTex;
	SdlTexture portalesTex;
public:
	CreadorTexturas(const SdlWindow& window);
	VistaObjeto* crear(int tipo, int x, int y, int angulo);
	~CreadorTexturas();
	
};

#endif