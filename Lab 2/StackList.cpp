#include "StackList.h"

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
	if(stack.countNodes == 0){
		return true;
	}
	return false;
}