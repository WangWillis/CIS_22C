#ifndef STACKLIST_H
#define STACKLIST_H
#include "List.h"

#include <iostream> 
#include <stddef.h>
using namespace std;

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