#include <memory>

#include "entidad.h"
#include "jugador.h"
#include "disparo_portal.h"

#include "superficie.h"
#include "superficie_acido.h"
#include "superficie_metal.h"

int main(int argc, char const *argv[])
{
    // Lo que sigue es lo mismo a Entidad* jugador = new Jugador();
    std::unique_ptr<Entidad> jugador = std::make_unique<Jugador>();
    std::unique_ptr<Entidad> disparoPortal = std::make_unique<DisparoPortal>();

    std::unique_ptr<Superficie> acido = std::make_unique<SuperficieAcido>();
    std::unique_ptr<Superficie> metal = std::make_unique<SuperficieMetal>();

    jugador->afectarseCon(*metal);
    jugador->afectarseCon(*acido);

    disparoPortal->afectarseCon(*metal);
    disparoPortal->afectarseCon(*acido);
}
