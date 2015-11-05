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
		Queue(const Queue&);
		~Queue();
		//removes and gets data at start
		T pop();
		//gets data at start
		T get() const;
		T get(int) const;
		//checks if list is empty
		bool isEmpty() const;
		int numEle() const;
		int getArrSize() const;
		//add data to end of queue
		void add(const T);
		Queue<T>& operator=(const Queue<T>&);
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
template <class T>
Queue<T>::Queue(const Queue& source){
	if(queue != NULL){
		delete [] queue;
		start = 0;
		end = -1;
		queue = NULL;
	}
	arrSize = source.getArrSize();
	if(!source.isEmpty()){
		queue = new T [arrSize];
		for(end; end < source.numEle() - 1; end++)
			queue[end + 1] = source.get(end + 1);
	}
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
T Queue<T>::get() const{
	//as long as the queue is not empty give back the first data
	if(!isEmpty()){
		return queue[start%arrSize];		
	} else {
		throw "Queue is Empty";
	}
}
template <class T>
T Queue<T>::get(int i) const{
	if(!isEmpty() && i <= (end - start)){
		return queue[(start+i)%arrSize];
	} else {
		throw "NO GOOD";
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
bool Queue<T>::isEmpty() const{
	//only empty if end = -1
	if(end == -1){
		return true;
	}
	return false;
}

template <class T>
int Queue<T>::getArrSize() const{
	return arrSize;
}

template <class T>
int Queue<T>::numEle() const{
	if(!isEmpty()){
		return end - start + 1;
	} else {
		return 0;
	}
	
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& source){
	if(this == &source){
		return *this;
	}
	if(queue != NULL){
		delete [] queue;
		start = 0;
		end = -1;
		queue = NULL;
	}
	arrSize = source.getArrSize();
	if(!source.isEmpty()){
		queue = new T [arrSize];
		for(end; end < source.numEle() - 1; end++)
			queue[end + 1] = source.get(end + 1);
	}
	return *this;
}

#endif