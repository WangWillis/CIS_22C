#include <iostream>
#include <string>
#include "StackList.h"
#include "Currency.h"
#include "Money.h"

using namespace std;

int main(){
	Stack <int> intStack;
	Stack <string> stringStack;
	Stack <Currency*> curStack;
	for(int i = 1; i <= 5; i++){
		intStack.push(i);
	}
	while(!intStack.isEmpty()){
		cout << intStack.pop() << endl;
	}
	string temp = "HELLO";
	for(int i = 0; i < 5; i++){
		stringStack.push(temp.substr(i));
	}
	while(!stringStack.isEmpty()){
		cout << stringStack.pop() << endl;
	}
	Dollar* dol = new Dollar(1,1);
	Yen* ye = new Yen(1,1);
	Euros* euro = new Euros(1,1);
	curStack.push(dol);
	curStack.push(ye);
	curStack.push(euro);
	while(!curStack.isEmpty()){
		Currency* temp = curStack.pop();
		temp->toString();
		delete temp;
	}
	return 0;
}