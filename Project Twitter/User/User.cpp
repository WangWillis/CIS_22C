#include "User.h"
#include "TweetContainer.h"

User::User(string username, string psswrd)
{
	userName = username;
	password = psswrd;
	numFollower = 0;
	numFollowing = 0;
}

void User::setUsername(string username)
{
	userName = username;
}

void User::setPassword(string psswrd)
{
	password = psswrd;
}

void User::setFollowers(int followrs)
{
	numFollower = followrs;
}

void User::setFollowing(int followng)
{
	numFollowing = followng;
}

string User::getUsername()
{
	return userName;
}

bool User::matchPassword(string pass)
{
	if (password == pass)
		return true;
	else false;
}

int User::getFollowers()
{
	return numFollower;
}
int User::getFollowing()
{
	return numFollowing;
}

void User::addTweet(Tweet* pst)
{
	MyTweet Tweeting;
	Tweeting.setPost(pst);
	myTweets.addFront(Tweeting);
	newsFeed.add(Tweeting);
}

void User::deleteTweet(MyTweet pst)
{
	if (pst.isReTweet() == true)
		myRetweets.delInfo(pst);
	else
		myTweets.delInfo(pst);
	
	newsFeed.remove(pst);
}

void User::displayFollowers()
{
	followers.toString();
}
void User::displayFollowing()
{
	following.toString();
}
void User::displayNewsFeed()
{
	newsFeed.toString();
}

//Not sure
Queue<string> User::toQueuefollowers()
{
	return followers.toQueue();
}

