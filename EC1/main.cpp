#include <iostream>
#include "BoxInterface.h"
#include "MagicBox.h"
#include "ToyBox.h" 
#include "PlainBox.h"

int main()
{
    //setting up BoxInterface Variables
    BoxInterface<int> *box1 = new ToyBox<int>(BLACK);
    BoxInterface<char> *box2 = new MagicBox<char>('c');
    //calling Functions from BoxInterface class
    box1->getItem();
    box2->getItem();
    //freeing up memory
    delete box1, box2;
    //print if program runs succsesfully 
    std::cout << "IT WORKS" << std::endl;

    return 0;
}