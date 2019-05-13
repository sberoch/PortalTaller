#include <SDL2/SDL.h>
#include <iostream>
#include <exception>
#include "SdlWindow.h"
#include "SdlTexture.h"

int main(int argc, char** argv){
    bool quit;
    try {
        SdlWindow window(800, 800);
        window.fill();
        // Usar factory
        SdlTexture im("emisor_receptor.png", window);
        //Emisor
        Area srcArea(0, 0, 196, 191);
        Area destArea(100, 100, 196, 191);
        im.render(srcArea, destArea);

        //Receptor
        Area srcArea2(196, 0, 196, 191);
        Area destArea2(450, 100, 196, 191);
        im.render(srcArea2, destArea2);

        window.render();

        SDL_Event e;
        while (!quit) {
            while(SDL_PollEvent(&e) != 0) {
                if(e.type == SDL_QUIT) {
                    quit = true;
                }
            }
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
