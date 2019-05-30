#include "VistaBloqueMetalDiagonal.h"

VistaBloqueMetalDiagonal::VistaBloqueMetalDiagonal(SdlTexture& tex, int angulo) {
	this->textura = tex;
	this->angulo = angulo;
	Area srcArea(2, 405, 185, 185);
	clips.push_back(srcArea);
	tamanioHorizontal = 85;
	tamanioVertical = 85;
}

void VistaBloqueMetalDiagonal::dibujarEn(int x, int y) {
	Area srcArea = clips.front();
	Area destArea(xInicial + x, yInicial + y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea, (double) angulo, SDL_FLIP_NONE);
}
