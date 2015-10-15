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
            struct Data* next;

		};
		Data* head;
	public:
		List();
		List(T data);
		~List();
		T getHeadData();
		void addFront(T data);
		void delFront();
        void displayList() const;
};

#endif