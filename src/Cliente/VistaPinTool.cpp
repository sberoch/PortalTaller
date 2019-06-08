#include "VistaPinTool.h"

#define CANT_CLIPS 6

VistaPinTool::VistaPinTool(SdlTexture& tex) {
	this->textura = tex;
	this->frame = 0;
	for (int i = 0; i < CANT_CLIPS; ++i) {
		Area area(i*300, 50 + color*300, 300, 450);
		clips.push_back(area);
	}
	tamanioHorizontal = 30;
	tamanioVertical = 45;
}

void VistaPinTool::dibujarEn(int x, int y) {
	Area srcArea = clips.at(floor(frame/8));
	Area destArea(xInicial + x, yInicial + y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
	++frame;
	if (frame/8 >= CANT_CLIPS) {
		frame = 0;
	}
}

void VistaPinTool::asignarColorSegunPlayer(int playerId) {
	color = playerId - 1;
}