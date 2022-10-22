#include <iostream>

/*
 * meia_piramide.cpp
 * 
 * Imprime uma meia pirâmide de números
 * Na linha eles são somados por 2
 * Na quebra de linha o contador é somado em 3
 */

int main() {
    std::cout << "Quantas repeticoes: ";
    int total{};
    std::cin >> total;

    int valorAtual{ 1 };
    for (int i{ 1 }; i <= total; ++i) {
        /* imprime o valor atual com um 0 à direita caso necessário */
        if (valorAtual < 10) std::cout << 0;
        std::cout << valorAtual << ' ';

        for (int j{ 1 }; j < i; ++j) {
            /* soma 2 ao valor atual */
            valorAtual += 2;
            /* imprime o valor atual com um 0 à direita caso necessário */
            if (valorAtual < 10) std::cout << 0;
            std::cout << valorAtual << ' ';
        }
        
        /* quebra a linha e soma 3 */
        std::cout << '\n';
        valorAtual += 3;
    }

    return 0;
}
