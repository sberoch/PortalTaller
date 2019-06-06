#ifndef __VELOCIDAD_H__
#define __VELOCIDAD_H__

class Velocidad {
    private:
    float coordenadaX_;
    float coordenadaY_;

    public:
    Velocidad(float x, float y);
    ~Velocidad();
    float x();
    float y();
};

#endif