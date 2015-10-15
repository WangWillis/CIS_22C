#ifndef LIST_H
#define LIST_H

#include <stddef.h>

template <class T>
class List{
	private:
		// template <class T>
		struct Data{
			T info;
			Data* next;
		};
		Data* head;
	public:
		List();
		List(T data);
		~List();
		T getHeadData();
		void addFront(T data);
		void delFront();
};

#endif