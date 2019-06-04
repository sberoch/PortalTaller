#ifndef __COLISIONABLE_H__
#define __COLISIONABLE_H__

#include "identificable.h"

// Forward declaration
class Jugador;
//class DisparoPortal;
//class Roca;
//class DisparoPin;
//class BolaEnergia;

//class BloqueEmisor;
//class BloqueReceptor;
//class BloqueMetalCuadrado;
//class BloqueMetalTriangular;
//class BloquePiedra;
//class BarreraEnergia;
//class SuperficieBoton;
//class SuperficieCompuerta;
//class Portal;

class Fisicas;

class Colisionable : public Identificable {
    public:
    virtual void colisionarContra(Colisionable& otro) = 0;
    
    virtual void colisionarContra(Jugador& j);
    //virtual void colisionarContra(DisparoPortal& d);
    //virtual void colisionarContra(Roca& r);
    //virtual void colisionarContra(DisparoPin& d);
    //virtual void colisionarContra(BolaEnergia& b);

    //virtual void colisionarContra(BloqueEmisor& b);
    //virtual void colisionarContra(BloqueReceptor& b);
    //virtual void colisionarContra(BloqueMetalCuadrado& b);
    //virtual void colisionarContra(BloqueMetalTriangular& b);
    //virtual void colisionarContra(BloquePiedra& b);
    //virtual void colisionarContra(BarreraEnergia& b);
    //virtual void colisionarContra(SuperficieBoton& s);
    //virtual void colisionarContra(SuperficieCompuerta& s);
    //virtual void colisionarContra(Portal& p);

    Colisionable(Fisicas& unasFisicas);
    virtual ~Colisionable();

    protected:
    Fisicas& fisicas_;
};

#endif
