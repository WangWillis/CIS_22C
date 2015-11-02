#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue;

template <class T>
class Queue{
	private:
		//for positions in the array
		//start and end never go lower posistion unless resized use %arrsize to get the right position
		int start, end, arrSize;
		T* queue;
		//to resize when needed
		T* upSize();
		T* downSize();
	public:
		Queue();
		~Queue();
		//removes and gets data at start
		T pop();
		//gets data at start
		T get();
		//checks if list is empty
		bool isEmpty();
		//add data to end of queue
		void add(const T);
};

//Constructor no args
template <class T>
Queue<T>::Queue(){
	//starts off at size 2 resize if needed
	queue = new T [2];
	arrSize = 2;
	start = 0;
	end = -1;
}
//frees memory
template <class T>
Queue<T>::~Queue(){
	delete [] queue;
}
//upSizes array if needs more memory
template <class T>
T* Queue<T>::upSize(){
	//doubles the queue size
	T* temp = new T [2*arrSize];
	//copy elements over
	for(int i = 0; i < arrSize; i++){
		temp[i] = queue[(start+i)%arrSize];
	}
	//reset the positions
	start = 0;
	end = arrSize;
	arrSize *= 2;
	delete [] queue;
	return temp;
}
//downSizes array if too big
template <class T>
T* Queue<T>::downSize(){
	//downsizes array to 20% of the size
	T* temp = new T [(int)(0.2*arrSize) + 1];
	//copies elements over
	for(int i = 0; i < (end - start + 1); i++){
		temp[i] = queue[(start+i)%arrSize];
	}
	//resets the positions
	end = end - start;
	start = 0;
	arrSize = (int)(0.2*arrSize) + 1;
	delete [] queue;
	return temp;
}
//adds elements to the queue
template <class T>
void Queue<T>::add(const T data){
	//puts end into new parts
	end++;
	//if going to oversize increase the array size
	if((end - start) >= arrSize){
		queue = upSize();
	}
	//adds to queue
	queue[(end%arrSize)] = data;
}
//gets starting element of queue
template <class T>
T Queue<T>::get(){
	//as long as the queue is not empty give back the first data
	if(!isEmpty()){
		return queue[start%arrSize];		
	} else {
		throw "Queue is Empty";
	}

}
//gets and remeoves first element of queue
template <class T>
T Queue<T>::pop(){
	//checks if empty
	if(!isEmpty()){
		//resize if gets too small
		if((end - start + 1) <= (0.1 * arrSize)){
			queue = downSize();
		}
		//holds the start position
		int temp = start;
		//if the queue is going to be empty after the pop
		if(((end%arrSize) == (start%arrSize))){
			start = 0;
			end = -1;
			return queue[temp%arrSize];
		} else if(end != -1) {
			start++;
			return queue[(temp%arrSize)];
		}
	} else {
		throw "Queue is Empty";
	}
}
//checks if the queue is empty
template <class T>
bool Queue<T>::isEmpty(){
	//only empty if end = -1
	if(end == -1){
		return true;
	}
	return false;
}

#endif