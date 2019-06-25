#ifndef __FORMA_H__
#define __FORMA_H__

class Forma {
    private:
    float ancho_;
    float alto_;
    float rotacion_;

    public:
    Forma(float unAncho, float unAlto, float unaRotacion);
    float ancho();
    float alto();
    float rotacion();
};

#endif
