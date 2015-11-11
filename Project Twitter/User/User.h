#include "BST.h"
#include "Queue.h"
#include "List.h"
#include "TweetContainer.h"
#include "Tweet.h"
#include <string>

using namespace std;

class User;

class User{
private:
	string userName, password;
	int numFollower, numFollowing;
	List <MyTweet> myTweets;
//	AVLTree <UserTweet> newsFeed;
//	AVLTree <string> followers;
//	AVLTree <string> following;

public:
	User();
	~User();
	User(string, string);

	void setUsername(string);
	void setPassword(string);
	void setFollowers(int);
	void setFollowing(int);

	string getUsername();
	bool matchPassword(string);
	int getFollowers();
	int getFollowing();

	//this just general add so just add a new tweet container to the newsfeed
	//Looks like the hash table needs to be completed for this :)
	void addTweet(Tweet*); //Needs to be completed
	void deleteTweet(MyTweet); //Delete by tweet also need to delete from followers newsfeed but prob not in main

	//Tree has been completed
	//BinarySearchTree needs to be completed
	void displayFollowers();
	void displayFollowing();
	void displayNewsFeed();
	Queue toQueue();
};
