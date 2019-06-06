#ifndef __ROTACION_H__
#define __ROTACION_H__

class Rotacion {
    private:
    size_t angulo_;

    public:
    Rotacion(size_t unAnguloEnGrados);
    ~Rotacion();
    float anguloRadianes();
    size_t anguloGrados();
};

#endif
