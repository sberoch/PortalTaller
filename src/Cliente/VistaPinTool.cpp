#include "VistaPinTool.h"

#define CANT_CLIPS 6

VistaPinTool::VistaPinTool(SdlTexture& tex, int playerId) {
	this->textura = tex;
	this->frame = 0;
	color = playerId - 1;
	for (int i = 0; i < CANT_CLIPS; ++i) {
		Area area(i*300, 50 + color*450, 300, 450);
		clips.push_back(area);
	}
	tamanioHorizontal = 30;
	tamanioVertical = 45;
}

void VistaPinTool::dibujarEn(int x, int y) {
	Area srcArea = clips.at(floor(frame/8));
	Area destArea(xInicial + x - tamanioHorizontal/2,
				  yInicial + y - tamanioVertical/2, 
				  tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
	++frame;
	if (frame/8 >= CANT_CLIPS) {
		frame = 0;
	}
}
