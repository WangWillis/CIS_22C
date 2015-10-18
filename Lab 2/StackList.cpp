#include "StackList.h"


template <class T> 
T Stack<T> :: pop()
{
	try {
		T temp; 
		temp = stack.getHeadData();
		stack.delFront();
		return temp;
	} catch (const char* exc ) {
			cout << exc << endl;

		}


}

template <class T> 
T Stack<T> :: get()
{
	return stack.getHeadData();
}

template <class T> 
int Stack<T> :: stackCount()
{
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
	if(stack.countNodes == 0){
		return true;
	}
	return false;

}