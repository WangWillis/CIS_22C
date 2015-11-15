#ifndef HNODE_H
#define HNODE_H

#include <stddef.h>
// #include <type_traits>

//declaring class prototype
template <class T> class HashNode;

template <class T>
class HashNode{
	private:
		//store key
		string key;
		//store data
		T data;
		//pointer to next node
		HashNode<T>* next;
		void del(T const&);
		void del(T* const&);
	public:
		HashNode();
		//constructs a node with data in it
		HashNode(const string, const T);
		//destructor for if T is a pointer
		~HashNode();
		//gets the key
		string getKey();
		//gets the data from the node
		T getData();
		//sets the data in the node
		void setData(const string, const T);
		//sets the next pointer
		HashNode<T>* getNext();
		//gets the next pointer
		void setNext(HashNode<T>*);
};

template <class T>
void HashNode<T>::del(T const&){}
//for deleting pointers
template <class T>
void HashNode<T>::del(T* const& data){delete data;}
//default constructor
template <class T>
HashNode<T>::HashNode(){
	next = NULL;
}
//constructs a node with data in it
template <class T>
HashNode<T>::HashNode(const string id, const T info){
	key = id;
	data = info;
	next = NULL;
}
//destructor if T is a pointer
template <class T>
HashNode<T>::~HashNode(){
	del(data);
}
template <class T>
string HashNode<T>::getKey(){
	return key;
}
//returns the data in the node
template <class T>
T HashNode<T>::getData(){
	return data;
}
//gets the data in the node
template <class T>
void HashNode<T>::setData(const string id, const T info){
	key = id;
	data = info;
}
//gets the next pointer
template <class T>
HashNode<T>* HashNode<T>::getNext(){
	return next;
}
//sets the next pointer
template <class T>
void HashNode<T>::setNext(HashNode<T>* temp){
	next = temp;
}
#endif
