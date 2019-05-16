#include "VistaPiedraMovil.h"

#include <stdlib.h>     
#include <time.h>  

VistaPiedraMovil::VistaPiedraMovil(SdlTexture& tex) {
	this->textura = tex;
	srand(time(NULL));
	int nroPiedra = rand() % 8;
	srcArea.set(1 + nroPiedra*86, 4513, 85, 83);
	tamanioHorizontal = 85;
	tamanioVertical = 85;
}

void VistaPiedraMovil::dibujarEn(int x, int y) {
	Area destArea(x, y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}
