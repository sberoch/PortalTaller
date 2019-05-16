#include "VistaPuerta.h"

VistaPuerta::VistaPuerta(SdlTexture& tex) {
	this->textura = tex;
	for (int i = 0; i < 10; ++i) {
		Area area(1 + 194*i, 2052, 192, 384);
		clips.push_back(area);
	}
	for (int i = 0; i < 9; ++i) {
		Area area(1 + 194*i, 2437, 192, 384);
		clips.push_back(area);
	}
	for (int i = 0; i < 9; ++i) {
		Area area(1553 - i*194, 2437, 192, 384);
		clips.push_back(area);
	}
	for (int i = 0; i < 10; ++i) {
		Area area(1747 - 194*i, 2052, 192, 384);
		clips.push_back(area);
	}
	tamanioHorizontal = 160;
	tamanioVertical = 340;

}

void VistaPuerta::dibujarEn(int x, int y) {}

void VistaPuerta::dibujarAnimacionEn(int x, int y, int frame) {
	Area srcArea = clips.at(frame);
	Area destArea(x, y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}