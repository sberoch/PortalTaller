#include "VistaPuerta.h"

#define CANT_CLIPS 38

VistaPuerta::VistaPuerta(SdlTexture& tex) {
	frame = 0;
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
	tamanioHorizontal = 85;
	tamanioVertical = 170;

}

void VistaPuerta::dibujarEn(int x, int y) {
	Area srcArea = clips.at(floor(frame/8));
	Area destArea(x, y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
	++frame;
	if (frame/8 >= CANT_CLIPS) {
		frame = 0;
	}
}
