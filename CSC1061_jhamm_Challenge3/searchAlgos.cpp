#include "searchAlgos.h"

// Sequential search algorithm
// Searches for a specified element in an array sequentially
// Parameters:
//   arr: Pointer to the array to be searched
//   len: Length of the array
//   searchEl: Element to search for
//   comparisons: Reference to an integer variable to store the number of comparisons made during the search
// Returns:
//   True if the element is found, false otherwise
bool sequentialSearch(int *arr, int len, int searchEl, int &comparisons) {
  // Iterating through the array
  for (int i = 0; i < len; i++) {
    // Incrementing comparisons for each comparison operation
    comparisons += 2;
    // Checking if the current element is equal to the search element
    if (arr[i] == searchEl)
      return true; // Returning true if found
  }
  return false; // Returning false if not found
}

// Binary search algorithm
// Searches for a specified element in a sorted array using binary search
// Parameters:
//   arr: Pointer to the sorted array to be searched
//   len: Length of the array
//   searchEl: Element to search for
//   comparisons: Reference to an integer variable to store the number of comparisons made during the search
// Returns:
//   True if the element is found, false otherwise
bool binarySeach(int *arr, int len, int searchEl, int &comparisons) {
  // Initializing low and high pointers for binary search
  int low = 0;
  int high = len - 1;
  // Performing binary search
  while (high - low > 1) {
    // Incrementing comparisons for each comparison operation
    comparisons++;
    // Calculating the pivot index
    int pivot = low + (high - low) / 2;
    // Incrementing comparisons for each comparison operation
    comparisons++;
    // Checking if the search element is equal to the pivot element
    if (searchEl == arr[pivot]) {
      return true; // Returning true if found
    } else {
      // Incrementing comparisons for each comparison operation
      comparisons++;
      // Adjusting the search range based on the comparison result
      if (searchEl > arr[pivot]) {
        low = pivot + 1;
      } else {
        high = pivot - 1;
      }
    }
  }
  return false; // Returning false if not found
}