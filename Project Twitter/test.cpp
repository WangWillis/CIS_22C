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
	for(int i = 0; i < 5; i++){

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
	head->clearList(head);
	delete head;
	// string s1, s2;
	// cout << "Enter your user name" << endl;
	// getline(cin, s1);
	// cout << "Enter your tweet" << endl;
	// getline(cin, s2);
	// Tweet* t3 = new Tweet(s1, s2);
	// MyTweet m3(t3);
	// cout << "enter your retweet message" << endl;
	// getline(cin, s2);
	// Tweet* rt = new ReTweet(t3, s1, s2);
	// MyTweet r1(rt);
	// m3.toString();
	// r1.toString();
	return 0;	
}

//Jason wuz here

