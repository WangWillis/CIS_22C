#include <iostream>
#include "Classes\User.h"
#include "Classes\Data Structures\HashTable.h"
#include "Classes\Tweet\Tweet.h"
#include "Classes\Data Structures\BinaryTree\List&Queue\Queue.h"
#include "Classes\Tweet\TweetContainer.h"
#include <string>

using namespace std;

void add(User* user, string post, HashTable<User*>* hash){
	Tweet* twt = new Tweet(user->getUsername(), post);
	user->addTweet(twt);
	Queue<string> followerStream = user->toQueueFollowers();
	while(!followerStream.isEmpty()){
		User* temp = hash->getData(followerStream.pop());
		temp->addTweet(twt);
	}
}

void remove(User* user, MyTweet pst, HashTable<User*>* hash){
	Queue<string> followerStream = user->toQueueFollowers();
	while(!followerStream.isEmpty()){
		User* temp = hash->getData(followerStream.pop());
		UserTweet utt = temp->getUserTweet(pst.getTweet());
		if(utt.isReTweet()){
			remove(temp, temp->getMyReTweet(utt.getRePost()), hash);
		}
		temp->deleteTweet(pst);
	}
	user->deleteTweet(pst);
}

int main(){
	HashTable<User*>* hash = new HashTable<User*>();
	User* u1 = new User("WILLYBEAR", "1234");
	User* u2 = new User("WILLYWNG", "4321");
	hash->add(u1->getUsername(), u1);
	hash->add(u2->getUsername(), u2);
	u1->addFollower(u2->getUsername());
	u2->addFollowing(u1->getUsername());
	string post1 = "YOOOOO BISSHH IM BEK";
	add(u1, post1, hash);
	u1->displayNewsFeed();
	u2->displayNewsFeed();
	remove(u1, u1->getMyTweet(0), hash);
	u1->displayNewsFeed();
	u2->displayNewsFeed();
	delete hash;
	return 0;
}