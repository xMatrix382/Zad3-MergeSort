#include "pch.h"
#include "../MergeSort/MergeSort.h"

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
    int tab[] = { 42, 7, 19, 83, 2, 56, 31, 14, 90, 5 };
    int oczekiwane[] = { 2, 5, 7, 14, 19, 31, 42, 56, 83, 90 };
    int rozmiar = 10;

    MergeSort<int> sorter;
    sorter.sortuj(tab, rozmiar);

    for (int i = 0; i < rozmiar; ++i) {
        EXPECT_EQ(tab[i], oczekiwane[i]);
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
    int tab[] = {
        54, 12, 89, 3, 47, 76, 21, 95, 8, 63,
        34, 71, 16, 84, 29, 52, 99, 11, 43, 68,
        25, 79, 5, 60, 38, 91, 14, 49, 82, 19,
        66, 31, 74, 2, 57, 87, 23, 45, 93, 10,
        69, 36, 77, 15, 51, 85, 27, 41, 96, 6,
        62, 33, 72, 18, 55, 88, 24, 46, 92, 13,
        65, 39, 75, 7, 50, 81, 28, 44, 97, 1,
        61, 35, 73, 20, 53, 86, 26, 42, 94, 9,
        64, 32, 78, 17, 56, 83, 22, 48, 98, 4,
        67, 37, 70, 21, 58, 80, 30, 40, 90, 12,
        59
    };
    const int rozmiar = 101;

    MergeSort<int> sorter;
    sorter.sortuj(tab, rozmiar);

    for (int i = 0; i < rozmiar - 1; ++i) {
        EXPECT_LE(tab[i], tab[i + 1]);
    }
}

// 13. Poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(MergeSortGoogleTest, DuzaTablicaPonad100UjemneDodatnieDuplikaty) {
    int tab[] = {
        -15, 4, 22, -15, 0, 8, -3, 19, 4, -42,
        11, -3, 27, 0, 14, -8, 6, 33, -15, 2,
        -1, 18, 8, -25, 9, 12, 0, -3, 41, 7,
        -11, 22, 5, -8, 16, 3, -19, 29, 11, 0,
        -6, 14, 2, -1, 35, 8, -12, 17, 6, -4,
        24, 1, -8, 13, 0, 31, -22, 10, 4, -3,
        20, 15, -7, 9, 2, -14, 26, 5, -1, 12,
        0, 38, -9, 18, 7, -16, 21, 3, -5, 11,
        1, -2, 28, 6, -10, 14, 0, 23, -6, 17,
        9, -13, 30, 4, -7, 15, 2, -1, 19, 8,
        -20
    };
    const int rozmiar = 101;

    MergeSort<int> sorter;
    sorter.sortuj(tab, rozmiar);

    for (int i = 0; i < rozmiar - 1; ++i) {
        EXPECT_LE(tab[i], tab[i + 1]);
    }
}