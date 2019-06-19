#include "partida.h"

Partida::Partida() {
    
}

Partida::Partida(Partida&& otra) {

}

Partida& Partida::operator=(Partida&& otra) {
    if (this == &otra) {
        return *this;
    }
    return *this; 
}
