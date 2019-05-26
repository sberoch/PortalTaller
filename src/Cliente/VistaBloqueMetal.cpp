#include "VistaBloqueMetal.h"

VistaBloqueMetal::VistaBloqueMetal(SdlTexture& tex) {
	this->textura = tex;
	Area srcArea(2, 213, 191, 191);
	clips.push_back(srcArea);
	tamanioHorizontal = 85;
	tamanioVertical = 85;
}

void VistaBloqueMetal::dibujarEn(int x, int y) {
	Area srcArea = clips.front();
	Area destArea(xInicial + x, yInicial + y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}

