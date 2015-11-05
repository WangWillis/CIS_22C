#ifndef BTNODE_H
#define BTNODE_H

#include <stddef.h>

template <class T>
class BTNode;

template <class T>
class BTNode{
	private:
		//dont want to have a node with random data
		BTNode();
		T data;
		BTNode* left, right;
		void del(T const &);
		void del(T* const &)
	public:
		BTNode(const T);
		~BTNode();
		T getData();
		BTNode* getLeft();
		BTNode* getRight();
		void setLeft(const BTNode*);
		void setRight(const BTNode*);
};

template <class T>
BTNode<T>::BTNode(const T info) : left(NULL), right(NULL){
	data = info;
}

template <class T>
BTNode<T>::~BTNode(){
	del(data);
}

template <class T>
void del(T const &) {}

template <class T>
void del(T* const & p) {delete p;}

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
void BTNode<T>::setLeft(const BTNode* temp){
	if(left == NULL)
		left = temp;
}

template <class T>
void BTNode<T>::setRight(const BTNode* temp){
	if(right == NULL)
		right = temp;
}

#endif