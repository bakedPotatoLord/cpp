#pragma once

#include <iostream>
#include "EmployeeInfo.h"

template<class T>
struct treeNode {
	T data;
	struct treeNode* left;
	struct treeNode* right;
};

template<class T>
class BinaryTree{
private:
	treeNode<T> * root;
	int count;

public:
	void add(T data);
	T search(int id);
	bool hasID(int id);
	bool isEmpty();

	treeNode<T> getRoot();

	BinaryTree(T root);
	BinaryTree();

};

template<class T>
inline void BinaryTree<T>::add(T data)
{
	treeNode<T>* val = new treeNode<T>;
	val->left = NULL;
	val->right = NULL;
	val->data = data;

	treeNode<T>* parent = NULL;

	if (isEmpty()) {
		root = val;
	}
	else {
		treeNode<T>* ptr = root;
		while (ptr != NULL) {
			parent = ptr;

			if (data > ptr->data) {
				ptr = ptr->right;
			}
			else if (data < ptr->data) {
				ptr = ptr->left;
			}
		}
		if (parent->data > data) {
			parent->left = val;
		}
		else if (parent->data < data) {
			parent->right = val;
		}
		else {
			cout << "duplicates are not allowed";
		}

	}
}
	


template<class T>
inline T BinaryTree<T>::search(int id)
{
	treeNode<T>* n = root;

	while (n != NULL) {
		if (n->data > id) {
			n = n->left;
		}
		else if(n->data < id) {
			n = n->right;
		}
		else {
			return n->data;
		}
	}
	throw "aaaah!";
}

template<class T>
inline bool BinaryTree<T>::hasID(int id)
{
	treeNode<T>* n = root;

	while (n != NULL) {
		if (n->data > id) {
			n = n->left;
		}
		else if (n->data < id) {
			n = n->right;
		}
		else {
			return true;
		}
	}
	return false;
}

template<class T>
inline treeNode<T> BinaryTree<T>::getRoot()
{
	return *root;
}



template<class T>
inline BinaryTree<T>::BinaryTree(T root)
{
	add(T);
}

template<class T>
inline BinaryTree<T>::BinaryTree()
{
	root = NULL;
	count = 0;
}


template<class T>
inline bool BinaryTree<T>::isEmpty()
{
	return root == NULL;
}

