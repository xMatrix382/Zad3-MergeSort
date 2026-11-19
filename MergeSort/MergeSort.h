/**
 * @file MergeSort.h
 * @brief Definicja oraz implementacja klasy szablonowej MergeSort realizującej sortowanie przez scalanie.
 */

#pragma once

 /**
  * @class MergeSort
  * @brief Klasa szablonowa implementująca algorytm sortowania przez scalanie (MergeSort).
  *
  * Algorytm działa w oparciu o paradygmat „dziel i zwyciężaj” ze złożonością czasową
  * \f$O(n \log n)\f$ oraz pamięciową \f$O(n)\f$.
  *
  * @tparam T Typ elementów przechowywanych w tablicy (musi obsługiwać operator porównania <=).
  */

template <typename T>
class MergeSort {
private:
    /**
     * @brief Scala dwie posortowane podtablice w jedną uporządkowaną całość.
     *
     * Funkcja dzieli rozpatrywany fragment tablicy na dwie tablice pomocnicze (lewą i prawą),
     * a następnie przepisuje elementy z powrotem do tablicy głównej w kolejności niemalejącej.
     *
     * @param tab Wskaźnik na sortowaną tablicę elementów.
     * @param lewy Indeks początkowy lewej podtablicy.
     * @param srodek Indeks końcowy lewej podtablicy (punkt podziału).
     * @param prawy Indeks końcowy prawej podtablicy.
     */
    void scal(T* tab, int lewy, int srodek, int prawy) {
        int n1 = srodek - lewy + 1;
        int n2 = prawy - srodek;

        T* L = new T[n1];
        T* P = new T[n2];

        for (int i = 0; i < n1; i++) L[i] = tab[lewy + i];
        for (int j = 0; j < n2; j++) P[j] = tab[srodek + 1 + j];

        int i = 0, j = 0, k = lewy;
        while (i < n1 && j < n2) {
            if (L[i] <= P[j]) {
                tab[k++] = L[i++];
            }
            else {
                tab[k++] = P[j++];
            }
        }

        while (i < n1) tab[k++] = L[i++];
        while (j < n2) tab[k++] = P[j++];

        delete[] L;
        delete[] P;
    }

public:
    /**
     * @brief Rekurencyjnie sortuje przekazaną tablicę rosnąco metodą przez scalanie.
     *
     * W przypadku przekazania pustego wskaźnika (\c nullptr) lub tablicy o rozmiarze
     * mniejszym bądź równym 1 metoda kończy działanie bez modyfikacji danych.
     *
     * @param tab Wskaźnik na tablicę do posortowania.
     * @param rozmiar Liczba elementów w tablicy.
     */
    void sortuj(T* tab, int rozmiar) {
        if (tab == nullptr || rozmiar <= 1) return;
        int srodek = rozmiar / 2;
        sortuj(tab, srodek);
        sortuj(tab + srodek, rozmiar - srodek);
        scal(tab, 0, srodek - 1, rozmiar - 1);
    }
};