#ifndef HASH_H
#define HASH_H

#include <stdlib.h>
#include <string>
#include "HashList\HashList.h"
#include "BinaryTree\BST.h"

using namespace std;

static const int TABLESIZE = 50;

template <class T>
class HashTable;

template <class T>
class HashTable{
private:
    
    HashList<T>* hashTable[TABLESIZE];
    AVLTree<string> keys;
    unsigned int hash(string);
public:
    HashTable();
    ~HashTable();
    Queue<string> getKeys();
    T getData(string key);
    bool inSet(string key);
    void addItem(string key, T data);
    void removeItem(string key);
};

template <class T>
HashTable<T>::HashTable(){
    for(int i = 0; i < TABLESIZE; i++){
        hashTable[i] = NULL;
    }
}

template <class T>
HashTable<T>::~HashTable(){
    for(int i = 0; i < TABLESIZE; i++){
        if(hashTable[i] != NULL){
            delete hashTable[i];
            hashTable[i] == NULL;
        }
    }
}

template <class T>
unsigned int HashTable<T>::hash(string key){
    int hash = 0;
    for(int i = 0; i < key.length(); i ++)
    {
        hash = (hash + (int)key[i]) * 17;
    }
    return hash % TABLESIZE;
    //      402/ 100 = 4 R2 
}

template <class T>
bool HashTable<T>::inSet(string key){
    return keys.find(key);
}

template <class T>
void HashTable<T>::addItem(string key, T data){
    unsigned int index = hash(key);
    if(hashTable[index] == NULL){
        hashTable[index] = new HashList<T>();
    }
    keys.add(key);
    hashTable[index]->addToSet(key, data);
}

template <class T>
T HashTable<T>::getData(string key){
    unsigned int index = hash(key);
    if(hashTable[index] != NULL){
        return hashTable[index]->getDataKey(key);
    }else{
        throw "Invalid Key";
    }
}

template <class T>
void HashTable<T>::removeItem(string key){
    unsigned int index = hash(key);
    if(hashTable[index] != NULL){
        keys.remove(key);
        hashTable[index]->delWithKey(key);
    }else{
        throw "Invalid Key";
    }
}

template <class T>
Queue<string> HashTable<T>::getKeys(){
    return keys.toQueue();
}

#endif