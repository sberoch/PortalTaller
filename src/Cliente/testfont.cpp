/*#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Texto.h"
#include "SdlWindow.h"
#include <thread>
#include <chrono>

int main(int argc, char const *argv[])
{
	SdlWindow window(1200,750);
	Texto texto("JUGAR", 72, window);

	int i = 0;
	while(i < 600) {
	    window.fill();
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		texto.dibujarEn(800,450);
		window.render();
		i++;
	}
	return 0;
}*/