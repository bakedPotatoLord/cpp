// AI tooling was used for autocomplete and comment generation
// @bakedpotatolord 2/24

#include "main.h"
#include "searchAlgos.h"
#include "sortingAlgos.h"
#include <iostream>

using namespace std;

int main() {
  int *arr1 = makeArr(100);
  int *arr2 = makeArr(100);

  int sumSelection = 0;
  int sumQuick = 0;

  for (int i = 0; i < 100; i++) {
    shuffle(arr1, 100);
    copyArr(arr1, arr2, 100);

    sumSelection += selectionSortComparisons(arr1, 100);
    sumQuick += quickSortComparisons(arr2, 0, 99);
  }

  double averageSelection = (double)sumSelection / 100.0;
  double averageQuick = (double)sumQuick / 100.0;
  cout << "---------<sort algorithms>---------" << endl;
  cout << "selection sort average comparisons: " << averageSelection << endl;
  cout << "quick sort average comparisons: " << averageQuick << endl
       << endl
       << endl;

  // array seaching
  arr1 = makeArr(1000);
  arr2 = makeArr(1000);

  int sumSequential = 0;
  int sumBinary = 0;

  for (int i = 0; i < 1000; i++) {
    shuffle(arr1, 1000);
    sequentialSearch(arr1, 1000, i + 1, sumSequential);
    binarySeach(arr2, 1000, i + 1, sumBinary);
  }

  double averageSequential = (double)sumSequential / 1000.0;
  double averageBinary = (double)sumBinary / 1000.0;
  cout << "---------<search algorithms>---------" << endl;
  cout << "sequential search average comparisons: " << averageSequential
       << endl;
  cout << "binary search average comparisons: " << averageBinary << endl;
}

int *makeArr(const int len) {
  int *arr = new int[len];
  for (int i = 0; i < len; i++) {
    arr[i] = i + 1;
  }
  return arr;
}

int *shuffle(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    int toSwap = rand() % 100;
    int saved = arr[i];
    arr[i] = arr[toSwap];
    arr[toSwap] = saved;
  }
  return arr;
}

void copyArr(int *toCopy, int *toFill, int len) {
  for (int i = 0; i < len; i++) {
    toFill[i] = toCopy[i];
  }
}

void printArr(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}
