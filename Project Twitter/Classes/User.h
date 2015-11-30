#ifndef USER_H
#define USER_H
#include "Data Structures/BinaryTree/BST.h"
#include "Data Structures/BinaryTree/List&Queue/Queue.h"
#include "Data Structures/BinaryTree/List&Queue/List.h"
#include "Data Structures/BinaryTree/List&Queue/Node.h"
#include "Tweet/TweetContainer.h"
#include "Tweet/Tweet.h"
#include <string>

using namespace std;

class User;

class User{
private:
	User();
	string userName, password;
	int numFollower, numFollowing, numTweets;
	List <MyTweet> myTweets;
	AVLTree <UserTweet> newsFeed;
	AVLTree <string> followers;
	AVLTree <string> following;

public:
<<<<<<< HEAD
=======

>>>>>>> 759775e9b42746e1e700e35d9bce372a9359b0b5
	User(string, string);
	~User();

	void setUsername(string);
	void setPassword(string);
	void setFollowers(int);
	void setFollowing(int);
	void setNumTweets(int);

	string getUsername();
	bool matchPassword(string);
	int getFollowers();
	int getFollowing();
	int getNumTweets();
	
	void addTweet(Tweet*);
	void deleteTweet(MyTweet);
	void addFollower(string);
	void addFollowing(string);
	void removeFollower(string);
	void removeFollowing(string);
	UserTweet getUserTweet(Tweet*);
	MyTweet getMyTweet(const int);

	void displayFollowers();
	void displayFollowing();
	void displayNewsFeed();
	void displayMyTweets();
	Queue <string> toQueueFollowers();
	Queue <MyTweet> toQueueMyTweet();
};

#endif
