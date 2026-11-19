#include "pch.h"
#include "../MergeSort/MergeSort.h"
#include <vector>
#include <algorithm>
#include <random>

// 1. Zachowuje tablicę niezmienioną, gdy ona jest już posortowana rosnąco
TEST(MergeSortGoogleTest, JuzPosortowanaRosnaco) {
    int tab[] = { 1, 2, 3, 4, 5 };
    int oczekiwane[] = { 1, 2, 3, 4, 5 };
    int rozmiar = 5;

    MergeSort<int> sorter;
    sorter.sortuj(tab, rozmiar);

    for (int i = 0; i < rozmiar; ++i) {
        EXPECT_EQ(tab[i], oczekiwane[i]);
    }
}

// 2. Potrafi posortować tablicę, która jest posortowana w odwrotnej kolejności
TEST(MergeSortGoogleTest, OdwrotnaKolejnosc) {
    int tab[] = { 9, 7, 5, 3, 1 };
    int oczekiwane[] = { 1, 3, 5, 7, 9 };
    int rozmiar = 5;

    MergeSort<int> sorter;
    sorter.sortuj(tab, rozmiar);

    for (int i = 0; i < rozmiar; ++i) {
        EXPECT_EQ(tab[i], oczekiwane[i]);
    }
}

// 3. Poprawnie sortuje losową tablicę liczb
TEST(MergeSortGoogleTest, LosowaTablica) {
    std::vector<int> dane = { 42, 7, 19, 83, 2, 56, 31, 14, 90, 5 };
    std::vector<int> oczekiwane = dane;
    std::sort(oczekiwane.begin(), oczekiwane.end());

    MergeSort<int> sorter;
    sorter.sortuj(dane.data(), static_cast<int>(dane.size()));

    for (size_t i = 0; i < dane.size(); ++i) {
        EXPECT_EQ(dane[i], oczekiwane[i]);
    }
}

// 4. Poprawnie sortuje tablicę tylko z liczbami ujemnymi
TEST(MergeSortGoogleTest, TylkoUjemne) {
    int tab[] = { -5, -100, -1, -42, -17 };
    int oczekiwane[] = { -100, -42, -17, -5, -1 };
    int rozmiar = 5;

    MergeSort<int> sorter;
    sorter.sortuj(tab, rozmiar);

    for (int i = 0; i < rozmiar; ++i) {
        EXPECT_EQ(tab[i], oczekiwane[i]);
    }
}

// 5. Poprawnie sortuje tablicę z liczbami ujemnymi i dodatnimi
TEST(MergeSortGoogleTest, UjemneIDodatnie) {
    int tab[] = { -10, 25, 0, -3, 14, -1, 8 };
    int oczekiwane[] = { -10, -3, -1, 0, 8, 14, 25 };
    int rozmiar = 7;

    MergeSort<int> sorter;
    sorter.sortuj(tab, rozmiar);

    for (int i = 0; i < rozmiar; ++i) {
        EXPECT_EQ(tab[i], oczekiwane[i]);
    }
}

// 6. Obsługuje pustą tablicę bez rzucania wyjątku
TEST(MergeSortGoogleTest, PustaTablica) {
    int tab[1] = {};
    int rozmiar = 0;

    MergeSort<int> sorter;
    EXPECT_NO_THROW(sorter.sortuj(tab, rozmiar));
    EXPECT_NO_THROW(sorter.sortuj(nullptr, 0));
}

// 7. Nie zmienia tablicy, która zawiera tylko jeden element
TEST(MergeSortGoogleTest, JedenElement) {
    int tab[] = { 123 };
    int oczekiwane[] = { 123 };
    int rozmiar = 1;

    MergeSort<int> sorter;
    sorter.sortuj(tab, rozmiar);

    for (int i = 0; i < rozmiar; ++i) {
        EXPECT_EQ(tab[i], oczekiwane[i]);
    }
}

// 8. Poprawnie sortuje tablicę z duplikatami liczb
TEST(MergeSortGoogleTest, ZDuplikatami) {
    int tab[] = { 4, 2, 4, 1, 2, 5, 1 };
    int oczekiwane[] = { 1, 1, 2, 2, 4, 4, 5 };
    int rozmiar = 7;

    MergeSort<int> sorter;
    sorter.sortuj(tab, rozmiar);

    for (int i = 0; i < rozmiar; ++i) {
        EXPECT_EQ(tab[i], oczekiwane[i]);
    }
}

// 9. Poprawnie sortuje tablicę ujemną z duplikatami
TEST(MergeSortGoogleTest, UjemneZDuplikatami) {
    int tab[] = { -4, -9, -4, -1, -9, -2 };
    int oczekiwane[] = { -9, -9, -4, -4, -2, -1 };
    int rozmiar = 6;

    MergeSort<int> sorter;
    sorter.sortuj(tab, rozmiar);

    for (int i = 0; i < rozmiar; ++i) {
        EXPECT_EQ(tab[i], oczekiwane[i]);
    }
}

// 10. Poprawnie sortuje tablicę z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(MergeSortGoogleTest, UjemneDodatnieIDuplikaty) {
    int tab[] = { 5, -3, 0, 5, -3, 12, 0, -8, 12 };
    int oczekiwane[] = { -8, -3, -3, 0, 0, 5, 5, 12, 12 };
    int rozmiar = 9;

    MergeSort<int> sorter;
    sorter.sortuj(tab, rozmiar);

    for (int i = 0; i < rozmiar; ++i) {
        EXPECT_EQ(tab[i], oczekiwane[i]);
    }
}

// 11. Poprawnie sortuje tablicę zawierającą tylko dwa elementy w kolejności rosnącej
TEST(MergeSortGoogleTest, DwaElementyRosnaco) {
    int tab[] = { 10, 20 };
    int oczekiwane[] = { 10, 20 };
    int rozmiar = 2;

    MergeSort<int> sorter;
    sorter.sortuj(tab, rozmiar);

    for (int i = 0; i < rozmiar; ++i) {
        EXPECT_EQ(tab[i], oczekiwane[i]);
    }
}

// 12. Poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów
TEST(MergeSortGoogleTest, DuzaTablicaPonad100) {
    const int rozmiar = 250;
    std::vector<int> dane(rozmiar);
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(0, 10000);

    for (int i = 0; i < rozmiar; ++i) {
        dane[i] = dist(rng);
    }

    std::vector<int> oczekiwane = dane;
    std::sort(oczekiwane.begin(), oczekiwane.end());

    MergeSort<int> sorter;
    sorter.sortuj(dane.data(), rozmiar);

    for (int i = 0; i < rozmiar; ++i) {
        EXPECT_EQ(dane[i], oczekiwane[i]);
    }
}

// 13. Poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(MergeSortGoogleTest, DuzaTablicaPonad100UjemneDodatnieDuplikaty) {
    const int rozmiar = 300;
    std::vector<int> dane(rozmiar);
    std::mt19937 rng(123);
    std::uniform_int_distribution<int> dist(-50, 50);

    for (int i = 0; i < rozmiar; ++i) {
        dane[i] = dist(rng);
    }

    std::vector<int> oczekiwane = dane;
    std::sort(oczekiwane.begin(), oczekiwane.end());

    MergeSort<int> sorter;
    sorter.sortuj(dane.data(), rozmiar);

    for (int i = 0; i < rozmiar; ++i) {
        EXPECT_EQ(dane[i], oczekiwane[i]);
    }
}