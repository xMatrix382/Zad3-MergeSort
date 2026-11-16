#include <iostream>
#include "MergeSort.h"

int main() {
    // 1. Tablica int
    int tabInt[] = { 67, 27, 69, 1, 9, 72 };
    int rozmiarInt = 6;
    MergeSort<int> sortujInt;
    sortujInt.sortuj(tabInt, rozmiarInt);

    std::cout << "Posortowane int: ";
    for (int i = 0; i < rozmiarInt; i++) std::cout << tabInt[i] << " ";
    std::cout << "\n";

    // 2. Tablica double
    double tabDouble[] = { 3.14, -2.5, 0.0, 1.1 };
    int rozmiarDouble = 4;
    MergeSort<double> sortujDouble;
    sortujDouble.sortuj(tabDouble, rozmiarDouble);

    std::cout << "Posortowane double: ";
    for (int i = 0; i < rozmiarDouble; i++) std::cout << tabDouble[i] << " ";
    std::cout << "\n";

    return 0;
}