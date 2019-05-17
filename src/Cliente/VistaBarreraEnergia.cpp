#include "VistaBarreraEnergia.h"

VistaBarreraEnergia::VistaBarreraEnergia(SdlTexture& tex) {
	this->textura = tex;
	srcArea.set(1, 1722, 225, 50);
	tamanioHorizontal = 225;
	tamanioVertical = 50;
}

void VistaBarreraEnergia::dibujarEn(int x, int y) {
	Area destArea(x, y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}
