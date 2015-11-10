//
//  hash.h
//  Hash Table
//
//  Created by Randy Manzanares on 11/5/15.
//  Copyright (c) 2015 Randy Manzanares. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
using namespace std;

#ifndef HASH_H
#define HASH_H
template < class K, class T>
class HashTable{
private:
    static const int tableSize = 50;
    
    struct item{
        string name;
        string drink;
        item * next;
    };
    
    item* hashTable[tableSize];
    
public:
    HashTable();
    int Hash(string key);
    void AddItem(string name, string drink);
    int NumberOfItemsInIndex(int index);
    void PrintTable();
    void PrintItemsInIndex(int index);
    void FindDrink(string name);
    void RemoveItem(string name);

};













#endif /* defined(__Hash_Table__hash__) */
