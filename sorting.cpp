#include <iostream>
#include <iterator> // std::size()
//#include <utility> // std::swap() >= C++11
#include <string_view> // std::swap() >= C++17
#include <algorithm> // std::sort()

//#define SORTING_1 // std::sort()
//#define SORTING_2 // normal sorting
#define SORTING_3 // dinam sorting com função
//#define BUBBLE_SORT


/*
 * sorting.cpp
 * Alguns algoritmos de sorting
 */

void printArray(int *array, int length) {
    for (int i{ 0 }; i < length; ++i)
        std::cout << array[i] << ' ';

    std::cout << '\n';
}

#ifdef SORTING_3

bool ascending(int x, int y) {
    return x > y;
}

bool descending(int x, int y) {
    return x < y;
}

bool evensFirst(int x, int y)
{
    // if x is even and y is odd, x goes first (no swap needed)
    if ((x % 2 == 0) && !(y % 2 == 0))
        return false;

    // if x is odd and y is even, y goes first (swap needed)
    if (!(x % 2 == 0) && (y % 2 == 0))
        return true;

    // otherwise sort in ascending order
    return ascending(x, y);
}

void selectionSorting(int *array, int length, bool(*compFunc)(int, int)) {
    for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex) {
        int bestIndex{ startIndex };

        for (int currentIndex{ bestIndex + 1 }; currentIndex < length; ++currentIndex) {
            if (compFunc(array[bestIndex], array[currentIndex]))
                bestIndex = currentIndex;
        }

        std::swap(array[startIndex], array[bestIndex]);
    }
}

#endif

int main()
{
#ifdef SORTING_1
    // com std::sort()
    int arrayDois[]{ 90,30,20,50,10,70 };

    std::sort(std::begin(arrayDois), std::end(arrayDois));

    for (int i{ 0 }; i < static_cast<int>(std::size(arrayDois)); ++i)
        std::cout << arrayDois[i] << ' ';
#endif

#ifdef SORTING_2
    // sem std::sort()
    int array[]{ 50, 30, 10, 60, 20, 40 };
    constexpr int length{ std::size(array) };

    for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex) {
        int smallestIndex{ startIndex };

        for (int currentIndex{ smallestIndex + 1 }; currentIndex < length; ++currentIndex) {
            if (array[currentIndex] < array[smallestIndex])
                smallestIndex = currentIndex;
        }

        std::swap(array[startIndex], array[smallestIndex]);
    }

    printArray(array, length);
#endif

#ifdef SORTING_3
    //int array[]{ 50, 30, 10, 60, 20, 40 };
    int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    constexpr int length{ std::size(array) };

    selectionSorting(array, length, ascending);
    printArray(array, length);

    selectionSorting(array, length, descending);
    printArray(array, length);

    selectionSorting(array, length, evensFirst);
    printArray(array, length);
#endif

#ifdef BUBBLE_SORT

    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int length{ std::size(array) };

    for (int i{ 0 }; i < length - 1; ++i) {

        int endOfArray{ length - i };
        bool swapped{ false };

        for (int initialIndex{ 0 }; initialIndex < endOfArray - 1; ++initialIndex) {
            int nextIndex{ initialIndex + 1 };
            if (array[initialIndex] > array[nextIndex]) {
                std::swap(array[initialIndex], array[nextIndex]);
                swapped = true;
            }
        }

        if (!swapped) {
            std::cout << "Terminado: " <<  i + 1 << '\n';
            break;
        }
    }

    printArray(array, length);
#endif
}
