#ifndef QUEUE_H
#define QUEUE_H

class Queue;

class Queue{
	private:
		int start, end, arrSize;
		int* queue;
		int* upSize();
		int* downSize();
	public:
		Queue();
		~Queue();
		int pop();
		int get();
		bool isEmpty();
		void add(int num);
};
#endif