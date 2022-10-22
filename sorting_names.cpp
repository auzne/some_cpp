#include <algorithm>
#include <cstddef>
#include <iostream>
#include <limits>
#include <string>

int qtdeNomes() {
    std::cout << "Quantos nomes devem ser alocados: ";
    int length;
    std::cin >> length;
    return length;
}

void perguntarNomes(std::string* nomes, int length) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int count{ 0 }; count < length; ++count) {
        std::cout << "Nome [" << (count + 1) << "]: ";
        std::getline(std::cin, nomes[count]);
    }
}

void printarNomes(std::string* nomes, int length) {
    std::cout << "Nomes ordenados: " << '\n';
    for (int count{ 0 }; count < length; ++count) {
        std::cout << "Nome [" << (count + 1) << "]: " << nomes[count] << '\n';
    }
}

int main()
{
    int length{ qtdeNomes() };

    auto* nomes{ new std::string[static_cast<std::size_t>(length)]{} };

    perguntarNomes(nomes, length);
    
    std::sort(nomes, nomes + length);

    printarNomes(nomes, length);

    delete[] nomes;
    // nomes = nullptr;
}
