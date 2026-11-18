#pragma once

template <typename T>
class MergeSort {
private:
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
    void sortuj(T* tab, int rozmiar) {
        if (tab == nullptr || rozmiar <= 1) return;
        int srodek = rozmiar / 2;
        sortuj(tab, srodek);
        sortuj(tab + srodek, rozmiar - srodek);
        scal(tab, 0, srodek - 1, rozmiar - 1);
    }
};