#include "VistaBloquePiedra.h"
#include <iostream>

VistaBloquePiedra::VistaBloquePiedra(const SdlTexture& tex) {
	this->textura = tex;
	Area srcArea(2, 0, 191, 191);
	clips.push_back(srcArea);
	tamanioHorizontal = 100;
	tamanioVertical = 100;
}

void VistaBloquePiedra::dibujarEn(int x, int y) {
	Area srcArea = clips.front();
	Area destArea(xInicial + x, yInicial + y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}
