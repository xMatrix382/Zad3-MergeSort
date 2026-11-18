#include "pch.h"
#include "../MergeSort/MergeSort.h"
#include <vector>
#include <algorithm>
#include <random>

// test 1
TEST(MergeSortGoogleTest, JuzPosortowanaRosnaco) {
	int tab[] = { 1, 2, 3, 4, 5 };
	int oczekiwane[] = { 1, 2, 3, 4, 5 };
	int rozmiar = 5;

	MergeSort<int> sorter;
	sorter.sortuj(tab, rozmiar);

	for (int i = 0;i < rozmiar;i++) {
		EXPECT_EQ(tab[i], oczekiwane[i]);
	}
}