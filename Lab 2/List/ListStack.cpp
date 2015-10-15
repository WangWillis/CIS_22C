#include "ListStack.h"

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