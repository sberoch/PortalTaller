#ifndef __TRANSFORMACION_H__
#define __TRANSFORMACION_H__

// Forward declaration
class Fisicas;

class Transformacion {
    protected:
    Fisicas& fisicas_;

    public:
    Transformacion(Fisicas& unasFisicas);
    virtual ~Transformacion();
    virtual void aplicar() = 0;    
};

#endif
