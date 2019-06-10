#include "VistaPortalAzul.h"

VistaPortalAzul::VistaPortalAzul(SdlTexture& tex, int angulo) {
	this->textura = tex;
	this->angulo = angulo;
	Area srcArea(85, 0, 30, 200);
	clips.push_back(srcArea);
	tamanioHorizontal = 15;
	tamanioVertical = 100;
}

void VistaPortalAzul::dibujarEn(int x, int y) {
	Area srcArea = clips.front();
	Area destArea(xInicial + x - tamanioHorizontal/2,
				  yInicial + y - tamanioVertical/2, 
				  tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea, (double) angulo, SDL_FLIP_NONE);
}

