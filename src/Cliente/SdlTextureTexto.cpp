#include "SdlTextureTexto.h"
#include "SdlException.h"
#include <iostream>

SdlTextureTexto::SdlTextureTexto(const std::string texto, 
              const int size, const SdlWindow& window) :
	SdlTexture(window) { //<-- para renderer
	if (TTF_Init() == -1) 
        throw SdlException("Error al iniciar TTF:", SDL_GetError());

    this->font = TTF_OpenFont("portal.ttf", size);
    if(font == NULL) 
    	throw SdlException("Error al cargar font:", SDL_GetError());
	this->texture = createFromText(texto);
	}

SDL_Texture* SdlTextureTexto::createFromText(const std::string texto) {
    SDL_Color blanco = {255,255,255};
    SDL_Surface* surface = TTF_RenderText_Blended(this->font, texto.c_str(), blanco);
    this->textWidth = surface->w;
    this->textHeight = surface->h;
    if (!surface)
    	throw SdlException("Error con TTF_RenderText_Solid:", SDL_GetError());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(this->renderer, surface);
    if (!texture) {
        throw SdlException("Error al cargar la textura", SDL_GetError());
    }
    SDL_FreeSurface(surface);
    return texture;
}

int SdlTextureTexto::renderText(int x, int y) const {
    SDL_Rect rect = {x, y, textWidth, textHeight};
    return SDL_RenderCopy(this->renderer, this->texture, NULL, &rect);
}

int SdlTextureTexto::getWidth() const {
	return textWidth;
}

int SdlTextureTexto::getHeight() const {
	return textHeight;
}

SdlTextureTexto::~SdlTextureTexto() {
	TTF_CloseFont(font);
	TTF_Quit();
}