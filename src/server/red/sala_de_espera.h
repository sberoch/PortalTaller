#ifndef __SALA_ESPERA_H__
#define __SALA_ESPERA_H__

#include <vector>
#include <memory>

// Forward declaration
class Cliente;
class Evento;
class CoordinadorPartidas;

class SalaDeEspera {
    private:
    std::vector<std::shared_ptr<Cliente>> clientes_;

    public:
    void agregar(std::shared_ptr<Cliente> unCliente);

    void moverClienteAPartida(int uuidCliente, int partidaSeleccionada, CoordinadorPartidas& coordinador);

    void transmitir(Evento& unEvento);

    void transmitir(Evento& unEvento, int destinatario);

    void cerrar();
};

#endif
