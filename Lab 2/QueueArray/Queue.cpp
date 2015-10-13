#include "Queue.h"

//Constructor no args
Queue::Queue(){
	queue = new int [2];
	arrSize = 2;
	start = 0;
	end = -1;
}
//frees memory
Queue::~Queue(){
	delete [] queue;
}
//upSizes array if needs more memory
int* Queue::upSize(){
	int* temp = new int [2*arrSize];
	for(int i = 0; i < arrSize; i++){
		temp[i] = queue[(start+i)%arrSize];
	}
	start = 0;
	end = arrSize;
	arrSize *= 2;
	delete [] queue;
	return temp;
}
//downSizes array if too big
int* Queue::downSize(){
	int* temp = new int [(int)(0.2*arrSize) + 1];
	for(int i = 0; i < (end - start + 1); i++){
		temp[i] = queue[(start+i)%arrSize];
	}
	end = end - start;
	start = 0;
	arrSize = (int)(0.2*arrSize) + 1;
	delete [] queue;
	return temp;
}
//adds elements to the queue
void Queue::add(int num){
	end++;
	if((end - start) >= arrSize){
		queue = upSize();
	}
	queue[(end%arrSize)] = num;
}
//gets starting element of queue
int Queue::get(){
	return queue[start%arrSize];
}
//gets and remeoves first element of queue
int Queue::pop(){
	if(end >= 0){
		if((end - start + 1) <= (0.1 * arrSize)){
			queue = downSize();
		}
		int temp = start;
		if(((end%arrSize) == (start%arrSize))){
			start = 0;
			end = -1;
			return queue[temp%arrSize];
		} else if(end != -1) {
			start++;
			return queue[(temp%arrSize)];
		}
	}
}
bool Queue::isEmpty(){
	if(end == -1){
		return true;
	}
	return false;
}