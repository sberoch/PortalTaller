#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <exception>

#include "SdlWindow.h"
#include "SdlTexture.h"
#include "VistaBloqueMetal.h"
#include "VistaBloquePiedra.h"
#include "VistaAcido.h"
#include "VistaEmisor.h"
#include "VistaReceptor.h"
#include "VistaBoton.h"
#include "VistaPuerta.h"
#include "VistaPiedraMovil.h"
#include "VistaBarreraEnergia.h"
#include "VistaBolaEnergia.h"
#include "VistaPersonaje.h"
#include "VistaBloqueMetalDiagonal.h"
#include "VistaPinTool.h"
#include "VistaTorta.h"

#include "../Common/Constantes.h"

int main(int argc, char** argv){

    bool quit;

    try {
        SdlWindow window(1000, 800);
        window.fill();
        // Usar factory
        SdlTexture emisRecpTex("emisor_receptor.png", window);
        SdlTexture bloqueTex("bloque_metal_diag.png", window);
        SdlTexture personajeTex("chell.png", window);
        SdlTexture miscTex("miscelanea.png", window);
        SdlTexture puertaTex("puertas.png", window);
        SdlTexture efectosTex("efectos.png", window);
        SdlTexture pinToolTex("pin.png", window);
        SdlTexture tortaTex("cake.png", window);

        VistaBloqueMetal bloqueMetal(bloqueTex);
        VistaBloquePiedra bloquePiedra(bloqueTex);
        VistaAcido acido(miscTex);
        VistaEmisor emisor(emisRecpTex);
        VistaReceptor receptor(emisRecpTex);
        VistaBoton boton(miscTex);
        VistaPuerta puerta(puertaTex);
        VistaPiedraMovil piedra(efectosTex);
        VistaBarreraEnergia barreraEnergia(miscTex);
        VistaBolaEnergia bolaEnergia(efectosTex);
        VistaPersonaje personaje(personajeTex);
        VistaBloqueMetalDiagonal diagonal(bloqueTex);
        VistaPinTool pinTool(pinToolTex);
        VistaTorta torta(tortaTex);
        int x, y, x2, y2;

        int posX = 0;
        int posY = 0;

        quit = false;
        bool ctrl = false;
        bool fullscreen = true;
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
                    y2 = -10 + j*100 -posY;
                    bloquePiedra.dibujarEn(x2, y2);
                }           
            }
            //-----------------

            //Crear piso
            bloqueTex.setOpacity(255);
            for (int i = 0; i < 27; i++) {
                x = -400 + i*85 - posX;
                for (int j = 0; j < 5; j++) {
                    y = 500 + j*85 -posY;
                    bloqueMetal.dibujarEn(x,y);
                }           
            }
            //-------------

            acido.dibujarEn(620 - posX, 487 - posY);
            receptor.dibujarEn(195 - posX, 160 - posY);
            emisor.dibujarEn(195 - posX, 245 - posY);
            boton.dibujarEn(960 - posX, 475 - posY);
            puerta.dibujarEn(1130 - posX, 330 - posY);
            piedra.dibujarEn(1300 - posX, 425 - posY);
            piedra.mover(-1,-1);
            barreraEnergia.dibujarEn(1470 - posX, 450 - posY);
            bolaEnergia.dibujarEn(195 - posX, 160 - posY);
            bolaEnergia.mover(4,0);
            personaje.dibujarEn(620, 395);
            torta.dibujarEn(1725 - posX, 435 - posY);

            bloqueMetal.dibujarEn(450 - posX, 415 - posY);
            diagonal.dibujarEn(450 - posX, 330 - posY);
            diagonal.dibujarEn(535 - posX, 415 - posY);
            
            //Eventos
            SDL_PollEvent(&e);
            switch (e.type) {
                case SDL_MOUSEBUTTONDOWN: {
                    if (ctrl) {
                        int x, y;
                        SDL_GetMouseState(&x, &y);
                        pinTool.dibujarEn(x, y);
                    } else {
                        personaje.asignarEstado(ESTADO_DISPARANDO); 
                    }
                    break;
                }
                case SDL_QUIT: quit = true; break;
                case SDL_KEYDOWN: {
                    SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) e;
                    switch (keyEvent.keysym.sym) {
                        case SDLK_LEFT:
                            posX -= 5;
                            personaje.asignarEstado(ESTADO_CORRIENDO);
                            personaje.flipIzquierda();
                            break;
                        case SDLK_RIGHT:
                            posX += 5;
                            personaje.asignarEstado(ESTADO_CORRIENDO);
                            personaje.flipDerecha();
                            break;
                        case SDLK_UP:
                            posY -= 5;
                            break;
                        case SDLK_DOWN:
                            posY += 5;
                            break;
                        case SDLK_q:
                            personaje.asignarEstado(ESTADO_MUERTO);
                            break;
                        case SDLK_LCTRL:
                            ctrl = true;
                            break;
                        case SDLK_F11:
                            if (fullscreen) {
                                window.setFullscreen(false);
                                fullscreen = false;
                            } else {
                                window.setFullscreen(true); 
                                fullscreen = true;
                            } 
                    }
                    break;
                }
                case SDL_KEYUP: {
                    SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) e;
                    if (keyEvent.keysym.sym == SDLK_LCTRL) {
                        ctrl = false;
                    } else {
                        personaje.asignarEstado(ESTADO_IDLE); 
                    }  
                    break;
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
