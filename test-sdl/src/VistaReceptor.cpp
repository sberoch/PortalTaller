#include "VistaReceptor.h"

VistaReceptor::VistaReceptor(SdlTexture& tex) {
	this->textura = tex;
	srcArea.set(199, 0, 191, 191);
	tamanioHorizontal = 85;
	tamanioVertical = 85;
}

void VistaReceptor::dibujarEn(int x, int y) {
	Area destArea(x, y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}
