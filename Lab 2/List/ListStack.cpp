
#include "ListStack.h"

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

template <class T>
T List<T>:: getHeadData()
{

	return head->info;

}
template <class T>
void List<T>::addFront(T data)
{

	if (head == NULL) // case of empty list
    {
      	head = new Data();
        head -> info = data ;
		head -> next = NULL;
    }
    else {

	    Data* newnode = new Data();
		newnode -> info = data ;
		newnode -> next = head;
		head = newnode;
    }

}

template <class T> 
List<T>::List(){
	head = NULL;
	head->next = NULL;
}
template <class T>
List<T>::List(T data){
	head = new Data();
	head->info = data;
	head->next = NULL;
}
template<class T>
List<T>::~List(){
	while(head){
		List temp = head;
		head = head->next;
		delete temp;
	}
}
template<class T>
void List<T>::delFront(){
	Data* temp = head;
	head = head->next;
	delete temp;

}