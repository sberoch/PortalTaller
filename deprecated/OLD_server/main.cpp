#include <memory>
#include <iostream>


#include "entidades/entidad.h"
#include "entidades/jugador.h"
#include "entidades/disparo_portal.h"
#include "terrenos/terreno.h"
#include "terrenos/bloque_metal_cuadrado.h"
#include "terrenos/bloque_piedra.h"
#include "fisicas/fisicas.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    Colisionable* jugador = new Jugador();
    Colisionable* disparoPortal = new DisparoPortal();
    Colisionable* bloqueMetalCuadrado = new BloqueMetalCuadrado();    
    Colisionable* bloquePiedra = new BloquePiedra();
        
    disparoPortal->colisionarContra(*bloqueMetalCuadrado);
    bloqueMetalCuadrado->colisionarContra(*disparoPortal);

    Fisicas f;

    f.agregar(*jugador);
    f.agregar(*bloqueMetalCuadrado);

    for (int32 i = 0; i < 2; ++i) {
		f.step();
	}
    
    delete jugador;
    delete disparoPortal;
    delete bloqueMetalCuadrado;
    delete bloquePiedra;
    return 0;
}