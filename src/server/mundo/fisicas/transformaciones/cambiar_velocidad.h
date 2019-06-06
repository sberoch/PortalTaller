#ifndef __CAMBIAR_VELOCIDAD_H__
#define __CAMBIAR_VELOCIDAD_H__

#include "transformacion.h"

#include "../movimiento/velocidad.h"

// Forward declaration
class Entidad;

class CambiarVelocidad : public Transformacion {
    private:
    Entidad& entidad_;
    Velocidad velocidad_;

    public:
    CambiarVelocidad(Fisicas& unasFisicas, Entidad& unaEntidad, Velocidad& unaVelocidad);
    virtual ~CambiarVelocidad();
    virtual void aplicar() override;
};

#endif
