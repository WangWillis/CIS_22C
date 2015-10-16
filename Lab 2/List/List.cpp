#include "ListStack.h"
template <class T> 
List<T>::List(){
	head = NULL;
}
template <class T>
List<T>::List(T data){
	head = newNode(data);
}
template<class T>
List<T>::~List(){
	clearList();
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
template<class T>
void List<T>::delFront(){
	Data* temp = head;
	head = head->next;
	delete temp;
}
template<class T>
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
        cout << nodeptr->info;
        nodeptr = nodeptr->next;
    }
    return;
}