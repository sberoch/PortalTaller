#include "sala_de_espera.h"
#include "cliente.h"

void SalaDeEspera::agregar(std::shared_ptr<Cliente> unCliente) {
    clientes_.push_back(unCliente);
    unCliente->iniciar();
}

void SalaDeEspera::cerrar() {
    auto it = std::begin(clientes_);
    while (it != std::end(clientes_)) {
        (*it)->cerrar();
        ++it;                    
    }
}
