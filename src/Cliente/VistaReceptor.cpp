#include "VistaReceptor.h"

VistaReceptor::VistaReceptor(SdlTexture& tex) {
	this->textura = tex;
	Area srcArea(199, 0, 191, 191);
	clips.push_back(srcArea);
	tamanioHorizontal = 85;
	tamanioVertical = 85;
}

void VistaReceptor::dibujarEn(int x, int y) {
	Area srcArea = clips.front();
	Area destArea(x, y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}
