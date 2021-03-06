#include "mundo.h"

#include "../server_config.h"

#include "superficies/bloque.h"
#include "superficies/superficie_metal.h"

#include "entidades/jugador.h"

#include "fisicas/formas/forma.h"
#include "fisicas/movimiento/direccion.h"
#include "fisicas/movimiento/posicion.h"
#include "fisicas/movimiento/rotacion.h"

#include "../../Common/Evento.h"

#define NO_ROTADO 0.0f

void Mundo::agregarBloqueMetalCuadrado(Posicion& posicion, Rotacion& r) {
    // Se agrega un bloque de colision
    std::shared_ptr<Bloque> bloque(new Bloque(fisicas_));
    Forma forma(CONFIG.SIZE_BLOQUE_X, CONFIG.SIZE_BLOQUE_Y);
    bloques_[bloque->uuid()] = bloque;
    fisicas_.agregarBloqueRectangular(*bloque, posicion, forma);
    
    // Se agregan sensores de metal, que responden a colisiones
    Forma formaHorizontal(CONFIG.SIZE_SENSOR_METAL_CUADRADO_X,
        CONFIG.SIZE_SENSOR_METAL_CUADRADO_Y);
    Forma formaVertical(CONFIG.SIZE_SENSOR_METAL_CUADRADO_Y,
        CONFIG.SIZE_SENSOR_METAL_CUADRADO_X);

    Posicion posicionArriba = posicion + Posicion(0.0f, CONFIG.SIZE_BLOQUE_Y);
    Direccion direccionArriba(0.0f, 1.0f);
    std::shared_ptr<SuperficieMetal> metalArriba(new SuperficieMetal(fisicas_, direccionArriba));
    bloques_[metalArriba->uuid()] = metalArriba;
    fisicas_.agregarSuperficie(*metalArriba, posicionArriba, formaHorizontal, r);

    Posicion posicionAbajo = posicion + Posicion(0.0f, (-1) * CONFIG.SIZE_BLOQUE_Y);
    Direccion direccionAbajo(0.0f, -1.0f);
    std::shared_ptr<SuperficieMetal> metalAbajo(new SuperficieMetal(fisicas_, direccionAbajo));
    bloques_[metalAbajo->uuid()] = metalAbajo;
    fisicas_.agregarSuperficie(*metalAbajo, posicionAbajo, formaHorizontal, r);

    Posicion posicionIzquierda = posicion + Posicion((-1) * CONFIG.SIZE_BLOQUE_X, 0.0f);
    Direccion direccionIzquierda(-1.0f, 0.0f);
    std::shared_ptr<SuperficieMetal> metalIzquierda(new SuperficieMetal(fisicas_, direccionIzquierda));
    bloques_[metalIzquierda->uuid()] = metalIzquierda;
    fisicas_.agregarSuperficie(*metalIzquierda, posicionIzquierda, formaVertical, r);

    Posicion posicionDerecha = posicion + Posicion(CONFIG.SIZE_BLOQUE_X, 0.0f);
    Direccion direccionDerecha(1.0f, 0.0f);
    std::shared_ptr<SuperficieMetal> metalDerecha(new SuperficieMetal(fisicas_, direccionDerecha));
    bloques_[metalDerecha->uuid()] = metalDerecha;
    fisicas_.agregarSuperficie(*metalDerecha, posicionDerecha, formaVertical, r);
}

