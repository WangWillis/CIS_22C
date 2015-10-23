#ifndef NODE_H
#define NODE_H

#include <stddef.h>

//declaring class prototype
template <class T> class Node;

template <class T>
class Node{
	private:
		//store data
		T data;
		//pointer to next node
		Node* next;
	public:
		Node();
		//constructs a node with data in it
		Node(const T data);
		//gets the data from the node
		T getData();
		//sets the data in the node
		void setData(const T info);
		//sets the next pointer
		Node* getNext();
		//gets the next pointer
		void setNext(Node<T>* temp);
};
//default constructor
template <class T>
Node<T>::Node(){
	next = NULL;
}
//constructs a node with data in it
template <class T>
Node<T>::Node(const T info){
	data = info;
	next = NULL;
}
//returns the data in the node
template <class T>
T Node<T>::getData(){
	return data;
}
//gets the data in the node
template <class T>
void Node<T>::setData(const T info){
	data = info;
}
//gets the next pointer
template <class T>
Node<T>* Node<T>::getNext(){
	return next;
}
//sets the next pointer
template <class T>
void Node<T>::setNext(Node* temp){
	next = temp;
}
#endif