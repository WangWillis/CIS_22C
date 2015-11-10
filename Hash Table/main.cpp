//
//  main.cpp
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

int main()
{
    HashTable Hashy;
    string name = "";
    
    Hashy.AddItem("Paul", "Locha");
    Hashy.AddItem("Kim","Iced Mocha");
    Hashy.AddItem("Emma","Strawberry smoothy");
    Hashy.AddItem("Annie","Hot Chocolate");
    Hashy.AddItem("Sarah", "Passion Tea");
    Hashy.AddItem("Pepper","Caramel Mocha");
    Hashy.AddItem("Mike","Chai Tea");
    Hashy.AddItem("Steve","Apple Cider");
    Hashy.AddItem("Bill","Root Beer");
    Hashy.AddItem("Marie","Skinny Latte");
    Hashy.AddItem("Susan","Water");
    Hashy.AddItem("Joe","Green Tea");
    
    Hashy.PrintTable();
    //Hashy.PrintItemsInIndex(2);
    
    while ( name != "exit")
    {
        cout << "Search for ";
        cin >> name;
        
        if(name != "exit")
        {
            Hashy.FindDrink(name);
        }
    }
    
    
    Hashy.PrintItemsInIndex(2);
    
    while ( name != "exit")
    {
        cout << "Remove ";
        cin >> name;
        
        if(name != "exit")
        {
            Hashy.RemoveItem(name);
        }
    }
     Hashy.PrintItemsInIndex(2);
    
    
    return 0;
}
