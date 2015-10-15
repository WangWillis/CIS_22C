#include "List.h"
template <class T>

T List<T>:: getHeadData()
{

	return head->info;

}
List:: addFront(T data)
{

	if (head == NULL) // case of empty list
    {
      	head = new Data();
        head -> info = data ;
		head -> next = NULL;
    }
    else {

	    Data* newnode = new Data();
		newnode -> info = data ;
		newnode -> next = head;
		head = newnode;
    }

}
List:: delFront()
{


}