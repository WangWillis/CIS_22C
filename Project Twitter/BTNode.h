#ifndef BTNODE_H
#define BTNODE_H

#include <iostream>
#include <stdlib.h>

template <class T>
class BTNode;

template <class T>
class BTNode{
	private:
		//dont want to have a node with random data
		BTNode();
		T data;
		BTNode* left;
		BTNode* right;
		void del(T const &);
		void del(T* const &);
		int height(BTNode*);
		int max(const int, const int);
	public:
		BTNode(const T);
		T getData();
		BTNode<T>* getLeft();
		BTNode<T>* getRight();
		bool isBalanced(BTNode*);
		void setLeft(BTNode*);
		void setRight(BTNode*);
		void add(const T, BTNode*);
		void clearList(BTNode*);
		void toString(BTNode*);
};

template <class T>
BTNode<T>::BTNode(const T info) : left(NULL), right(NULL){
	data = info;
}

template <class T>
void BTNode<T>::del(T const &) {}

template <class T>
void BTNode<T>::del(T* const & p) {delete p;}

template<class T>
int BTNode<T>::max(const int a, const int b){
	if(a > b)
		return a;
	return b;
}

template <class T>
int BTNode<T>::height(BTNode<T>* node){
	if(node == NULL){
		return 0;
	}else{
		return 1 + max(height(node->getLeft()), height(node->getRight()));
	}
}

template <class T>
bool BTNode<T>::isBalanced(BTNode<T>* node){
	if(node == NULL){
		return true;
	}else{
		int lh = height(node->getLeft());
		int rh = height(node->getRight());
		if(abs(lh - rh) <= 1 && isBalanced(node->getLeft()) && isBalanced(node->getRight()))
			return true;
		return false;
	}
}

template <class T>
T BTNode<T>::getData(){
	return data;
}

template <class T>
BTNode<T>* BTNode<T>::getLeft(){
	return left;
}

template <class T>
BTNode<T>* BTNode<T>::getRight(){
	return right;
}

template <class T>
void BTNode<T>::setLeft(BTNode<T>* temp){
	if(left == NULL)
		left = temp;
}

template <class T>
void BTNode<T>::setRight(BTNode<T>* temp){
	if(right == NULL)
		right = temp;
}

template <class T>
void BTNode<T>::add(const T info, BTNode<T>* node){
	if(node != NULL){
		if(info < node->getData()){
			if(node->getLeft() != NULL){
				add(info, node->getLeft());
			}else{
				node->setLeft(new BTNode<T>(info));
			}
		}else{
			if(node->getRight() != NULL){
				add(info, node->getRight());
			}else{
				node->setRight(new BTNode<T>(info));
			}
		}
	}
}

template <class T>
void BTNode<T>::clearList(BTNode<T>* node){
	if(node != NULL){
		if(node->getLeft() != NULL){
			clearList(node->getLeft());
		}
		if(node->getRight() != NULL){
			clearList(node->getRight());
		}
		node->setLeft(NULL);
		node->setRight(NULL);
		del(node->getData());
		delete node;
	}
}

template <class T>
void BTNode<T>::toString(BTNode<T>* node){
	if(node != NULL){
		if(node->getLeft() != NULL){
			toString(node->getLeft());
		}
		std::cout << node->getData() << std::endl;
		if(node->getRight() != NULL){
			toString(node->getRight());
		}
	}
}

#endif