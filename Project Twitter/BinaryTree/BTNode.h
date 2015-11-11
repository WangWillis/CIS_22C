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
		int height;
		void del(T const &);
		void del(T* const &);
		int high(BTNode*);
		int highDiff(BTNode*);
		int max(const int, const int);
		T getMax(BTNode*);
		// int balance(BTNode*);
		BTNode* rotateLeft(BTNode*);
		BTNode* rotateRight(BTNode*);
		BTNode* doubleRotateLeft(BTNode*);
		BTNode* doubleRotateRight(BTNode*);
	public:
		BTNode(const T);
		T getData();
		BTNode<T>* getLeft();
		BTNode<T>* getRight();
        BTNode<T>* remove(const T, BTNode*);
        int getHeight();
        void setHeight(const int);
        void setData(const T);
		void setLeft(BTNode*);
		void setRight(BTNode*);
		BTNode<T>* add(const T, BTNode*);
		void clearList(BTNode*);
		void toString(BTNode*);
		bool find(T);
};

template <class T>
BTNode<T>::BTNode(const T info) : left(NULL), right(NULL), height(1){
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
int BTNode<T>::getHeight(){
	return height;
}

template <class T>
void BTNode<T>::setHeight(const int len){
	height = len;
}

template <class T>
int BTNode<T>::high(BTNode<T>* node){
	if(node == NULL){
		return 0;
	}
	return node->getHeight();
}

template <class T>
int BTNode<T>::highDiff(BTNode<T>* node){
	if(node == NULL){
		return 0;
	}
	return high(node->getLeft()) - high(node->getRight());
}

// template <class T>
// int BTNode<T>::height(BTNode<T>* node){
// 	if(node == NULL){
// 		return 0;
// 	}else{
// 		return 1 + max(height(node->getLeft()), height(node->getRight()));
// 	}
// }

// template <class T>
// int BTNode<T>::balance(BTNode<T>* node){
// 	if(node == NULL){
// 		return 0;
// 	}else{
// 		int lh = height(node->getLeft());
// 		int rh = height(node->getRight());
// 		if(abs(lh - rh) <= 1 && balance(node->getLeft()) == 0 && balance(node->getRight()) == 0)
// 			return 0;
// 		if((lh - rh) < 0)
// 			return -1;
// 		else
// 			return 1;
// 	}
// }
//returns an address to something that holds an address 
//wont break chain since pointer before Holds location of node not whats inside
//for when unbalanced on the right side
template <class T>
BTNode<T>* BTNode<T>::rotateLeft(BTNode<T>* node){
	BTNode<T>* temp = node->getRight();
	node->setRight(temp->getLeft());
	temp->setLeft(node);
	return temp;
}
//for when unbalanced on left side
template <class T>
BTNode<T>* BTNode<T>::rotateRight(BTNode<T>* node){
	BTNode<T>* temp = node->getLeft();
	node->setLeft(temp->getRight());
	temp->setRight(node);
	return temp;
}

template <class T>
BTNode<T>* BTNode<T>::doubleRotateLeft(BTNode<T>* node){
	node->setRight(rotateRight(node->getRight()));
	node = rotateLeft(node);
	return node;
}

template <class T>
BTNode<T>* BTNode<T>::doubleRotateRight(BTNode<T>* node){
	node->setLeft(rotateLeft(node->getLeft()));
	node = rotateRight(node);
	return node;
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
BTNode<T>* BTNode<T>::add(const T info, BTNode<T>* node){
	if(node == NULL){
		return new BTNode<T>(info);
	}else if(info < node->getData()){
		node->setLeft(add(info, node->getLeft()));
	}else{
		node->setRight(add(info, node->getRight()));
	}
	node->setHeight(max(high(node->getLeft()), high(node->getRight())) + 1);
	int diff = highDiff(node);
	if(diff > 1){
		if(highDiff(node->getLeft()) > 0){
			return rotateRight(node);
		}else{
			return doubleRotateRight(node);
		}
	}else if(diff < -1){
		if(highDiff(node->getRight()) < 0){
			return rotateLeft(node);
		}else{
			return doubleRotateLeft(node);
		}
	}else{
		return node;
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
						BTNode<T>* del = remove(temp, right->getLeft());
						return del;
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
				BTNode<T>* del = remove(data, right);
				return del;
			}
			return NULL;
		}else{
			BTNode<T>* left = node->getRight();
			if(left != NULL){
				if(left->getData() == data){
					if(left->getLeft() != NULL && left->getRight() != NULL){
						T temp = getMax(left->getLeft());
						left->setData(temp);
						BTNode<T>* del = remove(temp, left->getLeft());
						return del;
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
				BTNode<T>* del = remove(data, left);
				return del;
			}
			return NULL;
		}
	}
	return NULL;
}

template <class T>
bool BTNode<T>::find(T data) {
    if(data == this->data)
        return true;
    else if(data < this->data) {
        if(left == NULL)
            return false;
        else
            return left->find(data);
    }else{
        if(right == NULL)
            return false;
        else
        	return right->find(data);
    }
}


#endif
