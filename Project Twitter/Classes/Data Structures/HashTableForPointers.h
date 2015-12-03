#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>
#include <fstream>
#include "ContainerForPointers.h"
#include "BinaryTree/BST.h"

template <class T>
class HashTable;
//keys are strings data varies
template <class T>
class HashTable{
	private:
		//the size of the hashtable array
		int tableSize;
		//the table array
		Container<T>* table;
		//holds the keys
		AVLTree<string> keys;
		//hashing function
		unsigned int hash(std::string, Container<T>*);
		//gets the index for a certain key
		unsigned int getIndex(std::string);
		//upsizes the table
		Container<T>* upSize();
		//holds the number of key, data pairs
		int ele, numCol, longCol;
	public:
		//hash table default constructor
		HashTable();
		~HashTable();
		//adds data by key
		void add(std::string, T);
		//removes data by key
		void remove(std::string);
		//display all the keys
		void displayKeys();
		//shows the keys in bst form
		void showIndent();
		//gets the data from a key
		T getData(std::string);
		//checks if the key is used
		bool freeKey(std::string);
		//to get the effeciency of a key
		void efficiency();
		//writes keys to file
		void writeKeys();
};

template <class T>
HashTable<T>::HashTable(){
	//default size 2 times expected ele and prime
	tableSize = 53;
	table = new Container<T> [tableSize];
	ele = 0;
	numCol = 0;
	longCol = 0;
}

template <class T>
HashTable<T>::~HashTable(){
	ofstream out;
	out.open("Users/user.txt", std::fstream::trunc);
	out.close();
	//used to free up the spots where it holds dynamically allocated memeory
	for(int i = 0; i < tableSize; i++){
		if(!table[i].isEmpty()){
			table[i].del();
		}
	}
	//gives back the addresses for the array
	delete [] table;
}
//increase the size
template <class T>
Container<T>* HashTable<T>::upSize(){
	numCol = 0;
	longCol = 0;
	//doubles it cuz want to would do next prime after double though but no list/primes list take too much to generate
	tableSize *= 2;
	Container<T>* temp = new Container<T> [tableSize];
	//rehashes they keys to give them a new index in the new table
	for(int i = 0; i < tableSize/2; i++){
		//only does it for the spots that hold data
		if(!table[i].isEmpty()){
			string key = table[i].getKey();
			unsigned int index = hash(key, temp);
			temp[index].setDataKey(key, table[i].getData());
		}
	}
	//frees up mem for the old table
	delete [] table;
	return temp;
}
//hashing using quadratic hasing
template <class T>
unsigned int HashTable<T>::hash(std::string key, Container<T>* temp){
	//used for number of collisions
	int i = 0;
	unsigned int index = 0;
	//suming up all the char
	for(int j = 0; j < key.size(); j++){
		index += key[j];		
	}
	//mod the table size
	index = index % tableSize;
	//while there are still collisions use quadratic hasing till empty spot
	while(!temp[index].isEmpty()){
		i++;
		index += i*i;
		index = index % tableSize;
	}
	numCol += i;
	if(longCol < i){
		longCol = i;
	}
	return index;
}
//gets the index of a key if the key is used
//only used by class so dont need to check for user messup
template <class T>
unsigned int HashTable<T>::getIndex(std::string key){
	int i = 0;
	unsigned int index = 0;
	for(int j = 0; j < key.size(); j++){
		index += key[j];		
	}
	index = index % tableSize;
	while(!table[index].isEmpty() && table[index].getKey() != key){
		i++;
		index += i*i;
		index = index % tableSize;
	}
	return index;
}
//adds data
template <class T>
void HashTable<T>::add(std::string key, T data){
	//imcrements the number of elements
	ele++;
	//if the number of elemets is greater than HALF of the table size resize
	//something about chance of not hitting a free spot if greater than half
	if(ele > tableSize/2){
		table = upSize();
	}
	//adds the key
	keys.add(key);
	//gets the index and adds the data
	unsigned int index = hash(key, table);
	table[index].setDataKey(key, data);
}
//gets the data
template <class T>
T HashTable<T>::getData(std::string key){
	//gets the index of the data specific to the key
	unsigned int index = getIndex(key);
	//returns the data
	if (!table[index].isEmpty()){
		return table[index].getData();
	}else{
		throw "Not Valid Key";
	}
}
//checks if the key is free
template <class T>
bool HashTable<T>::freeKey(std::string key){
	return !keys.find(key);
}
//removes data from the hash table
template <class T>
void HashTable<T>::remove(std::string key){
	ele--;
	unsigned int index = getIndex(key);
	//deletes data from the hash table
	if(!table[index].isEmpty()){
		table[index].remove();
		keys.remove(key);
		numCol = 0;
		longCol = 0;
		//only way to re-evaluate
		Queue<string> temp;
		keys.toQueue(temp);
		while(!temp.isEmpty()){
			unsigned int trashCan = hash(temp.pop(), table);
		}
	}
}
//prints the indented hash table keys
template <class T>
void HashTable<T>::showIndent(){
	keys.indentPrint();
}
//prints the hash table keys normally 
template <class T>
void HashTable<T>::displayKeys(){
	keys.toString();
}

template <class T>
void HashTable<T>::efficiency(){
	if(ele != 0){
		//average col per ele
		std::cout << "Load Factor: " << 1 + (double)(numCol)/ele << std::endl;
		//total number of col
		std::cout << "Number of Collisions: " << numCol << std::endl;
		//longest col
		std::cout << "Longest Collisions Path: " << longCol << std::endl;
	}else{
		std::cout << "No elemets" << std::endl;
	}
}

template <class T>
void HashTable<T>::writeKeys(){
	ofstream outFile;
    outFile.open("Keys.txt", std::fstream::trunc);
    //print out the keys
    Queue<string> printKey;
    keys.toQueue(printKey);
    while(!printKey.isEmpty())
    {
        outFile << printKey.pop() << endl;
    }
    outFile.close();
}

#endif