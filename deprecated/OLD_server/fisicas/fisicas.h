#ifndef __FISICAS_H__
#define __FISICAS_H__

#include <map>
#include <set>
#include <queue>
#include <cstdint>
#include <memory>

#include "Box2D/Box2D.h"

//Forward declaration
class Entidad;
class Terreno;
class BloqueMetalCuadrado;
class Identificable;
class Posicion;
class Direccion;
class Transformacion;

class Fisicas {
    private:
    b2Vec2 gravedad_;
    b2World* mundo_;
    std::map<uint16_t, b2Body*> identificables_;
    std::queue<std::shared_ptr<Transformacion>> transformaciones_;

    public:
    Fisicas();
    explicit Fisicas(b2World* unMundo);
    ~Fisicas();
    void agregar(Identificable& unIdentificable, Posicion& p);
    
    void agregar(Entidad& unaEntidad, Posicion& p);
    void agregarPosta(Entidad& unaEntidad, Posicion& p);
    
    //void agregar(Terreno& unTerreno, Posicion& p);    
    //void agregarPosta(Terreno& unTerreno, Posicion& p);
    void agregar(BloqueMetalCuadrado& b, Posicion& p);
    void agregarPosta(BloqueMetalCuadrado& unTerreno, Posicion& p);
    
    void destruir(Entidad& unaEntidad);
    void destruirPosta(Entidad& unaEntidad);
    
    void teletransportar(Entidad& unaEntidad, Posicion& p, Direccion& d);
    void teletransportarPosta(Entidad& unaEntidad, Posicion& p, Direccion& d);

     void step();
     void aplicarTransformaciones();
    // Deberia ser privado.
    //void quitarElementosDestruidos();
    // ProcesarEventos() que incluya a 
    // quitar destruidos, movimientos, etc
};

#endif
