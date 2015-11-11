#ifndef BST_H
#define BST_H

#include <iostream>
#include "BTNode.h"

template <class T>
class BinarySearchTree;

template <class T>
class BinarySearchTree{
	private:
		BTNode* head;
	public:
		BinarySearchTree();
		BinarySearchTree(T);
		~BinarySearchTree();
		void add(const T);
		void rem(const T);
		bool find(const T);
		void displayUp();
		void displayDown();
};


template <class T>
bool BinarySearchTree<T>::find(T data) {
    if (head == NULL)
        return false;
    else
        return head->find(data);
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(){
	head = NULL;
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(T data){
	head = new BTNode(data);
}

template <class T>


template <class T>
void BinarySearchTree<T>::add(const T data){
	if(head == NULL){
		head = new BTNode(data);
	}
}

#endif
