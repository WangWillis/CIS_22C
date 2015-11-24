//Tree is AVL tree
//input file is people.txt
//in the input file format name '~' birthday
//Steven~12/12/12
//strings are not checked so assume people enter valid birthdays and not something like "thirty"
//find will only find first entry in bst
//when finding a person needs to be their full name not just part of the string
//Caps matter too
#include "BinaryTree/BST.h"
#include <iostream>
#include <fstream> 
#include "People.h"
#include <string>

using namespace std;

int main(){
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
    int choice;
    do{
        cout << "1. add person" << endl;
        cout << "2. find person" << endl;
        cout << "3. exit" << endl;
        cin >> choice;
        cin.ignore();
        if(choice == 1){
            People person;
            string temp;
            cout << "Enter the person's name" << endl;
            getline(cin, temp);
            person.setName(temp);
            cout << "Enter the person's Birthday" << endl;
            getline(cin, temp);
            person.setBirthday(temp);
            entry.add(person);
            cout << "ADDED! :D" << endl;
        }else if(choice == 2){
            string temp;
            cout << "Find a person by name or birthday" << endl;
            cout << "enter a name or birthday" << endl;
            getline(cin, temp);
            People person(temp, temp);
            person = entry.get(person);
            if((person.getName() == temp && person.getBirthday() != temp) || (person.getName() != temp && person.getBirthday() == temp)){
                cout << "Name: " << person.getName() << endl;
                cout << "Birthday: " << person.getBirthday() << endl;
            }else{
                cout << "Person not found" << endl;
            }
        }else if( choice != 3){
            cin.clear();
            cin.ignore();
            cout << "Invalid Input" << endl;
        }
    }while(choice != 3);
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
    outFile.open("People.txt", fstream::trunc);
    temp2 = entry.toQueue();
    while(!temp2.isEmpty()){
        People temp = temp2.pop();
        outFile << temp.getName() << "~" << temp.getBirthday() << endl;
    }
    outFile.close();
    return 0;
    
}
