#ifndef __AGREGAR_ENTIDAD_H__
#define __AGREGAR_ENTIDAD_H__

#include "transformacion.h"

#include "../movimiento/posicion.h"
#include "../formas/forma.h"

// Forward Declaration
class Entidad;

class AgregarEntidad : public Transformacion {
    private:
    Entidad& entidad_;
    Posicion posicion_;
    Forma forma_;

    public:
    AgregarEntidad(Fisicas& unasFisicas, Entidad& unaEntidad, Posicion& unaPosicion, Forma& unaForma);
    virtual ~AgregarEntidad();
    virtual void aplicar() override;
};

#endif
