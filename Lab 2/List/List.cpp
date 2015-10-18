#include "List.h"
template <class T> 
List<T>::List(){
	ele = 0;
	head = NULL;
}
template <class T>
List<T>::List(T data){
	ele = 0;
	head = newNode(data);
}
template <class T>
List<T>::~List(){
	clearList();
}
template <class T>
int List<T>::countNodes(){
	return ele;
}
template <class T>
T List<T>:: getHeadData(){
	return head->info;
}
template <class T>
void List<T>::addFront(T data){
	ele++;
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
	ele++;
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
	if(head != NULL){
		ele--;
		Data* temp = head;
		head = head->next;
		delete temp;
	}

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
			Data* temp = head;
			Data* bef = NULL;
			for(int i = 0; i < pos; i++){
				bef = temp;
				temp = temp->next;
			}
			bef->next = temp->next;
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
		Data* temp = head;
		head = head->next;
		delete temp;
	}
	ele = 0;
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
