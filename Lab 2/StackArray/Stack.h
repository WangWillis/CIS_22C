#ifndef STACK_H_INCLUDED_
#define STACK_H_INCLUDED_

#include <string>

using namespace std;

class Stack;

class Stack{
	private:
		int end, size;
		string *stack;
		string *upSize();
		string *downSize();
	public:
		Stack();
		~Stack();
		string pop();
		string get();
		bool isEmpty();
		void push(string num);
};
#endif