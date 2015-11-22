#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node.h"
#include "Queue.h"

//List class with a head pointer
template <class T>
class List{
	private:
		//data node	
		//point to the front of the list
		Node<T>* head;
		//a count of how many nodes are in the list
		int ele;
	public:
		//list with no initial data
		List();
		//list with first node that has data
		List(const T data);
		~List();
		//counts the nodes
		int countNodes();
		//gets data from the head
		T getHeadData();
		//get data from any position
		//pos starts at 0
		T getDataPos(const int pos);
		T getData(const T);
		Queue<T> toQueue();
		//adds node to front
		void addFront(const T data);
		//adds node next to node of same data
		// void addInfoOrder(T data);
		//deletes node from front
		void delFront();
		//deletes one instance of a certain data
		void delInfo(const T data);
		//deletes data in any position
		//pos starts at 0
		void delPos(const int pos);
		//clears the list
		void clearList();
		//add a node in the beginning, middle, or end of the list given by a choice of the user
		void addAnywhere(const T data, const int position);
};
//constructor
template <class T> 
List<T>::List(){
	ele = 0;
	head = NULL;
}
//constructor which creates a list with a default node
template <class T>
List<T>::List(const T data){
	ele = 0;
	head = new Node<T>(data);
}
//destructor
template <class T>
List<T>::~List(){
	//fucntion clears the list set head to NULL
	clearList();
}
//returns the count of the number of nodes in the list
template <class T>
int List<T>::countNodes(){
	return ele;
}
//returns the data in the head
template <class T>
T List<T>::getHeadData(){
	//check if the list is empty
	if(head != NULL){
		return head->getData();		
	}else{
		throw "List is Empty";
	}
}
//gets data in any position in the list
template <class T>
T List<T>::getDataPos(const int pos){
	//checks if the pos is a valid pos in the list
	//if list was empty ele would be 0
	if(pos >= 0 && pos < ele){
		Node<T>* temp = head;
		for(int i = 0; i < pos; i++){
			temp = temp->getNext();
		}
		return temp->getData();
	}else{
		throw "Not a Valid Position";
	}
}
//inserts a node to the front of the list
template <class T>
void List<T>::addFront(const T data){
	ele++;
	// incase of empty list
	if(head == NULL){
      	head = new Node<T>(data);
    }else{
	    Node<T>* temp = new Node<T>(data);
		temp->setNext(head);
		head = temp;
    }
}
// template <class T>
// void List<T>::addInfoOrder(T data){
// 	ele++;
// 	Node<T>* temp = head;
// 	Node<T>* node = new Node(data);
// 	while(temp->getData() != data && temp->next != NULL){
// 		temp = temp->getNext();
// 	}
// 	node->setNext(temp->getNext());
// 	temp->setNext(node);
// }

//deletes a node from the front of the list
template <class T>
void List<T>::delFront(){
	//makes sure the list isnt empty
	if(head != NULL){
		ele--;
		Node<T>* temp = head;
		head = head->getNext();
		delete temp;
	}else{
		throw "List is Empty";
	}
}
//removes one node which contains certain data
template <class T>
void List<T>::delInfo(const T data){
	Node<T>* temp = head;
	Node<T>* bef = NULL;
	//moves to the right position in the list
	while(temp->getData() != data && temp != NULL){
		bef = temp;
		temp = temp->getNext();
	}
	//checks if the list is empty and if the data is in the list
	if(temp != NULL){
		//if it is not the head node
		if(bef != NULL){
			bef->setNext(temp->getNext());
			ele--;
			delete temp;
		} else {
			delFront();
		}
	}
}
//pos starts at 0
template <class T>
void List<T>::delPos(const int pos){
	//checks if the pos is a valid position
	if(pos >= 0 && pos < ele){
		//position in front is delete the front
		if(pos == 0){
			delFront();
		}else{
			Node<T>* temp = head;
			Node<T>* bef = NULL;
			//iterates till the right spot
			for(int i = 0; i < pos; i++){
				bef = temp;
				temp = temp->getNext();
			}
			//unlinking node
			bef->setNext(temp->getNext());
			delete temp;
		}
		ele--;
	}else{
		throw "Not a Valid Position";
	}
}
//clears the list
template <class T>
void List<T>::clearList(){
	//deletes node in the list
	while(head){
		Node<T>* temp = head;
		head = head->getNext();
		delete temp;
	}
	//resets the instance variables
	ele = 0;
	head = NULL;
}
//add anywhere in the list
template <class T> 
void List<T>::addAnywhere(const T data, const int position)
{
	//checks for a valid position
	if (position >= 0 && position <= ele){
		//if the position is the head
    	if(position == 0){
        	addFront(data);
    	} else {
    		Node<T>* nodeptr = head; 
			Node<T>* newnode = new Node<T>(data); 
			//iterates through the list
    		for( int i = 1; i < position; i++){
				nodeptr = nodeptr->getNext(); 
    		}
    		//adding the node
    		newnode->setNext(nodeptr->getNext());
    		nodeptr->setNext(newnode);
    	}
	}
}

template <class T>
T List<T>::getData(const T data){
	Node<T>* temp = head;
	while(temp != NULL){
		if(temp->getData() == data){
			return temp->getData();
		}
		temp = temp->getNext();
	}
	return data;
}

template <class T>
Queue<T> List<T>::toQueue(){
	Queue<T> tempQ;
	if(this->head != NULL){
		Node<T>* temp = head;
		while(temp->getNext() != NULL){
			tempQ.add(temp->getData());
			temp = temp->getNext();
		}
	}
	return tempQ;
}

#endif