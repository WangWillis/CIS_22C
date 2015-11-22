#include <iostream>
#include "Classes/User.h"
#include "Classes/Data Structures/HashTable.h"
#include "Classes/Tweet/Tweet.h"
#include "Classes/Data Structures/BinaryTree/List&Queue/Queue.h"
#include "Classes/Tweet/TweetContainer.h"
#include "Classes/Server.h"
#include <string>

using namespace std;

int main(){
	Server awesome;
	string key = "WIllyBear";
	User* u1 = new User(key, "1234");
	User* u2 = new User("e", "1234");
	if(awesome.checkKey(key)){
		awesome.addUser(u1);
		awesome.addUser(u2);
		awesome.follow(u2, key);
	}else{
		delete u1;
		u1 = NULL;
	}
	awesome.add(u1, "IWIN");
	u1->displayNewsFeed();
	u2->displayNewsFeed();
	awesome.remove(u1, u1->getMyTweet(0));
	u1->displayNewsFeed();
	u2->displayNewsFeed();
	return 0;
}