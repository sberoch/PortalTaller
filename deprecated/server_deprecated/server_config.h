#ifndef __SERVER_CONFIG_H__
#define __SERVER_CONFIG_H__

struct Config {
    float GRAVEDAD_X = 0.0f;
    float GRAVEDAD_Y = -10.0f;
    float TIME_STEP = 1.0f / 30.0f;
	int VELOCITY_ITERATIONS = 10;
	int POSITION_ITERATIONS = 10;

    float DENSIDAD_DEFAULT = 1.0f;

    /* TAMANIOS */
    /* 
    /* Tener en cuenta que todos los tamaños definidos son
    /* refiriéndose a las hitboxes, por lo que están pensados
    /* para mejorar la experiencia de juego
    */
    float SIZE_PORTAL_X = 0.05f;
    float SIZE_PORTAL_Y = 0.25f;
    float SIZE_BLOQUE_DEFAULT_X = 1.0f;
    float SIZE_BLOQUE_DEFAULT_Y = 1.0f;
    float SIZE_BOTON_X = 0.8f;
    float SIZE_BOTON_Y = 0.1f;
    float SIZE_JUGADOR_X = 0.5f;
    float SIZE_JUGADOR_Y = 0.75f;
    float SIZE_RADIO_BOLA_ENERGIA = 0.5f;
    float SIZE_RADIO_DISPARO_PIN = 0.025f;
    float SIZE_RADIO_DISPARO_PORTAL = 0.1f;
    float SIZE_RADIO_ROCA = 0.35f;
    /* FIN_TAMANIOS */

};

Config CONFIG;

#endif
