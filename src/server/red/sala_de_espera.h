#ifndef __SALA_DE_ESPERA_H__
#define __SALA_DE_ESPERA_H__

#include <vector>
#include <memory>

// Forward declaration
class Cliente;

class SalaDeEspera {
    private:
    std::vector<std::shared_ptr<Cliente>> clientes_;

    public:
    void agregar(std::shared_ptr<Cliente> unCliente);
    void cerrar();
};

#endif
