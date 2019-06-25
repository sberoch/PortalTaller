#ifndef __DESTRUIR_ENTIDAD_H__
#define __DESTRUIR_ENTIDAD_H__

#include "transformacion.h"

// Forward declaration
class Entidad;

class DestruirEntidad : public Transformacion {
    private:
    Entidad& entidad_;

    public:
    DestruirEntidad(Fisicas& unasFisicas, Entidad& unaEntidad);
    virtual void aplicar() override;
};

#endif
