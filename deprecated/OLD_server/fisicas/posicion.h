#ifndef __POSICION_H__
#define __POSICION_H__

class Posicion {
    private:
    float x_;
    float y_;

    public:
    Posicion(float coordenadaX, float coordenadaY);
    float getX();
    float getY();
};

#endif
