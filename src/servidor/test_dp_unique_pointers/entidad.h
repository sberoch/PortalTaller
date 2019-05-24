#ifndef __ENTIDAD_H__
#define __ENTIDAD_H__

// Forward declaration
class Superficie;
class SuperficieAcido;
class SuperficieMetal;

class Entidad {
    public:
    virtual void afectarseCon(Superficie& s) = 0;
    virtual void afectarseCon(SuperficieAcido& s) = 0;
    virtual void afectarseCon(SuperficieMetal& s);
};

#endif