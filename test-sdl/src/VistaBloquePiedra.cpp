#include "VistaBloquePiedra.h"

VistaBloquePiedra::VistaBloquePiedra(SdlTexture& tex) {
	this->textura = tex;
	srcArea.set(2, 0, 191, 191);
	tamanioHorizontal = 100;
	tamanioVertical = 100;
}

void VistaBloquePiedra::dibujarEn(int x, int y) {
	Area destArea(x, y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}
