#ifndef __SALA_ESPERA_H__
#define __SALA_ESPERA_H__

#include <vector>
#include <mutex>
#include <memory>

// Forward declaration
class EscuchadorCliente;
class Evento;
class CoordinadorPartidas;

class SalaDeEspera {
    private:
    std::mutex mtx_;
    std::vector<std::shared_ptr<EscuchadorCliente>> clientes_;

    public:
    void agregar(std::shared_ptr<EscuchadorCliente> unCliente);

    void moverClienteAPartida(int uuidCliente, int partidaSeleccionada, CoordinadorPartidas& coordinador);

    void transmitir(Evento& unEvento);

    void transmitir(Evento& unEvento, int destinatario);

    void cerrar();
};

#endif
