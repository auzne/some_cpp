#include <iostream>

/*
 * bin_to_dec.cpp
 * Pergunta ao usuário um número (limitado em 255) e o converte em binário
 */

//#define COM_BITSET
#define SEM_BITSET

int askNum() {
    std::cout << "Digite um numero entre 0 e 255: ";
    int num{ 0 };
    std::cin >> num;
    if (num >= 0 && num <= 255)
        return num;
    return 0;
}

#ifdef COM_BITSET
#include <bitset>
#include <cmath>

template <int B>
std::bitset<B> getBin(int num) {
    const int max{ static_cast<int>(std::pow(2, B)) - 1 };
    std::bitset<B> bin;

    int currentNum{ max / 2 + 1};
    int currentIndex{ B - 1 };
    while (num > 0) {
        if (num >= currentNum) {
            bin.flip(currentIndex);
            num -= currentNum;
        }
        currentNum /= 2;
        --currentIndex;
    }
    return bin;
}
#endif

#ifdef SEM_BITSET
void printarDiminuirBit(int& num, int bits) {
    if (num >= bits) {
        std::cout << 1;
        num -= bits;
    } else {
        std::cout << 0;
    }
}
#endif

int main() {
    int num{ askNum() };

#ifdef COM_BITSET
    std::cout << getBin<8>(num) << '\n';
#endif

#ifdef SEM_BITSET
    printarDiminuirBit(num, 128);
    printarDiminuirBit(num, 64);
    printarDiminuirBit(num, 32);
    printarDiminuirBit(num, 16);

    std::cout << ' ';

    printarDiminuirBit(num, 8);
    printarDiminuirBit(num, 4);
    printarDiminuirBit(num, 2);
    printarDiminuirBit(num, 1);

    std::cout << '\n';
#endif

    return 0;
}
