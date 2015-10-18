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