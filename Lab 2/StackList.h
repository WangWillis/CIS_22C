#ifndef STACKLIST_H
#define STACKLIST_H


#include <iostream>
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

template <class T> 
T Stack<T>::pop(){
	try{
		T temp; 
		temp = stack.getHeadData();
		stack.delFront();
		return temp;
	} catch (const char* exc ) {
		cout << exc << endl;
	}
}

template <class T> 
T Stack<T>::get(){
	try{
		return stack.getHeadData();
	} catch(const char* exc) {
		cout << exc << endl;
	}
}

template <class T> 
int Stack<T>::stackCount(){
	return stack.countNodes();
}

template <class T>
void Stack<T>::clearStack(){
	stack.clearList();
}
template <class T>
void Stack<T>::push(T data){
	stack.addFront(data);
}

template <class T>
bool Stack<T>::isEmpty(){
	if(stack.countNodes() == 0){
		return true;
	}
	return false;
}

#endif