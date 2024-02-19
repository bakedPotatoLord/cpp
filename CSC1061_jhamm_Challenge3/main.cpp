// AI tooling was used for autocomplete and comment generation
// @bakedpotatolord 2/24

// This program demonstrates the efficiency of sorting and searching algorithms
// by measuring the average number of comparisons required. The sorting
// algorithms tested are selection sort and quick sort, while the searching
// algorithms tested are sequential search and binary search. Arrays are
// shuffled before each test to ensure randomness in data distribution.

#include "main.h"
#include "searchAlgos.h"
#include "sortingAlgos.h"
#include <iostream>

using namespace std;

int main() {
  // Creating arrays for testing
  int *arr1 = makeArr(100);
  int *arr2 = makeArr(100);

  // Variables to store the sum of comparisons for each sorting algorithm
  int sumSelection = 0;
  int sumQuick = 0;

  // Testing sorting algorithms
  for (int i = 0; i < 100; i++) {
    shuffle(arr1, 100);
    copyArr(arr1, arr2, 100);

    // Calculating sum of comparisons for selection sort
    sumSelection += selectionSortComparisons(arr1, 100);
    // Calculating sum of comparisons for quick sort
    sumQuick += quickSortComparisons(arr2, 0, 99);
  }

  // Calculating average comparisons for each sorting algorithm
  double averageSelection = (double)sumSelection / 100.0;
  double averageQuick = (double)sumQuick / 100.0;

  // Printing results for sorting algorithms
  cout << "---------<sort algorithms>---------" << endl;
  cout << "selection sort average comparisons: " << averageSelection << endl;
  cout << "quick sort average comparisons: " << averageQuick << endl
       << endl
       << endl;

  // Creating arrays for searching algorithms
  arr1 = makeArr(1000);
  arr2 = makeArr(1000);

  // Variables to store the sum of comparisons for each searching algorithm
  int sumSequential = 0;
  int sumBinary = 0;

  // Testing searching algorithms
  for (int i = 0; i < 1000; i++) {
    shuffle(arr1, 1000);
    // Calculating sum of comparisons for sequential search
    sequentialSearch(arr1, 1000, i + 1, sumSequential);
    // Calculating sum of comparisons for binary search
    binarySeach(arr2, 1000, i + 1, sumBinary);
  }

  // Calculating average comparisons for each searching algorithm
  double averageSequential = (double)sumSequential / 1000.0;
  double averageBinary = (double)sumBinary / 1000.0;

  // Printing results for searching algorithms
  cout << "---------<search algorithms>---------" << endl;
  cout << "sequential search average comparisons: " << averageSequential
       << endl;
  cout << "binary search average comparisons: " << averageBinary << endl;
}

// Function to create an array of specified length and initialize it with
// consecutive integers
int *makeArr(const int len) {
  int *arr = new int[len];
  for (int i = 0; i < len; i++) {
    arr[i] = i + 1;
  }
  return arr;
}

// Function to shuffle the elements of an array
int *shuffle(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    int toSwap = rand() % 100;
    int saved = arr[i];
    arr[i] = arr[toSwap];
    arr[toSwap] = saved;
  }
  return arr;
}

// Function to copy elements from one array to another
void copyArr(int *toCopy, int *toFill, int len) {
  for (int i = 0; i < len; i++) {
    toFill[i] = toCopy[i];
  }
}

// Function to print the elements of an array
void printArr(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}
