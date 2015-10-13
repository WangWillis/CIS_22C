#include <iostream>
#include "Queue.h"

using namespace std;

int main(){
	Queue q1;
	for(int i = 1; i <= 10; i++){
		q1.add(i);
	}
	q1.add(11);
	//cout << q1.get() << endl;
	for(int i = 0; i < 10; i++){
		cout << q1.pop() << endl;
	}
	cout << endl;
	for(int i = 0; i < 10; i++){
		q1.add(i);
	}
	for(int i = 0; i < 11; i++){
		cout << q1.pop() << endl;
	}
	return 0;
}