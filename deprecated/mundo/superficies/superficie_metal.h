#ifndef __SUPERFICIE_METAL_H__
#define __SUPERFICIE_METAL_H__

#include "superficie.h"
#include "../fisicas/movimiento/direccion.h"

// Forward declaration
class Fisicas;
class Direccion;

class SuperficieMetal : public Superficie {
    private:
    Direccion direccion_;

    public:
    SuperficieMetal(Fisicas& unasFisicas, Direccion& unaDireccion);
    virtual ~SuperficieMetal();
    virtual void colisionarContra(Colisionable& unColisionable) override;
};

#endif
