#include "VistaBloqueMetal.h"

VistaBloqueMetal::VistaBloqueMetal(SdlTexture& tex) {
	this->textura = tex;
	srcArea.set(2, 213, 191, 191);
	tamanioHorizontal = 85;
	tamanioVertical = 85;
}

void VistaBloqueMetal::dibujarEn(int x, int y) {
	Area destArea(x, y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}

