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
		void clearTree(const BTNode*)
		void trim(BTNode*);
		void add(const T, const BTNode*);
		void rem(const T, const BTNode*);
		//adds a lot of levels FIND BETTER WAY LATER
		//merges 2 trees together into one
		//used to the rem function
		void merge(const BTNode*, const BTNode*);
		bool find(const T, const BTNode*);
		void displayUp(const BTNode*);
		void displayDown(const BTNode*);
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