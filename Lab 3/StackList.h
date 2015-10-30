#ifndef STACKLIST_H
#define STACKLIST_H


#include <iostream>
#include "List.h"

template <class T>
class Stack{
	private:
		//list that holds the stack together
		List<T> stack;
	public:
		//removes and returns the last thing added
		T pop();
		//gets the data of the last thing added
		T get();
		//how many things are in the stack
		int stackCount();
		//clears the stack
		void clearStack();
		//adds to top of the stack
		void push(const T data);
		//checks if the stack is empty
		bool isEmpty();
};
//removes the top and returns it
template <class T> 
T Stack<T>::pop(){
	//checks if it is a valid pop i.e. stack is not empty
	try{
		T temp; 
		temp = stack.getHeadData();
		stack.delFront();
		return temp;
	} catch (const char* exc ) {
		std::cout << exc << std::endl;
	}
}
//gets the data from the top
template <class T> 
T Stack<T>::get(){
	//checks if stack is not empty 
	try{
		return stack.getHeadData();
	} catch(const char* exc) {
		std::cout << exc << std::endl;
	}
}
//returns the elements in the stack
template <class T> 
int Stack<T>::stackCount(){
	return stack.countNodes();
}
//clears the stack
template <class T>
void Stack<T>::clearStack(){
	stack.clearList();
}
//adds an element to the stack
template <class T>
void Stack<T>::push(const T data){
	stack.addFront(data);
}
//checks if the stack is empty
template <class T>
bool Stack<T>::isEmpty(){
	//if num nodes is 0 it is empty
	if(stack.countNodes() == 0){
		return true;
	}
	return false;
}

#endif