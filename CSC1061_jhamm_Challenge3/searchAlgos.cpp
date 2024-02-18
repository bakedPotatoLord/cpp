#include "searchAlgos.h"

bool sequentialSearch(int *arr, int len, int searchEl, int &comparisons) {
  for (int i = 0; i < len; i++) {
    comparisons += 2;
    if (arr[i] == searchEl)
      return true;
  }
  return false;
}

bool binarySeach(int *arr, int len, int searchEl, int &comparisons) {
  int low = 0;
  int high = len - 1;

  while (high - low > 1) {
    comparisons++;
    int pivot = low + (high - low) / 2;
    comparisons++;
    if (searchEl == arr[pivot]) {
      return true;
    } else {
      comparisons++;
      if (searchEl > arr[pivot]) {
        low = pivot + 1;
      } else {
        high = pivot - 1;
      }
    }
  }

  return false;
}
