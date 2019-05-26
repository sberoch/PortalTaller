#include "VistaEmisor.h"

VistaEmisor::VistaEmisor(SdlTexture& tex) {
	this->textura = tex;
	Area srcArea(1, 0, 191, 191);
	clips.push_back(srcArea);
	tamanioHorizontal = 85;
	tamanioVertical = 85;
}

void VistaEmisor::dibujarEn(int x, int y) {
	Area srcArea = clips.front();
	Area destArea(xInicial + x, yInicial + y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}
