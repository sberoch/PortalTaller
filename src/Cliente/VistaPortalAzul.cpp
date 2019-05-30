#include "VistaPortalAzul.h"

VistaPortalAzul::VistaPortalAzul(SdlTexture& tex, int angulo) {
	this->textura = tex;
	this->angulo = angulo;
	Area srcArea(98, 0, 50, 256);
	clips.push_back(srcArea);
	tamanioHorizontal = 16;
	tamanioVertical = 85;
}

void VistaPortalAzul::dibujarEn(int x, int y) {
	Area srcArea = clips.front();
	Area destArea(xInicial + x, yInicial + y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea, (double) angulo, SDL_FLIP_NONE);
}

