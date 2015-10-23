/* 
Randy Manzanares
Willis Wang
Lab 2
*/

#include <iostream>
#include <string>
#include "StackList.h"
#include "Money.h"

using namespace std;

int main(){
	//create an int stack
	Stack <int> intStack;
	//create a string stack
	Stack <string> stringStack;
	//create a Currecy stack
	Stack <Currency*> curStack;
	cout << "int stack" << endl << endl;
	//adds 1 through 5 to stack
	for(int i = 1; i <= 5; i++){
		intStack.push(i);
	}
	//print out elements in the int stack till empty
	while(!intStack.isEmpty()){
		cout << intStack.pop() << endl;
	}
	cout << endl << "String stack" << endl << endl;
	string temp = "HELLO";
	//parse the string hello in the stack each one containing one less letter
	for(int i = 0; i < 5; i++){
		stringStack.push(temp.substr(i));
	}
	//print till the stack is empty
	while(!stringStack.isEmpty()){
		cout << stringStack.pop() << endl;
	}
	cout << endl << "Currecny stack" << endl << endl;
	//creating Currecny 
	Dollar* dol = new Dollar(1,1);
	Yen* ye = new Yen(1,1);
	Euros* euro = new Euros(1,1);
	//adding the Currency to the stack
	curStack.push(dol);
	curStack.push(ye);
	curStack.push(euro);
	//prints out till the stack is empty
	while(!curStack.isEmpty()){
		Currency* temp = curStack.pop();
		temp->toString();
		delete temp;
	}
	return 0;
}