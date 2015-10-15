#ifndef QUEUE_H
#define QUEUE_H

#include <string>

using namespace std;

class Queue;

class Queue{
	private:
		int start, end, arrSize;
		string* queue;
		string* upSize();
		string* downSize();
	public:
		Queue();
		~Queue();
		string pop();
		string get();
		bool isEmpty();
		void add(string num);
};
#endif