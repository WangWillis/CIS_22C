//Tree is AVL tree
//input file is people.txt
//in the input file format name '~' birthday
//Steven~12/12/12
#include "BinaryTree/BST.h"
#include <iostream>
#include <fstream> 
#include "People.h"
#include <string>

using namespace std;

int main()
{
    ofstream outFile;
    ifstream inFile;
    AVLTree <People> entry;
    Queue<People> temp2;
    string temp;
    
    inFile.open("People.txt");
    while (getline(inFile, temp, '~'))
    {
        People person;
        person.setName(temp);
        
        getline(inFile, temp);
        person.setBirthday(temp);
        
        entry.add(person);
    }
    
    inFile.close();
    
    temp2 = entry.toQueueBF();
    
    outFile.open("TextFiles/BreathFirst(Birthdays).txt", fstream::trunc);
    while(!temp2.isEmpty()){
        outFile << temp2.pop().getBirthday();
        outFile << endl;
    }
    outFile.close();
    outFile.open("TextFiles/PostOrder(Names).txt", fstream::trunc);
    outFile.clear();
    temp2 = entry.toQueuePO();
    while(!temp2.isEmpty()){
        outFile << temp2.pop().getName();
        outFile << endl;
    }
    outFile.close();
    outFile.open("TextFiles/InOrder(Both).txt", fstream::trunc);
    temp2 = entry.toQueue();
    while(!temp2.isEmpty()){
        People temp = temp2.pop();
        outFile << temp.getName() << " " << temp.getBirthday() << endl;
    }
    outFile.close();
    return 0;
    
}
