#ifndef Container_H
#define Container_H

#include <string>

//container for the hash table
template <class T>
class Container{
	private:
		//holds a key
		std::string key;
		//holds data
		T data;
		//check to see if this holds valid data
		bool empty;
	public:
		//defalut constructor
		Container();
		//frees the mem
		void del();
		//gets the data
		T getData() const;
		//gets the key
		std::string getKey() const;
		//frees the container
		void remove();
		//sets key and data
		void setDataKey(std::string, T);
		//checks to see if empty container
		bool isEmpty() const;
};
//frees up dynamic memeory
template <class T>
void Container<T>::del(){
	delete data;
}
//defaults empty as true
template <class T>
Container<T>::Container(){
	empty = true;
}
//gets the data
template <class T>
T Container<T>::getData() const{
	if(!empty)
		return data;
}
//gets the key
template <class T>
std::string Container<T>::getKey() const{
	if(!empty)
		return key;
}
//sets the data and they key and fills container
template <class T>
void Container<T>::setDataKey(std::string key, T data){
	this->key = key;
	this->data = data;
	empty = false;
}
//checks to see if container is empty
template <class T>
bool Container<T>::isEmpty() const{
	return empty;
}
//removes the data
template <class T>
void Container<T>::remove(){
	//returns the memory
	del();
	//frees up the container
	empty = true;
}

#endif