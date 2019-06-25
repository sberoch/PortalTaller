#ifndef __MUNDO_H__
#define __MUNDO_H__

#include <map>
#include <queue>

#include "fisicas/fisicas.h"
#include "../../Common/handler.h"

// Forward declaration
class Colisionable;
class Posicion;
class Velocidad;
class Rotacion;

class Evento;
class EventoPortalAzul;
class EventoPortalNaranja;
class EventoDejarDeMoverse;
class EventoResetPortales;
class EventoSuicidio;
class EventoSalto;
class EventoCorrer;
class EventoPinTool;

class Mundo : public Handler {
    private:
    Fisicas fisicas_;
    std::map<int, std::shared_ptr<Colisionable>> bloques_;
    std::map<int, std::shared_ptr<Entidad>> entidades_;

    public:
    void agregarBloqueMetalCuadrado(Posicion& posicion, Rotacion& r);
    void agregarBloqueMetalTriangular(Posicion& posicion, Rotacion& r);
    void agregarJugador(Posicion& posicion);
    void moverJugador(int uuidDelJugador, Velocidad& v);
    void step();
    
    virtual void manejar(Evento& evento) override;
    virtual void manejar(EventoPortalAzul& evento) override;
    virtual void manejar(EventoPortalNaranja& evento) override;
    virtual void manejar(EventoResetPortales& evento) override;
    virtual void manejar(EventoSalto& evento) override;
    virtual void manejar(EventoSuicidio& evento) override;
    virtual void manejar(EventoCorrer& evento) override;
    virtual void manejar(EventoDejarDeMoverse& evento) override;
    virtual void manejar(EventoPinTool& evento) override;

    // Testing
    Fisicas* getFisicas() {return &fisicas_;}
};

#endif
