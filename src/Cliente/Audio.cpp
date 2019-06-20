#include "Audio.h"
#include "../Common/Constantes.h"
#include <iostream>

Audio::Audio() {
	if(SDL_Init(SDL_INIT_AUDIO) < 0) { 
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError()); 
	}
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}

	musicaFondo = Mix_LoadMUS("musica_fondo.mp3");
	if(musicaFondo == NULL) printf("%s\n", Mix_GetError());
	Mix_VolumeMusic(MIX_MAX_VOLUME/10);

	disparo = Mix_LoadWAV("disparo_portal.wav");
	if (disparo == NULL) printf("%s\n", Mix_GetError());
	efectos.insert(std::make_pair(EFECTO_DISPARO, disparo));

	salto = Mix_LoadWAV("salto.wav");
	if (salto == NULL) printf("%s\n", Mix_GetError());
	efectos.insert(std::make_pair(EFECTO_SALTO, salto));

	botonMenu = Mix_LoadWAV("boton_menu.wav");
	if (botonMenu == NULL) printf("%s\n", Mix_GetError());
	efectos.insert(std::make_pair(EFECTO_BOTON_CLICK, botonMenu));

	muerte = Mix_LoadWAV("muerte.wav");
	if (muerte == NULL) printf("%s\n", Mix_GetError());
	efectos.insert(std::make_pair(EFECTO_MUERTE, muerte));
	Mix_VolumeChunk(muerte, MIX_MAX_VOLUME/10);

	puerta = Mix_LoadWAV("puerta.wav");
	if (puerta == NULL) printf("%s\n", Mix_GetError());
	efectos.insert(std::make_pair(EFECTO_PUERTA, puerta));
	Mix_VolumeChunk(puerta, MIX_MAX_VOLUME/4);

	boton = Mix_LoadWAV("boton.wav");
	if (boton == NULL) printf("%s\n", Mix_GetError());
	efectos.insert(std::make_pair(EFECTO_BOTON, boton));

}

void Audio::reproducirMusica() {
	if(Mix_PlayingMusic() == 0) {
		std::cout << "Reprodiciendo musica\n";
		Mix_FadeInMusic(musicaFondo, -1, 3000);
	}
}

void Audio::pararMusica() {
	Mix_HaltMusic();
	std::cout << "Deteniendo musica\n";
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