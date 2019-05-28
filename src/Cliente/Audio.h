#ifndef AUDIO
#define AUDIO 

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>


class Audio {
private:
	Mix_Music* musicaFondo = NULL;
public:
	Audio();
	~Audio();
	void reproducirMusica();
};

#endif