#include "User.h"
#include "TweetContainer.h"

User::User(string username, string psswrd)
{
	userName = username;
	password = psswrd;
	followers = 0;
	following = 0;
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
	followers = followrs;
}

void User::setFollowing(int followng)
{
	following = followng;
}

string User::getUsername()
{
	return userName;
}

string User::getPassword()
{
	return password;
}

int User::getFollowers()
{
	return followers;
}
int User::getFollowing()
{
	return following;
}

void User::addTweet(Tweet* pst)
{
	MyTweet Tweeting;
	Tweeting.setPost(pst);
	myTweets.addFront(Tweeting);
	
	//Needs to be added in followers newsfeed
}

void User::deleteTweet (MyTweet pst)
{
//	myTweets.delInfo(pst);  This will not work :)
}

