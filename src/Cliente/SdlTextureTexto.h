#ifndef SDL_TEXTURE_TEXTO_H
#define SDL_TEXTURE_TEXTO_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "SdlTexture.h"
#include "SdlWindow.h"
#include <string>

class SdlTextureTexto : public SdlTexture {
private:
	TTF_Font* font;
	int textWidth;
	int textHeight;
public:
	SdlTextureTexto(const std::string texto, 
              const int size, const SdlWindow& window);
	int renderText(int x, int y) const;
	int getWidth() const;
	int getHeight() const;
	~SdlTextureTexto();

private:
	SDL_Texture* createFromText(const std::string texto);
};

#endif // SDL_TEXTURE_TEXTO_H
