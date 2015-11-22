#ifndef BST_H
#define BST_H

#include <iostream>
#include "BTNode.h"
#include "List&Queue/List.h"
#include "List&Queue/Queue.h"

using namespace std;

template <class T>
class AVLTree;

template <class T>
class AVLTree{
private:
	BTNode<T>* head;
	BTNode<T>* rotateLeft(BTNode<T>*);
	BTNode<T>* rotateRight(BTNode<T>*);
	BTNode<T>* add(const T, BTNode<T>*);
	BTNode<T>* remove(const T, BTNode<T>*);
	BTNode<T>* balance(BTNode<T>*);
	Queue<T>* toQueue(Queue<T>*, BTNode<T>*);
	T get(const T, BTNode<T>*);
	T getMax(BTNode<T>*);
	bool find(const T, BTNode<T>*);
	int high(BTNode<T>*);
	int highDiff(BTNode<T>*);
	int max(const int, const int);
	void clearList(BTNode<T>*);
	void toString(BTNode<T>*);
public:
	AVLTree();
	AVLTree(T);
	~AVLTree();
	T get(const T);
	Queue<T> toQueue();
	bool find(const T);
	void add(const T);
	void remove(const T);
	void toString();
};

template <class T>
AVLTree<T>::AVLTree(){
	head = NULL;
}

template <class T>
AVLTree<T>::AVLTree(T data){
	head = new BTNode<T>(data);
}

template <class T>
AVLTree<T>::~AVLTree(){
	clearList(head);
}

template <class T>
void AVLTree<T>::clearList(BTNode<T>* node){
	if (node != NULL){
		if (node->getLeft() != NULL){
			clearList(node->getLeft());
		}
		if (node->getRight() != NULL){
			clearList(node->getRight());
		}
		node->setLeft(NULL);
		node->setRight(NULL);
		delete node;
	}
}

template<class T>
int AVLTree<T>::max(const int a, const int b){
	if (a > b)
		return a;
	return b;
}

template <class T>
int AVLTree<T>::high(BTNode<T>* node){
	if (node == NULL){
		return 0;
	}
	return node->getHeight();
}

template <class T>
int AVLTree<T>::highDiff(BTNode<T>* node){
	if (node == NULL){
		return 0;
	}
	return high(node->getLeft()) - high(node->getRight());
}

//for unblanaced on right side
template <class T>
BTNode<T>* AVLTree<T>::rotateLeft(BTNode<T>* node){
	BTNode<T>* temp = node->getRight();
	node->setRight(temp->getLeft());
	temp->setLeft(node);
	node->setHeight(max(high(node->getLeft()), high(node->getRight())) + 1);
	temp->setHeight(max(high(temp->getLeft()), high(temp->getRight())) + 1);
	return temp;
}
//for when unbalanced on left side
template <class T>
BTNode<T>* AVLTree<T>::rotateRight(BTNode<T>* node){
	BTNode<T>* temp = node->getLeft();
	node->setLeft(temp->getRight());
	temp->setRight(node);
	node->setHeight(max(high(node->getLeft()), high(node->getRight())) + 1);
	temp->setHeight(max(high(temp->getLeft()), high(temp->getRight())) + 1);
	return temp;
}

template <class T>
T AVLTree<T>::getMax(BTNode<T>* node){
	if (node->getRight() == NULL){
		return node->getData();
	}
	else{
		return getMax(node->getRight());
	}
}

template <class T>
BTNode<T>* AVLTree<T>::balance(BTNode<T>* node){
	int diff = highDiff(node);
	if (diff > 1){
		if (highDiff(node->getLeft()) > 0){
			return rotateRight(node);
		}
		else{
			node->setLeft(rotateLeft(node->getLeft()));
			return rotateRight(node);
		}
	}
	else if (diff < -1){
		if (highDiff(node->getRight()) < 0){
			return rotateLeft(node);
		}
		else{
			node->setRight(rotateRight(node->getRight()));
			return rotateLeft(node);
		}
	}
	return node;
}

template <class T>
BTNode<T>* AVLTree<T>::add(const T info, BTNode<T>* node){
	if (node == NULL){
		return new BTNode<T>(info);
	}
	else if (info < node->getData()){
		node->setLeft(add(info, node->getLeft()));
	}
	else{
		node->setRight(add(info, node->getRight()));
	}
	node->setHeight(max(high(node->getLeft()), high(node->getRight())) + 1);
	return balance(node);
}

template <class T>
void AVLTree<T>::add(const T data){
	head = add(data, head);
}

template <class T>
BTNode<T>* AVLTree<T>::remove(const T data, BTNode<T>* node){
	if (node->getData() == data){
		if (node->getLeft() != NULL && node->getRight() != NULL){
			T temp = getMax(node->getLeft());
			node->setData(temp);
			node->setLeft(remove(temp, node->getLeft()));
			node->setHeight(max(high(node->getLeft()), high(node->getRight())) + 1);
			return balance(node);
		}
		else if (node->getLeft() != NULL){
			BTNode<T>* left = node->getLeft();
			delete node;
			return left;
		}
		else if (node->getRight() != NULL){
			BTNode<T>* right = node->getRight();
			delete node;
			return right;
		}
		else{
			delete node;
			return NULL;
		}
	}
	else if (data < node->getData() && node->getLeft() != NULL){
		node->setLeft(remove(data, node->getLeft()));
		node->setHeight(max(high(node->getLeft()), high(node->getRight())) + 1);
		return balance(node);
	}
	else if (node->getRight() != NULL){
		node->setRight(remove(data, node->getRight()));
		node->setHeight(max(high(node->getLeft()), high(node->getRight())) + 1);
		return balance(node);
	}
	else{
		return node;
	}
}

template <class T>
void AVLTree<T>::remove(const T data){
	if(head != NULL){
		head = remove(data, head);
	}
}

template <class T>
bool AVLTree<T>::find(const T data, BTNode<T>* node){
	if (node != NULL){
		if (node->getData() == data){
			return true;
		}
		else if (node->getData() < data){
			return find(data, node->getRight());
		}
		else{
			return find(data, node->getLeft());
		}
	}
	return false;
}

template <class T>
bool AVLTree<T>::find(const T data){
	return find(data, head);
}

template <class T>
void AVLTree<T>::toString(BTNode<T>* node){
	if (node != NULL){
		if (node->getLeft() != NULL){
			toString(node->getLeft());
		}
		cout << node->getData() << std::endl;
		if (node->getRight() != NULL){
			toString(node->getRight());
		}
	}
}

template <class T>
void AVLTree<T>::toString(){
	toString(head);
}

template <class T>
T AVLTree<T>::get(const T data, BTNode<T>* node){
	if (node != NULL){
		if (data == node->getData()){
			return node->getData();
		}
		else if (data < node->getData()){
			return get(data, node->getLeft());
		}
		else{
			return get(data, node->getRight());
		}
	}
	return data;
}

template <class T>
T AVLTree<T>::get(const T data){
	return get(data, head);
}

template <class T>
Queue<T>* AVLTree<T>::toQueue(Queue<T>* queue, BTNode<T>* node){
	if (node->getLeft() != NULL){
		queue = toQueue(queue, node->getLeft());
	}
	queue->add(node->getData());
	if (node->getRight() != NULL){
		queue = toQueue(queue, node->getRight());
	}
	return queue;
}

template <class T>
Queue<T> AVLTree<T>::toQueue(){
	Queue<T> temp;
	Queue<T>* queue = new Queue<T>();
	temp = *toQueue(queue, head);
	delete queue;
	return temp;
}

#endif
