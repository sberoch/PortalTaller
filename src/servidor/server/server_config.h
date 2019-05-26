#ifndef __SERVER_CONFIG_H__
#define __SERVER_CONFIG_H__

struct Config {
    float GRAVEDAD_X = 0.0f;
    float GRAVEDAD_Y = -10.0f;
    float TIME_STEP = 1.0f / 30.0f;
	int VELOCITY_ITERATIONS = 6;
	int POSITION_ITERATIONS = 2;
};

extern Config CONFIG;

#endif
