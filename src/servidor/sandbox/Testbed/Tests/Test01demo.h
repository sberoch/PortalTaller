#ifndef FOOTEST_H
#define FOOTEST_H

#include "../../../server/fisicas/fisicas.cpp"

#include "../../../server/entidades/entidad.cpp"
#include "../../../server/entidades/colisionable.cpp"
#include "../../../server/entidades/identificable.cpp"
#include "../../../server/entidades/jugador.cpp"
#include "../../../server/entidades/disparo_portal.cpp"
#include "../../../server/terrenos/terreno.cpp"
#include "../../../server/terrenos/bloque_metal_cuadrado.cpp"
#include "../../../server/terrenos/bloque_piedra.cpp"

class Test01demo : public Test {
        public:
        Test01demo() {
            Fisicas f(m_world);
            Colisionable* jugador = new Jugador();
            Colisionable* disparoPortal = new DisparoPortal();
            Colisionable* bloqueMetalCuadrado = new BloqueMetalCuadrado();    
            Colisionable* bloquePiedra = new BloquePiedra();
        
            disparoPortal->colisionarContra(*bloqueMetalCuadrado);
            bloqueMetalCuadrado->colisionarContra(*disparoPortal);

            f.agregar(*jugador);
            f.agregar(*bloqueMetalCuadrado);
    
        } //do nothing, no scene yet
    
        void Step(Settings* settings)
        {
            //run the default physics and rendering
            Test::Step(settings); 
    
            //show some text in the main screen
            //m_debugDraw.DrawString(5, m_textLine, "Now we have a foo test");
            //m_textLine += 15;
        }
    
        static Test* Create()
        {
            return new Test01demo;
        }
    };
  
#endif