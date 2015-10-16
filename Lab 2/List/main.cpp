//
//  main.cpp
//  Lab 2
//
//  Created by Randy Manzanares on 10/15/15.
//  Copyright (c) 2015 Randy Manzanares. All rights reserved.
//

#include <iostream>
#include "List.h"

int main() {
    
    List<int> list(1);
    list.addFront(1);
    list.addFront(23);
    list.displayList();
    
    List <string> list2;
    list2.addFront("Randy");
    list2.addFront("willis");
    list2.displayList();
    
    
    return 0;
}
