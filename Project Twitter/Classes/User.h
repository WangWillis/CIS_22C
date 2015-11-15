#include "Data Structures\BinaryTree\BST.h"
#include "Data Structures\Hash.h"
#include "Data Structures\BinaryTree\List&Queue\List.h"
#include "Tweet\TweetContainer.h"
#include "Tweet\Tweet.h"
#include <string>

using namespace std;

class User;

class User{
private:
	string userName, password;
	int numFollower, numFollowing,numTweets,numRetweets,numTNewsF;
	List <UserTweet> myTweets;
	List <UserTweet> myRetweets;
	AVLTree <UserTweet> newsFeed;
	AVLTree <string> followers;
	AVLTree <string> following;

public:
	User(){};
	~User(){};
	User(string, string);

	void setUsername(string);
	void setPassword(string);
	void setFollowers(int);
	void setFollowing(int);
	void setNumTweets(int);
	void setNumRTweets(int);
	void setNumNewsF(int);

	string getUsername();
	bool matchPassword(string);
	int getFollowers();
	int getFollowing();
	int getNumTweets();
	int getNumRTweets();
	int getNumNewsF();
	
	void addTweet(Tweet*);
	void deleteTweet(UserTweet);

	void displayFollowers();
	void displayFollowing();
	void displayNewsFeed();
	Queue <string> toQueueFollowers();
};
