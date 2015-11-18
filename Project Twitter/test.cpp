#include <iostream>
#include "Classes\Tweet\Tweet.h"
#include "Classes\Tweet\TweetContainer.h"
#include "Classes\Data Structures\Hash.h"
#include "Classes\User.h"
#include <string>

using namespace std;

void add(User* user, string post, HashTable<User*> hash){
	Tweet* twt = new Tweet(user->getUsername(), post);
	user->addTweet(twt);
	Queue<string> followerStream = user->toQueueFollowers();
	while(!followerStream.isEmpty()){
		User* temp = hash.getData(followerStream.pop());
		temp->addTweet(twt);
	}
}

void remove(User* user, MyTweet pst, HashTable<User*> hash){
	Queue<string> followerStream = user->toQueueFollowers();
	while(!followerStream.isEmpty()){
		User* temp = hash.getData(followerStream.pop());
		UserTweet utt = temp->getUserTweet(pst.getTweet());
		if(utt.isReTweet()){
			remove(temp, temp->getMyReTweet(utt.getRePost()), hash);
		}
		temp->deleteTweet(pst);
	}
	user->deleteTweet(pst);
}

int main(){
	HashTable<User*> hash;
	User* u1 = new User("WILLYBEAR", "1234");
	User* u2 = new User("WILLYWNG", "4321");
	cout << "HI!" << endl;
	hash.addItem(u1->getUsername(), u1);
	hash.addItem(u2->getUsername(), u2);
	cout << "HI!" << endl;
	u1->addFollower(u2->getUsername());
	u2->addFollowing(u1->getUsername());
	string post1 = "YOOOOO BISSHH IM BEK";
	cout << "HI" << endl;
	add(u1, post1, hash);
	u1->displayNewsFeed();
	u2->displayNewsFeed();
	return 0;
}