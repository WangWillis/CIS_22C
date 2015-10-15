#include <iostream>
#include "Stack.h"

Stack::Stack(){
	stack = new string [2];
	size = 2;
	end = -1;
}

Stack::~Stack(){
	delete [] stack;
}

string* Stack::upSize(){
	string *temp = new string [2*size];
	for(int i = 0; i < end-1; i++){
		temp[i] = stack[i];
	}
	size = 2*size;
	delete [] stack;
	return temp;
}

string* Stack::downSize(){
	string *temp = new string [2*end];
	for(int i = 0; i < end; i++){
		temp[i] = stack[i];
	}
	size = 2*end;
	delete [] stack;
	return temp;
}

void Stack::push(string num){
	end++;
	if(end > size){
		stack = upSize();
	}
	stack[end] = num;
}

string Stack::pop(){
	if(end >= 0){
		end--;
		if(end <= (0.1*size)){
			stack = downSize();
		}
		return stack[end+1];
	}
}

string Stack::get(){
	if(!isEmpty())
		return stack[end];
}

bool Stack::isEmpty(){
	if(end == -1){
		return true;
	}
	return false;
}