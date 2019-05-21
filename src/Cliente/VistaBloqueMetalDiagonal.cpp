#include "VistaBloqueMetalDiagonal.h"

VistaBloqueMetalDiagonal::VistaBloqueMetalDiagonal(SdlTexture& tex) {
	this->textura = tex;
	Area srcArea(2, 405, 185, 185);
	clips.push_back(srcArea);
	tamanioHorizontal = 85;
	tamanioVertical = 85;
	rotacion = 0.0;
}

void VistaBloqueMetalDiagonal::dibujarEn(int x, int y) {
	Area srcArea = clips.front();
	Area destArea(x, y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea, rotacion, SDL_FLIP_NONE);
}
