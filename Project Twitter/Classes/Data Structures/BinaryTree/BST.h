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
	//holds the root
	BTNode<T>* head;
	//rotates the subtree left
	BTNode<T>* rotateLeft(BTNode<T>*);
	//rotates subtree right
	BTNode<T>* rotateRight(BTNode<T>*);
	//recursive add function
	BTNode<T>* add(const T, BTNode<T>*);
	//recursice remove fucntion
	BTNode<T>* remove(const T, BTNode<T>*);
	//to balance the tree
	BTNode<T>* balance(BTNode<T>*);
	//recursive queue functiom
	void toQueue(Queue<T>&, BTNode<T>*);
	//recursive gets data
	T get(const T, BTNode<T>*);
	//gets the "biggest" data in the subtree
	T getMax(BTNode<T>*);
	//recursive find
	bool find(const T, BTNode<T>*);
	//finds the hight of the tree
	int high(BTNode<T>*);
	//gets the hight diff in the tree negative if right heavy positive if left
	int highDiff(BTNode<T>*);
	//max between two ints
	int max(const int, const int);
	//clears the tree
	void clearList(BTNode<T>*);
	//in order tree traversal printing
	void toString(BTNode<T>*);
	//prints how the tree looks
	void indentPrint(string, BTNode<T>*);
