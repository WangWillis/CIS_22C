#include <iostream>
#include "Tweet\Tweet.h"
#include "Tweet\TweetContainer.h"
#include "BinaryTree\BTNode.h"

using namespace std;

int main(){
	// Tweet* t1 = new Tweet("WILLYBEAR", "SUP WORLD");
	// string s1, s2;
	// getline(cin, s1);
	// getline(cin, s2);
	// Tweet* r1 = new ReTweet(t1, s1, s2);
	// MyTweet m1(t1);
	// MyTweet m2(r1);
	// m1.toString();
	// m2.toString();
	BTNode<int>* head = NULL;
	for(int i = 0; i < 5; i++){
		int temp;
		cin >> temp;
		head = head->add(temp, head);
	}
	cout << endl;
	head->toString(head);
	cout << endl;
	// int temp;
	// cin >> temp;
	// cout << endl;
	// delete head->remove(temp, head);
	// head->toString(head);
	head->clearList(head);
	//delete head;
	return 0;	
}