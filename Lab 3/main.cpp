#include <iostream>
#include <string>
#include <locale>
#include "StackList.h"
#include "Queue.h"

using namespace std;

int main(){
	string eqn;
	Stack <char> s1;
	Stack <int> s2;
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
		}else if(!isdigit(eqn[i]) && eqn[i] != '+' && eqn[i] != '-' && eqn[i] != '(' && eqn[i] != ')' && eqn[i] != '*' && eqn[i] != '/'){
			isGood = false;
			break;
		}
	}
	if(isGood && (isdigit(eqn[0]) || eqn[0] == '(')){
		for(int i = 0; i < eqn.size(); i++){
			if(eqn[i] == '('){
				char temp = eqn[i];
				s1.push(eqn[i]);
			}else if(eqn[i] == ')' && !s1.isEmpty()){
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
				}else{
					isGood = false;
					cout << "Invalid Equation" << endl;
					break;
				}
			}else if(eqn[i] == '+' || eqn[i] == '-' ){

			}else if(eqn[i] == '*' || eqn[i] == '/'){
				
			}else if(isdigit(eqn[i])){
				postFixStream.add(eqn[i]);
			}else{
				isGood = false;
				cout << "Invalid Equation" << endl;
				break;
			}
		}
	}else{
		isGood = false;
		cout << "Invalid Equation" << endl;
	}
	// if(!s2.isEmpty()){
	// 	cout << "Invalid Equation" << endl;
	// }
	return 0;
}