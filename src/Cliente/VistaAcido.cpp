#include "VistaAcido.h"

#define CANT_CLIPS 8

VistaAcido::VistaAcido(SdlTexture& tex) {
	this->textura = tex;
	for (int i = 0; i < CANT_CLIPS; ++i) {
		Area area(i*301, 1545, 301, 60);
		clips.push_back(area);
	}
	tamanioHorizontal = 150;
	tamanioVertical = 30;

}

void VistaAcido::dibujarEn(int x, int y) {}

void VistaAcido::dibujarAnimacionEn(int x, int y, int frame) {
	Area srcArea = clips.at(frame);
	Area destArea(x, y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}