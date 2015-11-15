#ifndef HLIST_H
#define HLIST_H

#include <iostream>
#include "HashNode.h"

//List class with a head pointer
template <class T>
class HashList{
	private:
		//data node	
		//point to the front of the list
		HashNode<T>* head;
		HashNode<T>* tail;
		//a count of how many nodes are in the list
		int ele;
	public:
		//list with no initial data
		HashList();
		~HashList();
		//counts the nodes
		int countNodes();
		//get data from any position
		T getDataKey(const string);
		void addToSet(const string, const T);
		void delWithKey(const string);
		void clearList();
};
//constructor
template <class T> 
HashList<T>::HashList(){
	ele = 0;
	head = NULL;
	tail = NULL;
}
//destructor
template <class T>
HashList<T>::~HashList(){
	//fucntion clears the list set head to NULL
	clearList();
}
template <class T>
T HashList<T>::getDataKey(const string key){
	HashNode<T>* temp = head;
	while(temp->getKey() != key && temp != NULL){
		temp = temp->getNext();
	}
	if(temp != NULL){
		return temp->getData();		
	}else{
		throw "Not Valid key";
	}
}

template <class T>
void HashList<T>::addToSet(const string key, const T data){
	if(head == NULL){
		head = new HashNode<T> (key, data);
		tail = head;
	}else{
		tail->setNext(new HashNode<T>(key,data));
		tail = tail->getNext();
	}
}

//removes one node which contains certain data
template <class T>
void HashList<T>::delWithKey(const string key){
	HashNode<T>* temp = head;
	HashNode<T>* bef = NULL;
	//moves to the right position in the list
	while(temp->getKey() != key && temp != NULL){
		bef = temp;
		temp = temp->getNext();
	}
	//checks if the list is empty and if the data is in the list
	if(temp != NULL){
		//if it is not the head node
		if(bef != NULL){
			bef->setNext(temp->getNext());
		} else {
			head = head->getNext();
		}
		if(temp->getNext() == NULL){
			tail = bef;
		}
		ele--;
		delete temp;
	}
}
//clears the list
template <class T>
void HashList<T>::clearList(){
	//deletes node in the list
	while(head){
		HashNode<T>* temp = head;
		head = head->getNext();
		delete temp;
	}
	//resets the instance variables
	ele = 0;
	head = NULL;
	tail = NULL;
}

#endif
