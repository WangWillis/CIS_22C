#include <iostream>
#include <time.h>

using namespace std;

int main(){
	time_t curtime, before;
	time(&curtime);
	cout << ctime(&curtime) << endl;
	for(long int i = 0; i < 1000000000; i++){
	}
	cout << endl;
	time(&before);
	if(before < curtime){
		cout << "curtime: " << ctime(&curtime) << endl;
	} else if (curtime < before){
		cout << "before: " << ctime(&before) << endl;
	}
	return 0;	
}