
#pragma once // Preprocessor directive to ensure that the header file is
             // included only once

#include "EmployeeInfo.h" // Include the header file that contains the EmployeeInfo class
#include <iostream> // Include the standard input/output stream library

using namespace std; // Using the standard namespace for cout

// Structure for a tree node containing data of type T
template <class T> struct treeNode {
  T data;                 // Data stored in the node
  struct treeNode *left;  // Pointer to the left child node
  struct treeNode *right; // Pointer to the right child node
};

// Class for a binary tree with nodes containing data of type T
template <class T> class BinaryTree {
private:
  treeNode<T> *root; // Pointer to the root node of the binary tree
  int count;         // Number of nodes in the binary tree

public:
  // Function to add a new node with data of type T to the binary tree
  void add(T data);

  // Function to search for a node with a given ID in the binary tree
  T search(int id);

  // Function to check if a node with a given ID exists in the binary tree
  bool hasID(int id);

  // Function to check if the binary tree is empty
  bool isEmpty();

  // Function to get the root node of the binary tree
  treeNode<T> getRoot();

  // Constructor with parameter to initialize the binary tree with a root node
  BinaryTree(T root);

  // Default constructor to initialize an empty binary tree
  BinaryTree();
};

// Implementation of the add function to add a new node to the binary tree
template <class T> inline void BinaryTree<T>::add(T data) {
  treeNode<T> *val = new treeNode<T>; // Create a new tree node with data
  val->left = NULL;                   // Initialize left child pointer to null
  val->right = NULL;                  // Initialize right child pointer to null
  val->data = data;                   // Set the data of the new node
  treeNode<T> *parent =
      NULL; // Pointer to track the parent node during traversal

  if (isEmpty()) { // If the binary tree is empty, set the new node as the root
    root = val;
  } else {
    treeNode<T> *ptr =
        root; // Pointer to traverse the binary tree starting from the root
    while (ptr != NULL) {
      parent = ptr; // Update the parent pointer
      if (data > ptr->data) {
        ptr = ptr->right; // Move to the right child if the new data is greater
                          // than the current node's data
      } else if (data < ptr->data) {
        ptr = ptr->left; // Move to the left child if the new data is less than
                         // the current node's data
      }
    }

    // Insert the new node as the left or right child of the parent node based
    // on the comparison result
    if (parent->data > data) {
      parent->left = val;
    } else if (parent->data < data) {
      parent->right = val;
    } else {
      cout << "duplicates are not allowed"; // Duplicate data is not allowed in
                                            // the binary tree
    }
  }
}

// Implementation of the search function to find a node with a given ID in the
// binary tree
template <class T> inline T BinaryTree<T>::search(int id) {
  treeNode<T> *n = root; // Start the search from the root node

  while (n != NULL) {
    if (n->data > id) {
      n = n->left; // Move to the left child if the current node's data is
                   // greater than the target ID
    } else if (n->data < id) {
      n = n->right; // Move to the right child if the current node's data is
                    // less than the target ID
    } else {
      return n->data; // Return the data of the node if the target ID is found
    }
  }
  throw "no employee found"; // Throw an exception if the target ID is not found
                             // in the binary tree
}

// Implementation of the hasID function to check if a node with a given ID
// exists in the binary tree
template <class T> inline bool BinaryTree<T>::hasID(int id) {
  treeNode<T> *n = root; // Start the search from the root node

  while (n != NULL) {
    if (n->data > id) {
      n = n->left; // Move to the left child if the current node's data is
                   // greater than the target ID
    } else if (n->data < id) {
      n = n->right; // Move to the right child if the current node's data is
                    // less than the target ID
    } else {
      return true; // Return true if the target ID is found in the binary tree
    }
  }
  return false; // Return false if the target ID is not found in the binary tree
}

// Implementation of the getRoot function to get the root node of the binary
// tree
template <class T> inline treeNode<T> BinaryTree<T>::getRoot() {
  return *root; // Return the root node of the binary tree
}

// Constructor implementation with a parameter to initialize the binary tree
// with a root node
template <class T> inline BinaryTree<T>::BinaryTree(T root) {
  add(T); // Add the root node to the binary tree
}

// Default constructor implementation to initialize an empty binary tree
template <class T> inline BinaryTree<T>::BinaryTree() {
  root = NULL; // Set the root pointer to null to indicate an empty binary tree
  count = 0;   // Initialize the count of nodes to zero
}

// Implementation of the isEmpty function to check if the binary tree is empty
template <class T> inline bool BinaryTree<T>::isEmpty() {
  return root == NULL; // Return true if the root pointer is null, indicating an
                       // empty binary tree
}