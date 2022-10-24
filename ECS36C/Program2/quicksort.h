// Quicksort
//
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include <vector>

void QuickSort(std::vector<int>* numbers, int& numComparisons, int& numMemoryAccess, double& quickSortTime);
void QuickSortRecurse(std::vector<int>* numbers, int i, int k, int& numComparisons, int& numMemoryAccess);
int Partition(std::vector<int>* numbers, int i, int k, int& numComparisons, int& numMemoryAccess);
