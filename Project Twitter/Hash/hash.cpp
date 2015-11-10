//
//  hash.cpp
//  Hash Table
//
//  Created by Randy Manzanares on 11/5/15.
//  Copyright (c) 2015 Randy Manzanares. All rights reserved.
//



#include <iostream>
#include <cstdlib>
#include <string>

#include "hash.h"

using namespace std;

HashTable::HashTable()
{
    for (int i = 0; i < tableSize; i++)
    {
        hashTable[i] = new item;
        hashTable[i]->name = "empty";
        hashTable[i]->drink = "empty";
        hashTable[i]->next = NULL;
    }
}

void HashTable::AddItem(string name, string drink)
{
    int index = Hash(name);
    if(hashTable[index]-> name == "empty")
    {
        hashTable[index]-> name = name;
        hashTable[index]-> drink = drink;
    }
    else
    {
        item * ptr = hashTable[index];
        item * n = new item;
        n->name = name;
        n->drink = drink;
        n->next = NULL;
        
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        //adds the next item at the end of the list
        ptr->next = n;
    
    }

}

int HashTable::NumberOfItemsInIndex(int index)
{
    int count = 0;
    
    if(hashTable[index]->name == "empty")
        return count;
    else
    {
        count++;
        item* Ptr = hashTable[index];
        while(Ptr->next != NULL)
        {
            count++;
            Ptr = Ptr->next;
        
        }
    
    }
    return count;
}

void HashTable::PrintTable()
{
    int number;
    for (int i = 0; i < tableSize; i++)
    {
        //hold the number of items in the i th bucket
        number = NumberOfItemsInIndex(i);
        cout << "----------------\n";
        cout << "index = " << i << endl;
        cout << hashTable[i]->name << endl;
        cout << hashTable[i]->drink << endl;
        cout << "# of items =" << number << endl;
        cout << "----------------\n";
    }


}

void HashTable::PrintItemsInIndex(int index)
{
    item * Ptr = hashTable[index];
    
    if(Ptr -> name == "empty")
        cout << "Bucket = " << index << " is empty" << endl;
    else
    {
        cout << "Bucket = " << index << " contains the following items\n";
        while(Ptr != NULL )
        {
            cout << "-------------------"<< endl;
            cout << Ptr->name << endl;
            cout << Ptr->drink << endl;
            cout << "-------------------"<< endl;
            Ptr = Ptr ->next;
        
        }
    }


}

int HashTable::Hash(string key)
{
    int hash = 0;
    int index;
    
    
    for(int i = 0; i < key.length(); i ++)
    {
        hash = (hash + (int)key[i]) * 17;
       // cout << "hash = " << hash << endl;
    }
    
    index = hash % tableSize;
    //      402/ 100 = 4 R2 
    
    return index;
}

void HashTable::RemoveItem(string name)
{
    //Find the bucket number
    int index = Hash(name);
    
    item* delPtr; //delete pointer
    item* P1;
    item* P2;
    
    // Case 0 - bucket is empty
    if(hashTable[index] -> name == "empty" && hashTable[index]->drink == "empty")
    {
        cout << name << " was not found in the hash table\n";
    }
    // Case 1 - only one item contained in bucket and that item has matching name
    else if (hashTable[index] -> name == name && hashTable[index] -> next == NULL)
    {
        hashTable[index] -> name = "empty";
        hashTable[index] -> drink = "empty";
        
        cout << name << " was removed from the hash table\n";
    
    }
    // Case 2 - match is located in the first item in the bucket but there are more items in the bucket
    else if(hashTable[index] -> name == name)
    {
        delPtr = hashTable[index];
        //now the second item is the first item in the list
        hashTable[index] = hashTable[index]->next;
        delete delPtr;
        
        cout << name << " was removed from the hash table\n";
    
    }
    // Case 3 - the bucket contains items but first item is not a match
    else
    {
        P1 = hashTable[index] -> next;
        P2 = hashTable[index];
    
        // advance through the items
        while ( P1 != NULL && P1-> name != name)
        {
            P2 = P1;
            P1 = P1 -> next;
        }
        // Case 3.1 - no match
        if (P1 == NULL)
        {
            cout << name << " was not found in the hash table\n";
        
        }
        // Case 3.2 - match is found
        else
        {
            delPtr = P1;
            P1 = P1 -> next;
            P2 -> next = P1;
            delete delPtr;
        
            cout << name << " was removed from the hash table\n";
        }
        
    }
}

void HashTable::FindDrink(string name)
{
    int bucket = Hash(name);
    bool foundName = false;
    string drink;
    
    item* Ptr= hashTable[bucket];
    while (Ptr != NULL)
    {
        if (Ptr ->name == name )
        {
            foundName = true;
            drink = Ptr->drink;
        }
        Ptr = Ptr -> next;
    }
    if(foundName == true)
    {
        cout << "Favorite Drink = " << drink << endl;
    
    }
    else
    {
        cout << name << "'s info was not found in the Hash Table\n";
    }
        

}