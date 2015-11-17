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
	HashTable<User*> hash1;
	
	return 0;	
}