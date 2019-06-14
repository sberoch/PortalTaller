#ifndef AUDIO
#define AUDIO 

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <map>


class Audio {
private:
	Mix_Music* musicaFondo = NULL;
	Mix_Chunk* disparo = NULL;
	Mix_Chunk* salto = NULL;
	Mix_Chunk* botonMenu = NULL;

	std::map<int, Mix_Chunk*> efectos;
public:
	Audio();
	~Audio();
	void reproducirMusica();
	void pararMusica();
	void reproducirEfecto(int idEfecto);
};

#endif