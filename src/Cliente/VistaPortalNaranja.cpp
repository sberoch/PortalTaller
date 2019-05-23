#include "VistaPortalNaranja.h"

VistaPortalNaranja::VistaPortalNaranja(SdlTexture& tex) {
	this->textura = tex;
	Area srcArea(398, 0, 50, 256);
	clips.push_back(srcArea);
	tamanioHorizontal = 16;
	tamanioVertical = 85;
}

void VistaPortalNaranja::dibujarEn(int x, int y) {
	Area srcArea = clips.front();
	Area destArea(x, y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}

