#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack(){
	stack = new int [2];
	size = 2;
	end = -1;
}

Stack::~Stack(){
	delete [] stack;
}

int *Stack::upSize(){
	int *temp = new int [2*size];
	for(int i = 0; i < end-1; i++){
		temp[i] = stack[i];
	}
	size = 2*size;
	delete [] stack;
	return temp;
}

int *Stack::downSize(){
	int *temp = new int [2*end];
	for(int i = 0; i < end; i++){
		temp[i] = stack[i];
	}
	size = 2*end;
	delete [] stack;
	return temp;
}

void Stack::push(int num){
	end++;
	if(end > size){
		stack = upSize();
	}
	stack[end] = num;
}

int Stack::pop(){
	if(end >= 0){
		end--;
		if(end <= (0.1*size)){
			stack = downSize();
		}
		return stack[end+1];
	}
}

void Stack::display(){
	for(int i = end; i >= 0; i--){
		cout << stack[i] << endl;
	}
}

bool Stack::isEmpty(){
	if(end == -1){
		return true;
	}
	return false;
}