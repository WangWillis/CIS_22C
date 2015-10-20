#ifndef NODE_H
#define NODE_H

#include <stddef.h>

template <class T> class Node;

template <class T>
class Node{
	private:
		T data;
		Node* next;
	public:
		Node();
		Node(T data);
		T getData();
		void setData(T info);
		Node* getNext();
		void setNext(Node<T>* temp);
};

template <class T>
Node<T>::Node(){
	next = NULL;
}
template <class T>
Node<T>::Node(T info){
	data = info;
	next = NULL;
}
template <class T>
T Node<T>::getData(){
	return data;
}
template <class T>
void Node<T>::setData(T info){
	data = info;
}
template <class T>
Node<T>* Node<T>::getNext(){
	return next;
}
template <class T>
void Node<T>::setNext(Node* temp){
	next = temp;
}

#endif