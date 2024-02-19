#include "sortingAlgos.h"
#include "main.h"

// Implementation of the selection sort algorithm
// Sorts an array in ascending order using selection sort and counts the number of comparisons made
// Parameters:
//   arr: Pointer to the array to be sorted
//   len: Length of the array
// Returns:
//   The total number of comparisons made during the sorting process
int selectionSortComparisons(int *arr, int len) {
  int comparisons = 0;
  // Iterating through the array
  for (int i = 0; i < len; i++) {
    comparisons++;
    // Initializing min index to current index
    int min = i;
    // Finding the index of the minimum element in the unsorted portion of the array
    for (int j = i; j < len; j++) {
      comparisons += 2;
      // Comparing elements to find the minimum
      if (arr[min] > arr[j]) {
        min = j;
      }
    }
    // Swapping the minimum element with the first element of the unsorted portion
    int saved = arr[i];
    arr[i] = arr[min];
    arr[min] = saved;
  }
  return comparisons; // Returning the total number of comparisons
}

// Implementation of the quick sort algorithm
// Sorts an array in ascending order using quick sort and counts the number of comparisons made
// Parameters:
//   arr: Pointer to the array to be sorted
//   low: Starting index of the subarray to be sorted
//   high: Ending index of the subarray to be sorted
// Returns:
//   The total number of comparisons made during the sorting process
int quickSortComparisons(int *arr, const int low, const int high) {
  int comps = 1;
  if (low < high) {
    // Partitioning the array and obtaining the pivot index
    int partIdx = partition(arr, low, high, comps);
    // Recursively sorting the subarrays before and after the pivot
    comps += quickSortComparisons(arr, low, partIdx - 1);
    comps += quickSortComparisons(arr, partIdx + 1, high);
  }
  return comps; // Returning the total number of comparisons
}

// Helper function for quick sort: partitioning
// Partitions the array into two halves such that elements less than pivot are on the left and elements greater are on the right
// Parameters:
//   arr: Pointer to the array to be partitioned
//   low: Starting index of the subarray to be partitioned
//   high: Ending index of the subarray to be partitioned
//   comps: Reference to an integer variable to store the number of comparisons made during the partitioning process
// Returns:
//   The index of the pivot element after partitioning
int partition(int arr[], int low, int high, int &comps) {
  // Initializing the index of the smaller element
  int i = (low - 1);
  // Choosing the pivot element (last element)
  const int pivot = arr[high];
  // Iterating through the array
  for (int j = low; j <= high; j++) {
    comps += 2;
    // Comparing elements with the pivot
    if (arr[j] < pivot) {
      i++;
      // Swapping elements
      int saved = arr[j];
      arr[j] = arr[i];
      arr[i] = saved;
    }
  }
  // Swapping the pivot element into its correct position
  arr[high] = arr[i + 1];
  arr[i + 1] = pivot;
  return i + 1; // Returning the index of the pivot element
}
