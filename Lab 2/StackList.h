#ifndef STACKLIST_H
#define STACKLIST_H

#include <stddef.h>
#include "List.h"

template <class T>
class Stack{
	private:
		List<T> stack;
	public:
		T pop();
		T get();
		int stackCount();
		void clearStack();
		void push(T data);
		bool isEmpty();
};
#include "StackList.cpp"
#endif