public:
	//default constructor
	AVLTree();
	//constructor with head node that has data
	AVLTree(T);
	//clears the tree
	~AVLTree();
	//gets data
	T get(const T);
	//give a stream of the tree data
	void toQueue(Queue<T>&);
	//finds if data is in this tree
	bool find(const T);
	//adds data
	void add(const T);
	//removes data
	void remove(const T);
	//inorder outputing
	void toString();
	//displays the tree like a tree ish
	void indentPrint();
};
//sets head to null
template <class T>
AVLTree<T>::AVLTree(){
	head = NULL;
}
//gives the head new data
template <class T>
AVLTree<T>::AVLTree(T data){
	head = new BTNode<T>(data);
}
//clears the tree
template <class T>
AVLTree<T>::~AVLTree(){
	clearList(head);
}
//clears going all the way to the left then right
template <class T>
void AVLTree<T>::clearList(BTNode<T>* node){
	if (node != NULL){
		//go down left
		if (node->getLeft() != NULL){
			clearList(node->getLeft());
		}
		//go down right
		if (node->getRight() != NULL){
			clearList(node->getRight());
		}
		//set children to NULL just cuz
		node->setLeft(NULL);
		node->setRight(NULL);
		//remove the node
		delete node;
	}
}
//gets the max of two ints
template<class T>
int AVLTree<T>::max(const int a, const int b){
	if (a > b)
		return a;
	return b;
}
//gets the height of the tree
template <class T>
int AVLTree<T>::high(BTNode<T>* node){
	if (node == NULL){
		return 0;
	}
	return node->getHeight();
}
//gets the hight difference of the tree
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
	//"rotation"
	BTNode<T>* temp = node->getRight();
	node->setRight(temp->getLeft());
	temp->setLeft(node);
	//redo the heights
	node->setHeight(max(high(node->getLeft()), high(node->getRight())) + 1);
	temp->setHeight(max(high(temp->getLeft()), high(temp->getRight())) + 1);
	return temp;
}
//for when unbalanced on left side
template <class T>
BTNode<T>* AVLTree<T>::rotateRight(BTNode<T>* node){
	//"rotation"
	BTNode<T>* temp = node->getLeft();
	node->setLeft(temp->getRight());
	temp->setRight(node);
	//redo the heights
	node->setHeight(max(high(node->getLeft()), high(node->getRight())) + 1);
	temp->setHeight(max(high(temp->getLeft()), high(temp->getRight())) + 1);
	return temp;
}
//get the biggest node in subtree for remove function
template <class T>
T AVLTree<T>::getMax(BTNode<T>* node){
	if (node->getRight() == NULL){
		return node->getData();
	}else{
		return getMax(node->getRight());
	}
}
//balances the tree
template <class T>
BTNode<T>* AVLTree<T>::balance(BTNode<T>* node){
	int diff = highDiff(node);
	//left unbalanced
	if (diff > 1){
		if (highDiff(node->getLeft()) > 0){
			return rotateRight(node);
		}else{//double rotations
			node->setLeft(rotateLeft(node->getLeft()));
			return rotateRight(node);
		}
	}else if (diff < -1){//right unbalanced
		if (highDiff(node->getRight()) < 0){
			return rotateLeft(node);
		}else{//double rotations
			node->setRight(rotateRight(node->getRight()));
			return rotateLeft(node);
		}
	}
	//if already balanced
	return node;
}
//add data
template <class T>
BTNode<T>* AVLTree<T>::add(const T info, BTNode<T>* node){
	//if nothing in tree
	if(node == NULL){
		return new BTNode<T>(info);
	}else if (info < node->getData()){//if data is less than node go left
		node->setLeft(add(info, node->getLeft()));
	}else{//go right otherwise
		node->setRight(add(info, node->getRight()));
	}
	//reset the hights 
	node->setHeight(max(high(node->getLeft()), high(node->getRight())) + 1);
	//re balanced
	return balance(node);
}
//add public funtion
template <class T>
void AVLTree<T>::add(const T data){
	head = add(data, head);
}
//removes data
template <class T>
BTNode<T>* AVLTree<T>::remove(const T data, BTNode<T>* node){
	//when the data is found
	if (node->getData() == data){
		//for the case node has 2 children
		if (node->getLeft() != NULL && node->getRight() != NULL){
			//gets the max data
			T temp = getMax(node->getLeft());
			//copy's it to the current node
			node->setData(temp);
			//remove the other node that had max data
			node->setLeft(remove(temp, node->getLeft()));
			//rebalance and readjust height
			node->setHeight(max(high(node->getLeft()), high(node->getRight())) + 1);
			return balance(node);
		}else if (node->getLeft() != NULL){//when only one child
			BTNode<T>* left = node->getLeft();
			delete node;
			//dont need to rebalance since rebalencing comes in recursive unwind
			return left;
		}else if (node->getRight() != NULL){//when only one child
			BTNode<T>* right = node->getRight();
			delete node;
			return right;
		}else{//when no children takes care of root case as well
			delete node;
			return NULL;
		}
	}else if (data < node->getData() && node->getLeft() != NULL){//moves to the left
		node->setLeft(remove(data, node->getLeft()));
		//balances in revursive unwind
		node->setHeight(max(high(node->getLeft()), high(node->getRight())) + 1);
		return balance(node);
	}else if (node->getRight() != NULL){//moves to the right
		node->setRight(remove(data, node->getRight()));
		//balances in recursive unwind
		node->setHeight(max(high(node->getLeft()), high(node->getRight())) + 1);
		return balance(node);
	}else{//data not found case
		return node;
	}
}
//removes data
template <class T>
void AVLTree<T>::remove(const T data){
	if(head != NULL){
		head = remove(data, head);
	}
}
//finds data
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
//find data driver
template <class T>
bool AVLTree<T>::find(const T data){
	return find(data, head);
}
//inorder output
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
//toString driver
template <class T>
void AVLTree<T>::toString(){
	toString(head);
}
//gets data
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
//get driver
template <class T>
T AVLTree<T>::get(const T data){
	return get(data, head);
}
//queue
template <class T>
void AVLTree<T>::toQueue(Queue<T>& queue, BTNode<T>* node){
	//makes sure node is not NULL
	if(node != NULL){
		//in order traversal
		if (node->getLeft() != NULL){
			toQueue(queue, node->getLeft());
		}
		//adds to queue
		queue.add(node->getData());
		if (node->getRight() != NULL){
			toQueue(queue, node->getRight());
		}
	}
}
//creates a queue
template <class T>
void AVLTree<T>::toQueue(Queue<T>& temp){
	toQueue(temp, head);
}
//prints the bst like a bst
template <class T>
void AVLTree<T>::indentPrint(string indent, BTNode<T>* node){
	if(node != NULL){
		cout << indent << node->getData() << endl;
		indent = indent + " ";
		if(node->getLeft() != NULL){
			indentPrint(indent, node->getLeft());
		}
		if(node->getRight() != NULL){
			indentPrint(indent, node->getRight());
		}
	}
}
//driver
template <class T>
void AVLTree<T>::indentPrint(){
	indentPrint("", head);
}

#endif
