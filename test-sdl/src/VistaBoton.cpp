#include "VistaBoton.h"

#define CANT_CLIPS 2

VistaBoton::VistaBoton(SdlTexture& tex) {
	this->textura = tex;
	for (int i = 0; i < CANT_CLIPS; ++i) {
		Area area(1, 116 + i*76, 175, 55);
		clips.push_back(area);
	}
	tamanioHorizontal = 80;
	tamanioVertical = 25;

}

void VistaBoton::dibujarEn(int x, int y) {}

void VistaBoton::dibujarAnimacionEn(int x, int y, int frame) {
	Area srcArea = clips.at(frame);
	Area destArea(x, y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}