#include "server.h"
#include "iostream"

int main(int argc, char const *argv[]) {
    Servidor s(argv[1]);
    try {
        s.correr();
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}
