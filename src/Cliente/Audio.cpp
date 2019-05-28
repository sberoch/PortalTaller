#include "Audio.h"

Audio::Audio() {
	if(SDL_Init(SDL_INIT_AUDIO) < 0) { 
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError()); 
	}
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}

	musicaFondo = Mix_LoadMUS("musica_fondo.mp3");
	if(musicaFondo == NULL) {
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
	}
}

void Audio::reproducirMusica() {
	Mix_VolumeMusic(MIX_MAX_VOLUME/10);
	if(Mix_PlayingMusic() == 0) {
		Mix_FadeInMusic(musicaFondo, -1, 3000);
	}
}

Audio::~Audio() {
	Mix_FreeMusic(musicaFondo);
	musicaFondo = NULL;
	Mix_Quit();
}