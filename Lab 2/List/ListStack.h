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
		T getHeadData();
		void addFront(T data);
		void delFront();
		void clearList();
        void displayList() const;
};
#include "ListStack.cpp"
#endif