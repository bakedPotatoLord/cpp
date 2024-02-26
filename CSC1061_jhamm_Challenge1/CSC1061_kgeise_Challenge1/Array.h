/*
File: Array.h
Author: Ram Longman
Date: 1/29/2023
Description: A class implementing dynamic arrays. Inheriting from the List class.
*/
#pragma once
#include "List.h"

template <class T>
class Array :
    public List<T>
{
public:
    //constructors and destructors
    Array();
    Array(int s);
    ~Array();

    int Length() { return List<T>::Length(); }

    //implement pure virtual functions
    void Push(T element);
    void Pop();
    void Insert(T element, int index);
    void Remove(int index);
    T get(int index);
    void print();

private:
    void resize();
    int size; //size of the currently allocated array
    T* arr; //pointer to the dynamic array
};

template<class T>
inline Array<T>::Array():List<T>()
{
    size = 5;
    arr = new T[size]; //create dynamic array
}

template<class T>
inline Array<T>::Array(int s):List<T>()
{
    size = s;
    arr = new T[size]; //create dynamic array
}

template<class T>
inline Array<T>::~Array()
{
    delete[] arr; //deallocate memory
}

template<class T>
inline void Array<T>::Push(T element)
{
    //add an element to the end of the array
    if (Length() == size) resize(); //if the array is full, resize it to be larger.
    arr[Length()] = element;
    List<T>::IncrementLength(); 
}

template<class T>
inline void Array<T>::Pop()
{
    //remove an element from the end of the array
    if (Length() > 0) { //can't pop from an empty array
        List<T>::DecrementLength();
    }
}

template<class T>
inline void Array<T>::Insert(T element, int index)
{
    if (index >= Length() - 1) Push(element);
    else if (index >= 0) {
        if (Length() == size) resize();
        //move elements to the right of index one position to the right
        for (int i = Length(); i > index; i--) { 
            arr[i] = arr[i - 1];
        }
        arr[index] = element; //put element in right location
        List<T>::IncrementLength();
    }
}

template<class T>
inline void Array<T>::Remove(int index)
{
    //remove an element from a specific index
    if (index >= Length() - 1) Pop();
    else if (index >= 0) {
        T e = arr[index];
        //move elements to the right of index one position to the left
        for (int i = index; i < Length() - 1; i++) {
            arr[i] = arr[i + 1];
        }
        List<T>::DecrementLength();
    }
}

template<class T>
inline T Array<T>::get(int index)
{
    //return value in the array at given index
    return arr[index];
}

template<class T>
inline void Array<T>::print()
{
    //display the list with spaces between elements
    for (int i = 0; i < Length(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<class T>
inline void Array<T>::resize()
{
    //double the size of the dynamic array
    T* p = new T[size*2]; //allocate new memory
    for (int i = 0; i < size; i++) {
        p[i] = arr[i]; //copy elements to new memory
    }
    size *= 2; //update size
    delete[] arr; //deallocate previous array
    arr = p; //set pointer to point to new array
}
