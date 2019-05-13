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
        int x = 100;
        int y = 100;

        //Receptor
        Area srcArea2(196, 0, 196, 191);
        int x2 = 400;
        int y2 = 100;

        SDL_Event e;
        while (!quit) {
            Area destArea(x, y, 196, 191);
            Area destArea2(x2,y2, 196, 191);
            window.fill();
            im.render(srcArea, destArea);
            im.render(srcArea2, destArea2);
            SDL_WaitEvent(&e);
            switch (e.type) {
                case SDL_KEYDOWN: {
                    SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) e;
                    switch (keyEvent.keysym.sym) {
                        case SDLK_LEFT:
                                x -= 30;
                                break;
                            case SDLK_RIGHT:
                                x += 30;
                                break;
                            case SDLK_UP:
                                y -= 30;
                                break;
                            case SDLK_DOWN:
                                y += 30;
                                break;
                            }
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    SDL_GetMouseState(&x2, &y2);
                    break;
                case SDL_QUIT:
                    quit = true;
                    break;

            }
            window.render();
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
