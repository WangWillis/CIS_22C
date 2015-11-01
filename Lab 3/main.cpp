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
	Stack <char> operandStack;
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
	//checking if first char in the eqn is good
	if(isGood && (isdigit(eqn[0]) || eqn[0] == '(')){
		//creating the post fix eqn
		for(int i = 0; i < eqn.size(); i++){
			//what to do for (
			if(eqn[i] == '('){
				char temp = eqn[i];
				operandStack.push(eqn[i]);
			} else if(!operandStack.isEmpty() && eqn[i] == ')') { //need to make sure stack is not empty or else it is an invalid eqn
				//poping up till the (
				while(operandStack.get() != '('){
					//adds to queue
					postFixStream.add(operandStack.pop());
					//if there is no ( for this ) it is an invalid eqn
					if(operandStack.isEmpty()){
						isGood = false;
						break;
					}
				}
				if(isGood){
					//gets rid of the (
					operandStack.pop();
				} else {
					//doesnt need to create postfix anymore since invalid
					break;
				}
			} else if(eqn[i] == '+' || eqn[i] == '-' ) { //checks for + and -
				//pops basically everything up till ( or is empty
				while(!operandStack.isEmpty() && operandStack.get() != '('){
					//adds to queue
					postFixStream.add(operandStack.pop());
				}
				//puts the operator on the stack
				operandStack.push(eqn[i]);
			} else if(eqn[i] == '*' || eqn[i] == '/') { //checks for * and /
				//pops up till stack is empty a + a - or a (
				while(!operandStack.isEmpty() && operandStack.get() != '+' && operandStack.get() != '-' && operandStack.get() != '('){
					//adds the operators to the queue
					postFixStream.add(operandStack.pop());
				}
				//puts the operator on the stack
				operandStack.push(eqn[i]);
			} else if(isdigit(eqn[i])) { //if it is a number
				//dont have special conditions
				postFixStream.add(eqn[i]);
			} else { //extra check just in case otherwise will never hit this point
				isGood = false;
				break;
			}
		}
	} else {
		//invalid since first input wrong
		isGood = false;
	}
	//empty out the rest of the stack onto the queue
	while(isGood && !operandStack.isEmpty()){
		if(operandStack.get() == '('){
			isGood = false;
		}
		postFixStream.add(operandStack.pop());
	}
	Stack <int> intStack;
	//evaluating the postfix eqn
	while(!postFixStream.isEmpty() && isGood){
		if(!isdigit(postFixStream.get())){
			//for getting the first number
			int temp;
			//need to check if it is not only and operand
			if(intStack.isEmpty()){
				isGood = false;
			} else { //gets the first number
				temp = intStack.pop();
			}
			//if it is not empty can perform operations
			if(!intStack.isEmpty()){
				char opHolder = postFixStream.pop();
				if(opHolder == '*'){
					intStack.push(intStack.pop() * temp);
				} else if(opHolder == '/') {
					intStack.push(intStack.pop() / temp);
				} else if(opHolder == '+') {
					intStack.push(intStack.pop() + temp);
				} else if(opHolder == '-') {
					intStack.push(intStack.pop() - temp);
				}
			} else { //if it is empty then it is an invalid equation
				isGood = false;
			}
		} else { //it is a number 
			//convert char to int
			int temp = postFixStream.pop() - '0';
			//add the interger to the stack
			intStack.push(temp);
		}
	}
	//if everything works out this will display the equation
	if(isGood){
		int temp = intStack.pop();
		//to check if there are too many numbers
		if(intStack.isEmpty()){
			cout << "= " << temp << endl;
		} else {
			cout << "Invalid Equation" << endl;
		}
	} else {
		cout << "Invalid Equation" << endl;
	}
	return 0;
}