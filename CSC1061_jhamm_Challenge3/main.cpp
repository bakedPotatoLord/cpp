
// AI tooling was used for autocomplete and comment generation
// @bakedpotatolord 2/24

#include <iostream>
#include "main.h"
#include "sortingAlgos.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    int* arr1 = makeArr();
    int* arr2 = makeArr();
    cout << "initial arr" << endl;
    printArr(arr1,100);

    cout << "shuffled arr" << endl;
    shuffle(arr1,100);
    printArr(arr1, 100);

    int c = selectionSortComparisons(arr1, 100);

    cout << "sorted arr?" << endl;
    printArr(arr1, 100);
    cout << c << endl;

}

int* makeArr()
{
    int* arr = new int[100];

    for (int i = 0; i < 100; i++) {
        arr[i] = i + 1;
    }


    return arr;
}

int* shuffle(int* arr,int len)
{
    for (int i = 0; i < len; i++) {
        int toSwap = rand() % 100;
        int saved = arr[i];
        arr[i] = arr[toSwap];
        arr[toSwap] = saved;
    }
    return arr;
}

void copyArr(int* toCopy, int* toFill, int len)
{
    for (int i = 0; i < len; i++) {
        toFill[i] = toCopy[i];
    }
}


void printArr(int* arr, int len) {
    for (int i = 0; i < len;i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}


//Overview
//Compare the Big - O behavior of search and sort algorithms.
//
//Instructions
//Create an array with all the numbers from 1 to 100 (each number should appear exactly once).
//Write a function to shuffle the list so each number is in a random unknown position.
//Modify the selection sort and quick sort functions to return the number of comparisons performed.
//Repeat the following process 100 times:
//Shuffle the list.
//Use selection sort and quick sort to sort the same shuffled list(may need two copies of it).
//Keep track of the number of comparisons performed using each algorithm.
//Display the average number of comparisons performed to sort the shuffled lists using each of the sorting algorithms.
//Create an array with all the numbers from 1 to 1000. Shuffle the array.Then, use both the sequential and binary search algorithms to search each of the numbers from 1 to 1000.
//Modify binary search and sequential search to return the number of comparisons performed instead of(or in addition to) an index. * *You may pass a parameter by reference to count comparisons instead of returning.
//Print the average number of comparisons performed to find the numbers using binary search and using sequential search.
