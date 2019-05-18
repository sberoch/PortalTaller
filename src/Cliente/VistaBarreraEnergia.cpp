#include "VistaBarreraEnergia.h"

VistaBarreraEnergia::VistaBarreraEnergia(SdlTexture& tex) {
	this->textura = tex;
	Area srcArea(1, 1722, 225, 50);
	clips.push_back(srcArea);
	tamanioHorizontal = 225;
	tamanioVertical = 50;
}

void VistaBarreraEnergia::dibujarEn(int x, int y) {
	Area srcArea = clips.front();
	Area destArea(x, y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}
