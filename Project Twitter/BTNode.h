#ifndef BTNODE_H
#define BTNODE_H

#include <iostream>

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
		int balance;
		void del(T const &);
		void del(T* const &);
	public:
		BTNode(const T);
		T getData();
    T minValue(BTNode*);
		BTNode<T>* getLeft();
		BTNode<T>* getRight();
        BTNode<T>* remove(BTNode*,T);
		void setLeft(BTNode*);
		void setRight(BTNode*);
		void add(const T, BTNode*);
		void clearList(BTNode*);
		void toString(BTNode*);
};

template <class T>
BTNode<T>::BTNode(const T info) : left(NULL), right(NULL){
	leftCount = 0;
	rightCount = 0;
	balance = 0;
	data = info;
}

template <class T>
void BTNode<T>::del(T const &) {}

template <class T>
void BTNode<T>::del(T* const & p) {delete p;}

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

template <class T>
BTNode<T>* BTNode<T>::remove(BTNode<T>* node,T keytodelete)
 {
    if (keytodelete < node->getData()) {
        if (node->getLeft() != NULL)
            return node->getLeft()->remove(node->getLeft(), keytodelete);
        else
            return NULL;
    } else if (keytodelete > node->getData()) {
        if (node->getRight != NULL)
            return node->getRight()->remove(node->getRight(), keytodelete);
        else
            return NULL;
    } else {
        if (node->getLeft() != NULL && node->getRight() != NULL) {
            this->keytodelete = minValue(node->getRight());
            return node->getRight()->remove(this->keytodelete, this);
        } else if (parent->left == this) {
            parent->left = (left != NULL) ? left : right;
            return this;
        } else if (parent->right == this) {
            parent->right = (left != NULL) ? left : right;
            return this;
        }
    }
}
template <class T>
T BTNode<T>::minValue(BTNode* node) {
    if (node->getLeft() == NULL)
        return node->getData();
    else
        return node->minValue(node->getLeft());
}
#endif