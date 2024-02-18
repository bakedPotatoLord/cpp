#include "sortingAlgos.h"
#include "main.h"
#include <iostream>

using namespace std;

int selectionSortComparisons(int* arr, int len)
{
	int comparisons = 0;

	for (int i = 0; i < len; i++) {
		//for every item in the list
		int min = i;
		for (int j = i; j < len; j++) {
			//starting at i, and continuing to end of list
			if (arr[min] > arr[j]) {
				min = j;
				comparisons++;
			}
		}
		//swap the values
		int saved = arr[i];
		arr[i] = arr[min];
		arr[min] = saved;
	}
	return comparisons;
}

int quickSortComparisons(int* arr, const int low,const int high)
{
	int comps = 1;

	if (low < high) {
		int partIdx = partition(arr, low, high, comps);
		comps += quickSortComparisons(arr, low, partIdx - 1);
		comps += quickSortComparisons(arr, partIdx + 1, high);
	}

	return comps;
}

int partition(int arr[], int low, int high, int& comps)
{
	int i = (low-1);

	const int pivot = arr[high];

	for (int j = low; j <= high; j++) {
		comps++;
		if (arr[j] < pivot) {
			
			i++;

			int saved = arr[j];
			arr[j] = arr[i];
			arr[i] = saved;
			
			
		}
	}

	arr[high] = arr[i+1];
	arr[i+1] = pivot;

	return i+1;
}


