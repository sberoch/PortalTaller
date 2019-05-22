#include "VistaPinTool.h"

#define CANT_CLIPS 6

VistaPinTool::VistaPinTool(SdlTexture& tex) {
	this->textura = tex;
	for (int i = 0; i < CANT_CLIPS; ++i) {
		Area area(i*300, 0, 300, 465);
		clips.push_back(area);
	}
	tamanioHorizontal = 30;
	tamanioVertical = 45;
}

void VistaPinTool::dibujarEn(int x, int y) {
	Area srcArea = clips.at(floor(frame/16));
	Area destArea(x, y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
	++frame;
	if (frame/16 >= CANT_CLIPS) {
		frame = 0;
	}
}