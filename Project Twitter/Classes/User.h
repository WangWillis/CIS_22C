#ifndef USER_H
#define USER_H
#include "Data Structures/BinaryTree/BST.h"
#include "Data Structures/BinaryTree/List&Queue/Queue.h"
#include "Data Structures/BinaryTree/List&Queue/List.h"
#include "Data Structures/BinaryTree/List&Queue/Node.h"
#include "Tweet/TweetContainer.h"
#include <fstream>
#include "Tweet/Tweet.h"
#include <string>

using namespace std;

class User;

class User{
private:
	//dont want a user with no username and password
	User();
	//hold the username and password
	string userName, password;
	//numerical values for info 
	int numFollower, numFollowing, numTweets;
	//holding the tweets for the user
	List <MyTweet> myTweets;
	//this user's newsfeed
	AVLTree <UserTweet> newsFeed;
	//who is following this user
	AVLTree <string> followers;
	//who this user is following
	AVLTree <string> following;
public:
	//takes in username, password
	User(string, string);
	~User();
	//for manipulating the data held in the class
	void setUsername(string);
	void setPassword(string);
	void setFollowers(int);
	void setFollowing(int);
	void setNumTweets(int);
	//for getting the data in the class and checking vaild things
	string getUsername();
	bool matchPassword(string);
	bool amFollowing(string);
	int getFollowers();
	int getFollowing();
	int getNumTweets();
	//interating with data structures and tweet stuff
	void addTweet(Tweet*);
	void deleteTweet(MyTweet);
	void addFollower(string);
	void addFollowing(string);
	void removeFollower(string);
	void removeFollowing(string);
	UserTweet getUserTweet(Tweet*);
	MyTweet getMyTweet(const int);
	//output functions
	void displayFollowers();
	void displayFollowing();
	void displayNewsFeed();
	void displayMyTweets();
	//streaming functions "getting a queue"
	void toQueueFollowers(Queue<string>&);
	void toQueueFollowing(Queue<string>&);
	void toQueueMyTweet(Queue<MyTweet>&);
};

#endif
