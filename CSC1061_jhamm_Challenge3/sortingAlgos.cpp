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

int quickSortComparisons(int* arr, int len)
{
	return 0;
}
