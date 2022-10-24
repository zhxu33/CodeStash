// Merge Sort
//
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include "mergesort.h"
#include "ctime"

void MergeSort(std::vector<int>* numbers, int& numComparisons, int& numMemoryAccess, double& mergeSortTime) {
   clock_t runtime = clock();
   MergeSortRecurse(numbers, 0, numbers->size() - 1, numComparisons, numMemoryAccess);
   runtime = clock() - runtime;
   mergeSortTime = (double)runtime/CLOCKS_PER_SEC;
}


void MergeSortRecurse(std::vector<int>* numbers, int i, int k, int& numComparisons, int& numMemoryAccess) {
   int j = 0;

   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition

      // Recursively sort left and right partitions
      MergeSortRecurse(numbers, i, j, numComparisons, numMemoryAccess);
      MergeSortRecurse(numbers, j + 1, k, numComparisons, numMemoryAccess);

      // Merge left and right partition in sorted order
      Merge(numbers, i, j, k, numComparisons, numMemoryAccess);
   }
}

void Merge(std::vector<int>* numbers, int i, int j, int k, int& numComparisons, int& numMemoryAccess) {
   int mergedSize = k - i + 1;                // Size of merged partition
   int mergePos = 0;                          // Position to insert merged number
   int leftPos = 0;                           // Position of elements in left partition
   int rightPos = 0;                          // Position of elements in right partition
   std::vector<int> mergedNumbers;
   mergedNumbers.resize(mergedSize);          // Dynamically allocates temporary array
                                              // for merged numbers

   leftPos = i;                               // Initialize left partition position
   rightPos = j + 1;                          // Initialize right partition position

   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {
      if ((*numbers)[leftPos] < (*numbers)[rightPos]) {
         mergedNumbers[mergePos] = (*numbers)[leftPos];
         ++leftPos;
         //++numMemoryAccess;
         numMemoryAccess += 2;
      }
      else {
         mergedNumbers[mergePos] = (*numbers)[rightPos];
         //++numMemoryAccess;
         numMemoryAccess += 2;
         ++rightPos;
      }
      numMemoryAccess += 2;
      numComparisons++;
      ++mergePos;
   }

   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers[mergePos] = (*numbers)[leftPos];
      numMemoryAccess+=2;
      ++leftPos;
      ++mergePos;
   }

   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers[mergePos] = (*numbers)[rightPos];
      numMemoryAccess+=2;
      ++rightPos;
      ++mergePos;
   }

   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      (*numbers)[i + mergePos] = mergedNumbers[mergePos];
      numMemoryAccess+=2;
   }
}
