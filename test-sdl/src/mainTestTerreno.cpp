#include <SDL2/SDL.h>
#include <iostream>
#include <exception>
#include "SdlWindow.h"
#include "SdlTexture.h"

int main(int argc, char** argv){
    bool quit;
    try {
        SdlWindow window(1000, 800);
        window.fill();
        // Usar factory
        SdlTexture im("bloque_metal_diag.png", window);

        //Bloque metal completo
        Area srcArea(2, 213, 191, 191);
        Area srcArea2(2, 0, 191, 191);
        int x;
        int y;
        int x2;
        int y2;
        
        quit = false;
        SDL_Event e;
        while (!quit) {
            window.fill();

            //Crear fondo
            im.setOpacity(100);
            for (int i = 0; i < 12; i++) {
                x2 = -10 + i*85;
                for (int j = 0; j < 7; j++) {
                    y2 = -10 + j*85;
                    Area destArea(x2, y2, 85, 85);
                    im.render(srcArea2, destArea);
                }           
            }

            //-----------------
            //Crear piso
            im.setOpacity(255);
            for (int i = 0; i < 12; i++) {
                x = -10 + i*85;
                for (int j = 0; j < 5; j++) {
                    y = 500 + j*85;
                    Area destArea(x, y, 85, 85);
                    im.render(srcArea, destArea);
                }           
            }
            //-------------
            
            SDL_WaitEvent(&e);
            if (e.type == SDL_MOUSEMOTION) {}
            if (e.type ==  SDL_QUIT) {
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