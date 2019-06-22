#ifndef __RETRANSMISOR_H__
#define __RETRANSMISOR_H__

#include "../../Common/Thread.h"
#include "../../Common/cola_bloqueante.h"

// Forward declaration
class Evento;

class Retransmisor : public Thread {
    private:
    bool& seguirCorriendo_;
    ColaBloqueante<std::shared_ptr<Evento>>& origen_;
    ColaBloqueante<std::shared_ptr<Evento>>& destino_;

    public:
    Retransmisor(bool& seguirCorriendo,
        ColaBloqueante<std::shared_ptr<Evento>>& origen,
        ColaBloqueante<std::shared_ptr<Evento>>& destino);
    virtual void ejecutar() override;
    virtual void cerrar() override;
};

#endif
