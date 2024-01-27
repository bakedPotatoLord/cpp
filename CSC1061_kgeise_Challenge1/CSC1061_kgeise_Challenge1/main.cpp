// CSC1061_kgeise_Challenge1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#pragma once

#include <iostream>
#include "LinkedList.h"
#include "Array.h"

using namespace std;

int main()
{
    // Test LinkedList
    cout << "LinkedList tests:\n";

    // Initialize LinkedList with values 0-9
    LinkedList<int> list;
    for (int i = 0; i < 10; i++) {
        list.Push(i);
    }
    
    // Print initial LinkedList
    cout << "initialize Linkedlist with 0-9 \n";
    list.print();
    cout << "starting length: " << list.Length() << '\n';
    cout << "value at index 3: " << list.get(3) << '\n';

    // Pop 2 elements from LinkedList
    cout << "popping 2 elements\n";
    list.Pop();
    list.Pop();

    // Print resulting LinkedList
    cout << "resulting length: " << list.Length() << '\n';
    list.print();

    // Insert elements at specific indices in LinkedList
    cout << "inserting  69 at idx 1 and 83 at idx 4\n";
    list.Insert(69, 1);
    list.Insert(83, 4);
    list.print();

    // Remove elements at specific indices from LinkedList
    cout << "remove elements at idx 2 and then 7\n";
    list.Remove(2);
    list.Remove(7);
    list.print();

    // Test Array
    cout << "\n\nArray tests:\n";
    Array<int> arr;

    // Initialize Array with values 0-9
    cout << "initialize Array with 0-9 \n";
    for (int i = 0; i < 10; i++) {
        arr.Push(i);
    }
    
    // Print initial Array
    arr.print();
    cout << "starting length: " << arr.Length() << '\n';
    cout << "value at index 3: " << arr.get(3) << '\n';

    // Pop 2 elements from Array
    cout << "popping 2 elements\n";
    arr.Pop();
    arr.Pop();

    // Print resulting Array
    cout << "resulting length: " << arr.Length() << '\n';
    arr.print();

    // Insert elements at specific indices in Array
    cout << "inserting  69 at idx 1 and 83 at idx 4\n";
    arr.Insert(69, 1);
    arr.Insert(83, 4);
    arr.print();

    // Remove elements at specific indices from Array
    cout << "remove elements at idx 2 and then 7\n";
    arr.Remove(2);
    arr.Remove(7);
    arr.print();
}
