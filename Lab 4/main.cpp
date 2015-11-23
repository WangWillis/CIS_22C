//Tree is AVL tree
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
    
    outFile.open("BreathFirst.txt", fstream::trunc);
    outFile.clear();
    while(!temp2.isEmpty()){
        outFile << temp2.pop().getBirthday();
        outFile << endl;
    }
    outFile.close();
    outFile.open("inOrder.txt", fstream::trunc);
    outFile.clear();
    temp2 = entry.toQueue();
    while(!temp2.isEmpty()){
        outFile << temp2.pop().getName();
        outFile << endl;
    }
    outFile.close();
    return 0;
    
}
