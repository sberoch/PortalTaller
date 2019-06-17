#include "sala.h"

Sala::Sala() {
    
}

Sala::Sala(Sala&& otra) {

}

Sala& Sala::operator=(Sala&& otra) {
    if (this == &otra) {
        return *this;
    }
    return *this; 
}
