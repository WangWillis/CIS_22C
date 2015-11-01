/*
Randy Manzanares
Willis Wang
Lab 3
*/

#include <iostream>
#include <string>
#include <locale>
#include "StackList.h"
#include "Queue.h"

using namespace std;

int main(){
	string eqn;
	Stack <char> s1;
	Queue <char> postFixStream;
	//for checking to see if equation has invalid characters
	bool isGood = true;
	cout << "Enter your equation" << endl;
	getline(cin, eqn);
	//removes all whitespace from the string and checks to see if the string has invalid characters
	for(int i = 0; i < eqn.size(); i++){
		if(eqn[i] == ' '){
			eqn.erase(i, 1);
			i -= 1;
		} else if(!isdigit(eqn[i]) && eqn[i] != '+' && eqn[i] != '-' && eqn[i] != '(' && eqn[i] != ')' && eqn[i] != '*' && eqn[i] != '/') {
			isGood = false;
			break;
		}
	}
	if(isGood && (isdigit(eqn[0]) || eqn[0] == '(')){
		for(int i = 0; i < eqn.size(); i++){
			if(eqn[i] == '('){
				char temp = eqn[i];
				s1.push(eqn[i]);
			} else if(!s1.isEmpty() && eqn[i] == ')') {
				while(s1.get() != '('){
					postFixStream.add(s1.pop());
					if(s1.isEmpty()){
						isGood = false;
						break;
					}
				}
				if(isGood){
					//gets rid of the (
					s1.pop();
				} else {
					isGood = false;
					break;
				}
			} else if(eqn[i] == '+' || eqn[i] == '-' ) {
				while(!s1.isEmpty() && s1.get() != '('){
					postFixStream.add(s1.pop());
				}
				s1.push(eqn[i]);
			} else if(eqn[i] == '*' || eqn[i] == '/') {
				while(!s1.isEmpty() && s1.get() != '+' && s1.get() != '-' && s1.get() != '('){
					postFixStream.add(s1.pop());
				}
				s1.push(eqn[i]);
			} else if(isdigit(eqn[i])) {
				postFixStream.add(eqn[i]);
			} else {
				isGood = false;
				break;
			}
		}
	} else {
		isGood = false;
	}
	while(isGood && !s1.isEmpty()){
		if(s1.get() == '('){
			isGood = false;
		}
		postFixStream.add(s1.pop());
	}
	Stack <int> s2;
	while(!postFixStream.isEmpty() && isGood){
		int temp;
		if(!isdigit(postFixStream.get())){
			if(s2.isEmpty()){
				isGood = false;
			} else {
				temp = s2.pop();
			}
			if(!s2.isEmpty()){
				char opHolder = postFixStream.pop();
				if(opHolder == '*'){
					s2.push(s2.pop() * temp);
				} else if(opHolder == '/') {
					s2.push(s2.pop() / temp);
				} else if(opHolder == '+') {
					s2.push(s2.pop() + temp);
				} else if(opHolder == '-') {
					s2.push(s2.pop() - temp);
				}
			} else {
				isGood = false;
			}
		} else {
			int temp = postFixStream.pop() - '0';
			s2.push(temp);
		}
	}
	if(isGood){
		int temp = s2.pop();
		if(s2.isEmpty()){
			cout << "= " << temp << endl;
		} else {
			cout << "Invalid Equation" << endl;
		}
	} else {
		cout << "Invalid Equation" << endl;
	}
	return 0;
}