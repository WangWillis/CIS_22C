#include <iostream>
#include "Tweet.h"
#include "TweetContainer.h"
#include "BTNode.h"

using namespace std;

UserTweet getUserTweet(Tweet* tweet){
	UserTweet temp(tweet);
	return temp;
}

int main(){
	BTNode<int>* head = NULL;
	for(int i = 0; i < 8; i++){

		int temp;
		cin >> temp;
		if(head == NULL){
			head = new BTNode<int>(temp);
		}else{
			head->add(temp, head);
		}
	}
	cout << endl;
	head->toString(head);
	cout << endl;
	int temp;
	cin >> temp;
	cout << endl;
	delete head->remove(temp, head);
	head->toString(head);
	head->clearList(head);
	delete head;
	return 0;	
}