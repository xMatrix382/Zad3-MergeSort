#include <iostream>
#include "MergeSort.h"

using namespace std;

int main() {
    // 1. Tablica int
    int tabInt[] = { 67, 27, 69, 1, 9, 72 };
    int rozmiarInt = 6;

    cout << "Przed posortowaniem int: ";
    for (int i = 0; i < rozmiarInt; i++) cout << tabInt[i] << " ";
    cout << "\n";

    MergeSort<int> sortujInt;
    sortujInt.sortuj(tabInt, rozmiarInt);

    cout << "Posortowane int: ";
    for (int i = 0; i < rozmiarInt; i++) cout << tabInt[i] << " ";
    cout << "\n" << "\n";

    // 2. Tablica double
    double tabDouble[] = { 3.14, -2.5, 3.4, 67.69 };
    int rozmiarDouble = 4;

    cout << "Przed posortowaniem double: ";
    for (int i = 0; i < rozmiarDouble; i++) cout << tabDouble[i] << " ";
    cout << "\n";

    MergeSort<double> sortujDouble;
    sortujDouble.sortuj(tabDouble, rozmiarDouble);

    cout << "Posortowane double: ";
    for (int i = 0; i < rozmiarDouble; i++) cout << tabDouble[i] << " ";
    cout << "\n";

    return 0;
}