void Mundo::agregarBloqueMetalTriangular(Posicion& posicion, Rotacion& r) {
    // Se agrega un bloque de colision
    std::shared_ptr<Bloque> bloque(new Bloque(fisicas_));
    Forma forma(CONFIG.SIZE_BLOQUE_X, CONFIG.SIZE_BLOQUE_Y);
    bloques_[bloque->uuid()] = bloque;
    fisicas_.agregarBloqueTriangular(*bloque, posicion, forma, r);
    
    Forma formaHorizontal(CONFIG.SIZE_SENSOR_METAL_CUADRADO_X,
        CONFIG.SIZE_SENSOR_METAL_CUADRADO_Y);
    Forma formaVertical(CONFIG.SIZE_SENSOR_METAL_CUADRADO_Y,
        CONFIG.SIZE_SENSOR_METAL_CUADRADO_X);
    Forma formaDiagonal(CONFIG.SIZE_SENSOR_METAL_DIAGONAL_X,
        CONFIG.SIZE_SENSOR_METAL_DIAGONAL_Y);

    Posicion posicionArriba = posicion + Posicion(0.0f, 0.0f + CONFIG.SIZE_BLOQUE_Y);
    Posicion posicionAbajo = posicion + Posicion(0.0f, -1*CONFIG.SIZE_BLOQUE_Y);
    Posicion posicionIzquierda = posicion + Posicion(-1*CONFIG.SIZE_BLOQUE_Y, 0.0f);
    Posicion posicionDerecha = posicion + Posicion(CONFIG.SIZE_BLOQUE_Y, 0.0f);

    Direccion direccionArriba(0.0f, 1.0f);
    Direccion direccionAbajo(0.0f, -1.0f);
    Direccion direccionIzquierda(-1.0f, 0.0f);
    Direccion direccionDerecha(-1.0f, 0.0f);

    Rotacion no(0);
    
    if (r.anguloGrados() == 0) { 
        std::shared_ptr<SuperficieMetal> metalAbajo(new SuperficieMetal(fisicas_, direccionAbajo));
        bloques_[metalAbajo->uuid()] = metalAbajo;
        fisicas_.agregarSuperficie(*metalAbajo, posicionAbajo, formaHorizontal, no);

        std::shared_ptr<SuperficieMetal> metalIzquierda(new SuperficieMetal(fisicas_, direccionIzquierda));
        bloques_[metalIzquierda->uuid()] = metalIzquierda;
        fisicas_.agregarSuperficie(*metalIzquierda, posicionIzquierda, formaVertical, no);

        std::shared_ptr<SuperficieMetal> metalDiagonal(new SuperficieMetal(fisicas_, direccionArriba));
        bloques_[metalDiagonal->uuid()] = metalDiagonal;
        Rotacion delta(r.anguloGrados() + 135);
        fisicas_.agregarSuperficie(*metalDiagonal, posicion, formaDiagonal, delta);

    } else if (r.anguloGrados() == 90) {
        std::shared_ptr<SuperficieMetal> metalAbajo(new SuperficieMetal(fisicas_, direccionAbajo));
        bloques_[metalAbajo->uuid()] = metalAbajo;
        fisicas_.agregarSuperficie(*metalAbajo, posicionAbajo, formaHorizontal, no);

        std::shared_ptr<SuperficieMetal> metalDerecha(new SuperficieMetal(fisicas_, direccionDerecha));
        bloques_[metalDerecha->uuid()] = metalDerecha;
        fisicas_.agregarSuperficie(*metalDerecha, posicionDerecha, formaVertical, no);

        std::shared_ptr<SuperficieMetal> metalDiagonal(new SuperficieMetal(fisicas_, direccionArriba));
        bloques_[metalDiagonal->uuid()] = metalDiagonal;
        Rotacion delta(r.anguloGrados() + 135);
        fisicas_.agregarSuperficie(*metalDiagonal, posicion, formaDiagonal, delta);

    } else if (r.anguloGrados() == 180) {
        std::shared_ptr<SuperficieMetal> metalArriba(new SuperficieMetal(fisicas_, direccionArriba));
        bloques_[metalArriba->uuid()] = metalArriba;
        fisicas_.agregarSuperficie(*metalArriba, posicionArriba, formaHorizontal, no);

        std::shared_ptr<SuperficieMetal> metalDerecha(new SuperficieMetal(fisicas_, direccionDerecha));
        bloques_[metalDerecha->uuid()] = metalDerecha;
        fisicas_.agregarSuperficie(*metalDerecha, posicionDerecha, formaVertical, no);

        std::shared_ptr<SuperficieMetal> metalDiagonal(new SuperficieMetal(fisicas_, direccionAbajo));
        bloques_[metalDiagonal->uuid()] = metalDiagonal;
        Rotacion delta(r.anguloGrados() + 135);
        fisicas_.agregarSuperficie(*metalDiagonal, posicion, formaDiagonal, delta);

    } else if (r.anguloGrados() == 270) {
        std::shared_ptr<SuperficieMetal> metalArriba(new SuperficieMetal(fisicas_, direccionArriba));
        bloques_[metalArriba->uuid()] = metalArriba;
        fisicas_.agregarSuperficie(*metalArriba, posicionArriba, formaHorizontal, no);

        std::shared_ptr<SuperficieMetal> metalIzquierda(new SuperficieMetal(fisicas_, direccionIzquierda));
        bloques_[metalIzquierda->uuid()] = metalIzquierda;
        fisicas_.agregarSuperficie(*metalIzquierda, posicionIzquierda, formaVertical, no);

        std::shared_ptr<SuperficieMetal> metalDiagonal(new SuperficieMetal(fisicas_, direccionAbajo));
        bloques_[metalDiagonal->uuid()] = metalDiagonal;
        Rotacion delta(r.anguloGrados() + 135);
        fisicas_.agregarSuperficie(*metalDiagonal, posicion, formaDiagonal, delta);
    }
}

