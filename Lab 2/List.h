#ifndef LIST_H
#define LIST_H

#include <iostream> 
#include <stddef.h>
using namespace std;

template <class T>
class List{
	private:	
		struct Data{
			T info;
            Data* next;
		};
		Data* head;
		int ele;
		Data* newNode(T data){
			Data* temp = new Data;
			temp->info = data;
			temp->next = NULL;
			return temp;
		}
	public:
		List();
		List(T data);
		~List();
		int countNodes();
		T getHeadData();
		void addFront(T data);
		void addInfoOrder(T data);
		void delFront();
		void delInfo(T data);
		//pos starts at 0
		void delPos(int pos);
		void clearList();
        void displayList() const;
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
	head = newNode(data);
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
T List<T>:: getHeadData(){


	if(head != NULL){
		return head->info;		
	}else{
		throw "List is Empty";
	}

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
	}else{
		throw "List is Empty";
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

template <class T> 
void List<T>::addAnywhere(T data, int position)
{
	if (position >= 0 && position <= ele){
		Data* nodeptr = head; 
		Data* newnode = newNode(data); 
		Data* prevnode = NULL; 
		if (head == NULL) // case of empty list
 		{
    	    head = newnode;
    	    head -> next = NULL;
       	 return;
    	}
    	if(position == 0 ) // it is the next head
    	{

        	addFront(data);
    	}
    	else  // middle or end of list
    	{
    		for( int i = 1; i < position; i++)
			{
				nodeptr = nodeptr-> next; 
    		}
    		newnode->next = nodeptr-> next;
    		nodeptr -> next = newnode ;
    	}
	}
	return;
}

#endif