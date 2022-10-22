#include <iostream>

int fatorial(int valor) {
    if (valor <= 1) {
        return 1;
    }
    return fatorial(valor - 1) * valor;
}


int main() {
    std::cout << fatorial(2) << '\n'; // 2
    std::cout << fatorial(3) << '\n'; // 6
    std::cout << fatorial(4) << '\n'; // 24

    return 0;
}
