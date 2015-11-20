#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include "Container.h"
#include "BinaryTree/BST.h"

template <class T>
class HashTable;

template <class T>
class HashTable{
	private:
		int tableSize;
		Container<T>* table;
		AVLTree<string> keys;
		unsigned int hash(std::string);
		unsigned int getIndex(std::string);
		Container<T>* upSize();
		int ele;
	public:
		HashTable();
		~HashTable();
		void add(std::string, T);
		void remove(std::string);
		T getData(std::string);
		bool freeKey(std::string);
};

template <class T>
HashTable<T>::HashTable(){
	tableSize = 10;
	table = new Container<T> [tableSize];
	ele = 0;
}

template <class T>
HashTable<T>::~HashTable(){
	// for(int i = 0; i < tableSize; i++){
	// 	if(!table[i].isEmpty()){
	// 		delete &table[i];
	// 	}
	// }
	delete [] table;
}

template <class T>
Container<T>* HashTable<T>::upSize(){
	tableSize *= 2;
	Container<T>* temp = new Container<T> [tableSize];
	for(int i = 0; i < tableSize/2; i++){
		unsigned int index = hash(table[i].getKey());
		temp[index].setDataKey(table[i].getKey(), table[i].getData());
	}
	for(int i = 0; i < tableSize/2; i++){
		if(!table[i].isEmpty()){
			delete &table[i];
		}
	}
	return temp;
}

template <class T>
unsigned int HashTable<T>::hash(std::string key){
	int i = 1;
	unsigned int index = 0;
	for(int j = 0; j < key.size(); j++){
		index += key[j];		
	}
	index = index % tableSize;
	while(!table[index].isEmpty()){
		index += i*i;
		index = index % tableSize;
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
	if(ele > tableSize){
		table = upSize();
	}
	keys.add(key);
	unsigned int index = hash(key);
	table[index].setDataKey(key, data);
}

template <class T>
T HashTable<T>::getData(std::string key){
	unsigned int index = getIndex(key);
	if(!table[index].isEmpty())
		return table[index].getData();
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

#endif