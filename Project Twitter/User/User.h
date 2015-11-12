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
	List <MyTweet> myRetweets;
	AVLTree <MyTweet> newsFeed;
	AVLTree <string> followers;
	AVLTree <string> following;

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
	
	void addTweet(Tweet*);
	void deleteTweet(UserTweet); 

	void displayFollowers();
	void displayFollowing();
	void displayNewsFeed();
	Queue <string> toQueueFollowers();
};
