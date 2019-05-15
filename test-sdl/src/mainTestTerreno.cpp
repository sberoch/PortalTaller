#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <exception>

#include "SdlWindow.h"
#include "SdlTexture.h"
#include "VistaBloqueMetal.h"
#include "VistaBloquePiedra.h"

#define ESTADO_IDLE 0
#define ESTADO_CORRIENDO 1

std::vector<Area> clips;

void initClips(int estado);

int main(int argc, char** argv){

    bool quit;

    try {
        SdlWindow window(1000, 800);
        window.fill();
        // Usar factory
        SdlTexture bloqueTex("bloque_metal_diag.png", window);
        SdlTexture personaje("chell.png", window);

        VistaBloqueMetal bloqueMetal(bloqueTex);
        VistaBloquePiedra bloquePiedra(bloqueTex);
        int x, y, x2, y2;

        //Chell init
        int frame = 0;
        int posX = 0;
        int posY = 0;
        initClips(ESTADO_CORRIENDO);
        SDL_RendererFlip flip = SDL_FLIP_NONE;


        quit = false;
        SDL_Event e;
        while (!quit) {
            window.fill();

            //Crear fondo
            bloqueTex.setOpacity(100);
            for (int i = 0; i < 27; i++) {
                //un getter del tamaño horizontal
                x2 = -400 + i*100 - floor(posX/2);
                for (int j = 0; j < 7; j++) {
                    //un getter del tamaño vertical
                    y2 = -10 + j*100;
                    bloquePiedra.dibujarEn(x2, y2);
                }           
            }
            //-----------------

            //Crear piso
            bloqueTex.setOpacity(255);
            for (int i = 0; i < 27; i++) {
                x = -400 + i*85 - posX;
                for (int j = 0; j < 5; j++) {
                    y = 500 + j*85;
                    bloqueMetal.dibujarEn(x,y);
                }           
            }
            //-------------

            //Chell
            Area area = clips.at(floor(frame/8));
            Area destAreaPersonaje(400, 296, 195, 204);
            personaje.renderPersonaje(area, destAreaPersonaje, flip);
            ++frame;
            if ((frame/8) >= 7) {
                frame = 0;
            }
            //------------
            
            

            //Eventos
            SDL_PollEvent(&e);
            switch (e.type) {
                case SDL_MOUSEMOTION: break;
                case SDL_QUIT: quit = true; break;
                case SDL_KEYDOWN: {
                    SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) e;
                    switch (keyEvent.keysym.sym) {
                        case SDLK_LEFT:
                            posX -= 5;
                            flip = SDL_FLIP_HORIZONTAL;
                            break;
                        case SDLK_RIGHT:
                            posX += 5;
                            flip = SDL_FLIP_NONE;
                            break;
                        case SDLK_UP:
                            posY -= 5;
                            break;
                        case SDLK_DOWN:
                            posY += 5;
                            break;
                    }
                }
            }
            //---------------
            SDL_Delay(7);
            window.render();
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}

void initClips(int estado) {
    int spritePosEnTextura;
    int cantFrames;
    int anchoTextura;
    switch (estado) {
        case ESTADO_IDLE:
            cantFrames = 7;
            anchoTextura = 105;
            spritePosEnTextura = 2075;
            break;
        case ESTADO_CORRIENDO:
            cantFrames = 8;
            anchoTextura = 195;
            spritePosEnTextura = 4123;
            break;
    }


    for (int i = 0; i < cantFrames; ++i)
    {
        //Esto es solo para corriendo
        Area area(1 + i*anchoTextura, spritePosEnTextura, anchoTextura -1, 200);
        clips.push_back(area);
    }
}