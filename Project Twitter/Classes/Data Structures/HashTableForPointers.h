#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>
#include "ContainerForPointers.h"
#include "BinaryTree/BST.h"

template <class T>
class HashTable;

template <class T>
class HashTable{
	private:
		int tableSize;
		Container<T>* table;
		AVLTree<string> keys;
		unsigned int hash(std::string, Container<T>*);
		unsigned int getIndex(std::string);
		Container<T>* upSize();
		int ele;
	public:
		HashTable();
		~HashTable();
		void add(std::string, T);
		void remove(std::string);
		void displayKeys();
		T getData(std::string);
		bool freeKey(std::string);
};

template <class T>
HashTable<T>::HashTable(){
	tableSize = 53;
	table = new Container<T> [tableSize];
	ele = 0;
}

template <class T>
HashTable<T>::~HashTable(){
	for(int i = 0; i < tableSize; i++){
		if(!table[i].isEmpty()){
			table[i].del();
		}
	}
	delete [] table;
}

template <class T>
Container<T>* HashTable<T>::upSize(){
	tableSize *= 2;
	Container<T>* temp = new Container<T> [tableSize];
	for(int i = 0; i < tableSize/2; i++){
		if(!table[i].isEmpty()){
			string key = table[i].getKey();
			unsigned int index = hash(key, temp);
			temp[index].setDataKey(key, table[i].getData());
		}
	}
	delete [] table;
	return temp;
}

template <class T>
unsigned int HashTable<T>::hash(std::string key, Container<T>* temp){
	int i = 1;
	unsigned int index = 0;
	for(int j = 0; j < key.size(); j++){
		index += key[j];		
	}
	index = index % tableSize;
	while(!temp[index].isEmpty()){
		index += i*i;
		index = index % tableSize;
		i++;
	}
	return index;
}

template <class T>
unsigned int HashTable<T>::getIndex(std::string key){
	int i = 1;
	unsigned int index = 0;
	for(int j = 0; j < key.size(); j++){
		index += key[j];		
	}
	index = index % tableSize;
	while(!table[index].isEmpty() && table[index].getKey() != key){
		index += i*i;
		index = index % tableSize;
	}
	return index;
}

template <class T>
void HashTable<T>::add(std::string key, T data){
	ele++;
	if(ele > tableSize/2){
		table = upSize();
	}
	keys.add(key);
	unsigned int index = hash(key, table);
	table[index].setDataKey(key, data);
}

template <class T>
T HashTable<T>::getData(std::string key){
	unsigned int index = getIndex(key);
	if (!table[index].isEmpty())
	{
		return table[index].getData();
	}
	else
	{
		//I think we need something here
	}
}

template <class T>
bool HashTable<T>::freeKey(std::string key){
	return !keys.find(key);
}

template <class T>
void HashTable<T>::remove(std::string key){
	ele--;
	unsigned int index = getIndex(key);
	if(!table[index].isEmpty())
		table[index].remove();
}

template <class T>
void HashTable<T>::displayKeys(){
	keys.toString();
}

#endif