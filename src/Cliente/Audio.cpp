#include "Audio.h"
#include "../Common/Constantes.h"

Audio::Audio() {
	if(SDL_Init(SDL_INIT_AUDIO) < 0) { 
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError()); 
	}
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}

	musicaFondo = Mix_LoadMUS("musica_fondo.mp3");
	if(musicaFondo == NULL) printf("%s\n", Mix_GetError());

	disparo = Mix_LoadWAV("disparo_portal.wav");
	if (disparo == NULL) printf("%s\n", Mix_GetError());
	efectos.insert(std::make_pair(EFECTO_DISPARO, disparo));

	salto = Mix_LoadWAV("salto.wav");
	if (salto == NULL) printf("%s\n", Mix_GetError());
	efectos.insert(std::make_pair(EFECTO_SALTO, salto));

}

void Audio::reproducirMusica() {
	Mix_VolumeMusic(MIX_MAX_VOLUME/10);
	if(Mix_PlayingMusic() == 0) {
		Mix_FadeInMusic(musicaFondo, -1, 3000);
	}
}

void Audio::reproducirEfecto(int idEfecto) {
	Mix_Chunk* efecto = efectos.at(idEfecto);
	Mix_PlayChannel(-1, efecto, 0);
}

Audio::~Audio() {
	Mix_FreeMusic(musicaFondo);
	musicaFondo = NULL;
	for (auto& it : efectos) {
		delete it.second;
	}
	Mix_Quit();
}