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
		T getMax(BTNode*);
	public:
		BTNode(const T);
		T getData();
		BTNode<T>* getLeft();
		BTNode<T>* getRight();
		int balance(BTNode*);
        BTNode<T>* remove(const T, BTNode*);
        void setData(const T);
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
int BTNode<T>::balance(BTNode<T>* node){
	if(node == NULL){
		return 0;
	}else{
		int lh = height(node->getLeft());
		int rh = height(node->getRight());
		if(abs(lh - rh) <= 1 && balance(node->getLeft()) == 0 && balance(node->getRight()) == 0)
			return 0;
		if((lh - rh) < 0)
			return -1;
		else
			return 1;
	}
}

template <class T>
T BTNode<T>::getMax(BTNode<T>* node){
	if(node->getRight() == NULL){
		return node->getData();
	}else{
		return getMax(node->getRight());
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
void BTNode<T>::setData(const T info){
	data = info;
}

template <class T>
BTNode<T>* BTNode<T>::getRight(){
	return right;
}

template <class T>
void BTNode<T>::setLeft(BTNode<T>* temp){
	left = temp;
}

template <class T>
void BTNode<T>::setRight(BTNode<T>* temp){
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
//need to handle removing the head in BST class
template <class T>
BTNode<T>* BTNode<T>::remove(const T data, BTNode<T>* node){
	if(node != NULL){
		if(node->getData() == data){
			return node;
		}else if(node->getData() < data){
			BTNode<T>* right = node->getRight();
			if(right != NULL){
				if(right->getData() == data){
					if(right->getLeft() != NULL && right->getRight() != NULL){
						T temp = getMax(right->getLeft());
						right->setData(temp);
						return remove(temp, right->getLeft());
					}else if(right->getLeft() != NULL){
						node->setRight(right->getLeft());
						return right;
					}else if(right->getRight() != NULL){
						node->setRight(right->getRight());
						return right;
					}else{
						node->setRight(NULL);
						return right;
					}
				}
				return remove(data, right);
			}
			return NULL;
		}else{
			BTNode<T>* left = node->getRight();
			if(left != NULL){
				if(left->getData() == data){
					if(left->getLeft() != NULL && left->getRight() != NULL){
						T temp = getMax(left->getLeft());
						left->setData(temp);
						return remove(temp, left->getLeft());
					}else if(left->getLeft() != NULL){
						node->setLeft(left->getLeft());
						return left;
					}else if(left->getRight() != NULL){
						node->setLeft(left->getRight());
						return left;
					}else{
						node->setLeft(NULL);
						return left;
					}
				}
				return remove(data, left);
			}
			return NULL;
		}
	}
	return NULL;
}

#endif