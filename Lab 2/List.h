#ifndef LIST_H
#define LIST_H

#include "Node.h"

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
		List(T data);
		~List();
		//counts the nodes
		int countNodes();
		//gets data from the head
		T getHeadData();
		//get data from any position
		//pos starts at 0
		T getDataPos(int pos);
		//adds node to front
		void addFront(T data);
		//adds node next to node of same data
		void addInfoOrder(T data);
		//deletes node from front
		void delFront();
		//deletes one instance of a certain data
		void delInfo(T data);
		//deletes data in any position
		//pos starts at 0
		void delPos(int pos);
		//clears the list
		void clearList();
        void addAnywhere(T data, int position);
};

template <class T> 
List<T>::List(){
	ele = 0;
	head = NULL;
}
template <class T>
List<T>::List(T data){
	ele = 0;
	head = new Node<T>(data);
}
template <class T>
List<T>::~List(){
	clearList();
}
template <class T>
int List<T>::countNodes(){
	return ele ;
}
template <class T>
T List<T>::getHeadData(){
	if(head != NULL){
		return head->getData();		
	}else{
		throw "List is Empty";
	}
}
template <class T>
T List<T>::getDataPos(int pos){
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
template <class T>
void List<T>::addFront(T data){
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
// 	while(temp->info != data && temp->next != NULL){
// 		temp = temp->getNext();
// 	}
// 	node->setNext(temp->getNext());
// 	temp->setNext(node);
// }
template <class T>
void List<T>::delFront(){
	if(head != NULL){
		ele--;
		Node<T>* temp = head;
		head = head->getNext();
		delete temp;
	}else{
		throw "List is Empty";
	}

}
template <class T>
void List<T>::delInfo(T data){
	Node<T>* temp = head;
	Node<T>* bef = NULL;
	while(temp->info != data && temp != NULL){
		bef = temp;
		temp = temp->getNext();
	}
	if(temp != NULL){
		if(bef != NULL){
			bef->setNext(temp->getNext());
		} else {
			head = NULL;
		}
		ele--;
		delete temp;
	}
}
//pos starts at 0
template <class T>
void List<T>::delPos(int pos){
	if(pos >= 0 && pos < ele){
		if(pos == 0){
			delFront();
		}else{
			Node<T>* temp = head;
			Node<T>* bef = NULL;
			for(int i = 0; i < pos; i++){
				bef = temp;
				temp = temp->getNext();
			}
			bef->setNext(temp->getNext());
			delete temp;
		}
		ele--;
	}else{
		throw "Not a Valid Position";
	}
}
template <class T>
void List<T>::clearList(){
	while(head){
		Node<T>* temp = head;
		head = head->getNext();
		delete temp;
	}
	ele = 0;
	head = NULL;
}
template <class T> 
void List<T>::addAnywhere(T data, int position)
{
	if (position >= 0 && position <= ele){
		
		if (head == NULL) // case of empty list
 		{
    	    head = new Node<T>(data);
    	}
    	else if(position == 0) // it is the next head
    	{
        	addFront(data);
    	}
    	else  // middle or end of list
    	{
    		Node<T>* nodeptr = head; 
			Node<T>* newnode = new Node<T>(data); 
    		for( int i = 1; i < position; i++)
			{
				nodeptr = nodeptr->getNext(); 
    		}
    		newnode->setNext(nodeptr->getNext());
    		nodeptr->setNext(newnode);
    	}
	}
}

#endif