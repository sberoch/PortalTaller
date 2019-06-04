#include "VistaPortalNaranja.h"

VistaPortalNaranja::VistaPortalNaranja(SdlTexture& tex, int angulo) {
	this->textura = tex;
	this->angulo = angulo;
	Area srcArea(398, 0, 50, 256);
	clips.push_back(srcArea);
	tamanioHorizontal = 20;
	tamanioVertical = 100;
}

void VistaPortalNaranja::dibujarEn(int x, int y) {
	Area srcArea = clips.front();
	Area destArea(xInicial + x, yInicial + y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea, (double) angulo, SDL_FLIP_NONE);
}

