#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue;

template <class T>
class Queue{
	private:
		int start, end, arrSize;
		T* queue;
		T* upSize();
		T* downSize();
	public:
		Queue();
		~Queue();
		T pop();
		T get();
		bool isEmpty();
		void add(const T num);
};

//Constructor no args
template <class T>
Queue<T>::Queue(){
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
	T* temp = new T [2*arrSize];
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
template <class T>
T* Queue<T>::downSize(){
	T* temp = new T [(int)(0.2*arrSize) + 1];
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
template <class T>
void Queue<T>::add(const T num){
	end++;
	if((end - start) >= arrSize){
		queue = upSize();
	}
	queue[(end%arrSize)] = num;
}
//gets starting element of queue
template <class T>
T Queue<T>::get(){
	if(!isEmpty()){
		return queue[start%arrSize];		
	} else {
		throw "Queue is Empty";
	}

}
//gets and remeoves first element of queue
template <class T>
T Queue<T>::pop(){
	if(!isEmpty()){
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
	} else {
		throw "Queue is Empty";
	}
	//return void;
}
template <class T>
bool Queue<T>::isEmpty(){
	if(end == -1){
		return true;
	}
	return false;
}

#endif