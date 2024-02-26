/*
File: List.h
Author: Ram Longman
Date: 1/29/2023
Description: An abstract class for lists.
*/
#pragma once

#include <iostream>
using namespace std;

template <class T>
class List
{
public:
	List() { length = 0; } //start with an empty list

	int Length() { return length; }
	void IncrementLength() { length++; }
	void DecrementLength() { length--; }

	//pure virtual functions that all child classes must implement
	virtual void Push(T element) = 0;
	virtual void Pop() = 0;
	virtual void Insert(T element, int index) = 0;
	virtual void Remove(int index) = 0;
	virtual T get(int index) = 0;
	virtual void print() = 0;

private:
	int length; //the number of elements in the list
};

