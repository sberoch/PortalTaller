#ifndef __SERVER_CONFIG_H__
#define __SERVER_CONFIG_H__

struct Config {
    /* CONSTANTES RELACIONADAS A LA RED */
    int MAX_EN_ESPERA = 20;
    int MAX_CANTIDAD_PARTIDAS = 4;
    /* FIN CONSTANTES RELACIONADAS A LA RED */
    
    /* CONSTANTES DE SIMULACION*/    
    float GRAVEDAD_X = 0.0f;
    float GRAVEDAD_Y = -10.0f;
    float TIME_STEP = 1.0f / 30.0f;
	int VELOCITY_ITERATIONS = 15;
	int POSITION_ITERATIONS = 10;
    /* FIN CONSTANTES DE SIMULACION*/

    /* TAMAÑOS */
    /* 
    /* Tener en cuenta que todos los tamaños definidos son
    /* refiriéndose a las hitboxes, por lo que están pensados
    /* para mejorar la experiencia de juego
    */
    float SIZE_SENSOR_METAL_CUADRADO_X = 0.3f;
    float SIZE_SENSOR_METAL_CUADRADO_Y = 0.2f;

    float SIZE_SENSOR_METAL_DIAGONAL_X = SIZE_SENSOR_METAL_CUADRADO_X * 1.4142f;
    float SIZE_SENSOR_METAL_DIAGONAL_Y = SIZE_SENSOR_METAL_CUADRADO_Y;
    
    float SIZE_PORTAL_X = 0.05f;
    float SIZE_PORTAL_Y = 0.25f;
    
    float SIZE_BLOQUE_X = 1.0f;
    float SIZE_BLOQUE_Y = 1.0f;

    float SIZE_BOTON_X = 0.8f;
    float SIZE_BOTON_Y = 0.1f;

    float SIZE_JUGADOR_X = 0.25f;
    float SIZE_JUGADOR_Y = 0.375f;

    float SIZE_RADIO_BOLA_ENERGIA = 0.5f;

    float SIZE_RADIO_DISPARO_PIN = 0.025f;

    float SIZE_RADIO_DISPARO_PORTAL = 0.1f;

    float SIZE_RADIO_ROCA = 0.35f;
    /* FIN TAMAÑOS */

    /* DENSIDADES */
    float DENSIDAD_DEFAULT = 1.0f;
    float DENSIDAD_BLOQUE = DENSIDAD_DEFAULT;
    float DENSIDAD_JUGADOR = DENSIDAD_DEFAULT;
    float DENSIDAD_BOLA_ENERGIA = DENSIDAD_DEFAULT;
    float DENSIDAD_DISPARO_PIN = DENSIDAD_DEFAULT;
    float DENSIDAD_DISPARO_PORTAL = DENSIDAD_DEFAULT;
    float DENSIDAD_ROCA = DENSIDAD_DEFAULT;    
    /* FIN DENSIDADES*/

    /* ROZAMIENTOS */
    float ROZAMIENTO_SUPERFICIE = 0.0f;
    /* FIN ROZAMIENTOS */

};

extern Config CONFIG;

#endif
