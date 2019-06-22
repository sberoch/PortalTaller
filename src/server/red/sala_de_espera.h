#ifndef __SALA_DE_ESPERA_H__
#define __SALA_DE_ESPERA_H__

#include <vector>
#include <memory>

#include "../../Common/cola_bloqueante.h"
#include "../../Common/Evento.h"
#include "../../Common/handler.h"
#include "../../Common/Thread.h"

// Forward declaration
class Cliente;

class SalaDeEspera : public Thread, public Handler {
    private:
    bool& seguirCorriendo_;
    std::vector<std::shared_ptr<Cliente>> clientes_;
    ColaBloqueante<std::shared_ptr<Evento>> eventosEntrantes_;

    public:
    SalaDeEspera(bool& seguirCorriendo);
    void agregar(std::shared_ptr<Cliente> unCliente);
    virtual void ejecutar() override;
    virtual void cerrar() override;
    
    virtual void manejar(Evento& evento) override;
    virtual void manejar(EventoCrearPartida& evento) override;
    virtual void manejar(EventoSeleccionarPartida& evento) override;
    virtual void manejar(EventoUnirseAPartida& evento) override;
    virtual void manejar(EventoIniciarPartida& evento) override;
};

#endif
