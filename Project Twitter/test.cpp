#include <iostream>
#include "Classes\Tweet\Tweet.h"
#include "Classes\Tweet\TweetContainer.h"
#include "Classes\Data Structures\Hash.h"
#include <string>

using namespace std;

int main(){
	HashTable<int*> hash1;
	hash1.addItem("SUP", new int [1]);
	int* temp = hash1.getData("SUP");
	temp[0] = 1;
	cout << temp[0] << endl;
	return 0;	
}