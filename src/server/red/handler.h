#ifndef __HANDLER_H__
#define __HANDLER_H__

// Forward declaration
class Evento;

class Handler {
    public:
    virtual void manejar(Evento& evento) = 0;
};

#endif
