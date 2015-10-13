#ifndef STACK_H_INCLUDED_
#define STACK_H_INCLUDED_

class Stack;

class Stack{
	private:
		int end, *stack, size;
		int *upSize();
		int *downSize();
	public:
		Stack();
		~Stack();
		int pop();
		bool isEmpty();
		void push(int num);
		void display();
};
#endif