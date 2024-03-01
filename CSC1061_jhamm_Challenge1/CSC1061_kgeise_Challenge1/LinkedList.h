/*
File: LinkedList.h
Author: 
Date:
Description:
*/
#pragma once
#include "List.h"

template <class T>
struct Node { // a linked list node
    T info;
    Node* link;
};

template <class T>
class LinkedList :
    public List<T>
{
public:
    LinkedList(); // constructor
    ~LinkedList(); // destructor

    // implement pure virtual functions
    void Push(T element); // add an element to the end of the list
    void Pop(); // remove the last element from the list
    void Insert(T element, int index); // insert an element at a specific index
    void Remove(int index); // remove an element at a specific index
    T get(int index); // get the element at a specific index
    void print(); // print all elements in the list

private:
    Node<T>* head; // pointer to the first node in the list
    Node<T>* tail; // pointer to the last node in the list
};

template<class T>
inline LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

template<class T>
inline LinkedList<T>::~LinkedList()
{
    Node<T>* current = head;
    Node<T>* next;

    // delete all nodes in the list
    while (current != nullptr) {
        next = current->link;
        delete current;
        current = next;
    }

    head = nullptr;
    tail = nullptr;
}

template<class T>
inline void LinkedList<T>::Push(T element)
{
    Node<T>* newNode = new Node<T>{ element, nullptr };

    // if the list is empty, set both head and tail to the new node
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        // add the new node to the end of the list and update the tail
        tail->link = newNode;
        tail = newNode;
    }

    List<T>::IncrementLength();
}

template<class T>
inline void LinkedList<T>::Pop()
{
    if (head == nullptr) {
        // List is empty, nothing to pop
        return;
    }

    if (head == tail) {
        // Only one element in the list, delete it
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        // Traverse the list to find the second-to-last node, update tail, and delete the last node
        Node<T>* temp = head;
        while (temp->link != tail) {
            temp = temp->link;
        }
        delete tail;
        tail = temp;
        tail->link = nullptr;
    }

    List<T>::DecrementLength();
}

template<class T>
inline void LinkedList<T>::Insert(T element, int index)
{
    if (index < 0 || index > List<T>::Length()) {
        // Invalid index, do nothing
        return;
    }

    if (index == List<T>::Length()) {
        // Insert at the end (same as Push)
        Push(element);
        return;
    }

    Node<T>* newNode = new Node<T>{ element, nullptr };

    if (index == 0) {
        // Insert at the beginning
        newNode->link = head;
        head = newNode;
    }
    else {
        // Insert at a specific index by traversing the list
        Node<T>* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->link;
        }
        newNode->link = temp->link;
        temp->link = newNode;
    }

    List<T>::IncrementLength();
}

template<class T>
inline void LinkedList<T>::Remove(int index)
{
    if (index < 0 || index >= LinkedList<T>::Length()) {
        // Invalid index, do nothing
        return;
    }

    if (index == 0) {
        // Remove from the beginning
        Node<T>* temp = head;
        head = head->link;
        delete temp;
    }
    else {
        // Remove from a specific index by traversing the list
        Node<T>* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->link;
        }
        Node<T>* toRemove = temp->link;
        temp->link = toRemove->link;
        delete toRemove;
    }

    List<T>::DecrementLength();
}

template<class T>
inline T LinkedList<T>::get(int index)
{
    if (index < 0 || index >= LinkedList<T>::Length()) {
        // Invalid index, return a default value
        return T();
    }

    // Traverse the list to find the node at the specified index
    Node<T>* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->link;
    }

    return temp->info;
}

template<class T>
inline void LinkedList<T>::print()
{
    Node<T>* temp = head;

    // Traverse the list and print each element
    while (temp != nullptr) {
        std::cout << temp->info << " ";
        temp = temp->link;
    }

    std::cout << std::endl;
}
