#include "VistaEmisor.h"

VistaEmisor::VistaEmisor(SdlTexture& tex) {
	this->textura = tex;
	srcArea.set(1, 0, 191, 191);
	tamanioHorizontal = 85;
	tamanioVertical = 85;
}

void VistaEmisor::dibujarEn(int x, int y) {
	Area destArea(x, y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}
