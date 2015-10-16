#include "List.h"
template <class T> 
List<T>::List(){
	head = NULL;
}
template <class T>
List<T>::List(T data){
	head = newNode(data);
}
template <class T>
List<T>::~List(){
	clearList();
}
template <class T>
int List<T>::countNodes(){
	int count = 0;
	Data* temp = head;
	while(temp != NULL){
		temp = temp->next;
		count++;
	}
	return count;
}
template <class T>
T List<T>:: getHeadData(){
	return head->info;
}
template <class T>
void List<T>::addFront(T data){
	// incase of empty list
	if(head == NULL){
      	head = newNode(data);
    }else{
	    Data* temp = newNode(data);
		temp -> next = head;
		head = temp;
    }
}
template <class T>
void List<T>::addInfoOrder(T data){
	Data* temp = head;
	Data* node = newNode(data);
	while(temp->info != data && temp->next != NULL){
		temp = temp->next;
	}
	node->next = temp->next;
	temp->next = node;
}
template <class T>
void List<T>::delFront(){
	Data* temp = head;
	head = head->next;
	delete temp;
}
template <class T>
void List<T>::delInfo(T data){
	Data* temp = head;
	Data* bef = NULL;
	while(temp->info != data && temp != NULL){
		bef = temp;
		temp = temp->next;
	}
	if(temp != NULL){
		if(bef != NULL){
			bef->next = temp->next;
		} else {
			head = NULL;
		}
		delete temp;
	}
}
template <class T>
void List<T>::clearList(){
	while(head){
		Data* temp = head;
		head = head->next;
		delete temp;
	}
	head = NULL;
}
template <class T>
void List<T>::displayList() const
{
    Data* nodeptr;
    nodeptr = head;
    while (nodeptr){
        cout << nodeptr->info << endl;
        nodeptr = nodeptr->next;
    }
    return;
}
