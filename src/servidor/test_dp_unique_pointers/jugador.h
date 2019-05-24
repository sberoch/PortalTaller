#ifndef __JUGADOR_H__
#define __JUGADOR_H__

#include "entidad.h"

// Forward declaration
class Superficie;
class SuperficieAcido;

class Jugador : public Entidad {
    public:
    virtual void afectarseCon(Superficie& s) override;
    virtual void afectarseCon(SuperficieAcido& s) override;
};

#endif