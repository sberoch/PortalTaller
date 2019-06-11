#include "agregar_terreno.h"

#include "../fisicas.h"

AgregarTerreno::AgregarTerreno(Fisicas& unasFisicas, Terreno& unTerreno, Posicion& unaPosicion) :
    Transformacion(unasFisicas),
    terreno_(unTerreno),
    posicion_(unaPosicion) {
}

void AgregarTerreno::aplicar() {
    fisicas_.agregarPosta(terreno_, posicion_);    
}
