#pragma once

template<class T>
struct treeNode {
	T data;
	treeNode* left;
	treeNode* right;
};

template<class T>
class BinaryTree{
private:
	treeNode* root = nullptr;
	int count = 0;

public:
	void add(T data);
	bool search(T data);

	BinaryTree(T root);
	BinaryTree();

};

template<class T>
inline void BinaryTree<T>::add(T data)
{
	if (root == nullptr) {
		root = new treeNode<T>{
			data,
			nullptr
			nullptr
		};
		return;
	}
	
	treeNode<T>* ptr = root;

	while(true){
		if (data == ptr->data) {
			throw "duplicates are not allowed";
		}
		else if (data > ptr->data) {
			ptr = ptr->right;
		}
		else {
			ptr = ptr->left;
		}

		if (ptr == nullptr) {
			ptr = 
		}
	}
}

template<class T>
inline bool BinaryTree<T>::search(T data)
{
	return false;
}