void Mundo::agregarJugador(Posicion& posicion) {
    std::shared_ptr<Jugador> jugador(new Jugador(fisicas_));
    Forma formaJugador(CONFIG.SIZE_JUGADOR_X, CONFIG.SIZE_JUGADOR_Y);
    entidades_[jugador->uuid()] = jugador;
    fisicas_.agregarEntidad(*jugador, posicion, formaJugador);
}

void Mundo::moverJugador(int uuidJugador, Velocidad& v) {
    fisicas_.cambiarVelocidad(*entidades_[uuidJugador], v);
}

void Mundo::step() {
    fisicas_.step();
}

void Mundo::manejar(Evento& evento) {
    evento.actualizar(*this);
}

void Mundo::manejar(EventoPortalAzul& evento) {
    //Calcular x,y y angulo con la direccion
    //Chequear si hay uno antes, sacarlo en ese caso
    //Guardar la posicion en la lista de objetos del juego para poder borrar despues
    //Enviar la creacion del portal azul
}

void Mundo::manejar(EventoPortalNaranja& evento) {
    //Calcular x,y y angulo con la direccion
    //Chequear si hay uno antes, sacarlo en ese caso
    //Guardar la posicion en la lista de objetos del juego para poder borrar despues
    //Enviar la creacion del portal naranja
}

void Mundo::manejar(EventoResetPortales& evento) {
    //Sacar los dos portales
    //Enviar evento eliminar
}

void Mundo::manejar(EventoSalto& evento) {
    //Si esta en el piso, mover arriba
    //Si esta en el aire nada
    //Enviar mover y cambio estado saltando (si estaba en el piso)
}

void Mundo::manejar(EventoSuicidio& evento) {
    //Cambio de estado a muerto
    //Sacarlo del juego
}

void Mundo::manejar(EventoCorrer& evento) {
    //Si esta en el piso
        //Mover en la direccion correspondiente
        //Cambio de estado a corriendo
        //Flipear si corresponde
    //Si esta en el aire
        //Mover
        //Flipear si corresponde
}

void Mundo::manejar(EventoDejarDeMoverse& evento) {
    //Si esta en el piso
        //Evento cambio de estado a idle
    //Si esta en el aire
        //Nada
}

void Mundo::manejar(EventoPinTool& evento) {
    //Enviar crear item con id del pintool segun el id del player
    //Guardarse la posicion en lista de objetos del juego para borrar luego de un tiempo
}
