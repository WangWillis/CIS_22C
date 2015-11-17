#include "User.h"

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

void User::setNumTweets(int Ntweets)
{
	numTweets = Ntweets;
}

void User::setNumRTweets(int RT)
{
	numRetweets = RT;
}

void User::setNumNewsF(int NF)
{
	numTNewsF = NF;
}

int User::getNumTweets()
{
	return numTweets;
}
int User::getNumRTweets()
{
	return numRetweets;
}
int User::getNumNewsF()
{
	return numTNewsF;
}

string User::getUsername()
{
	return userName;
}

bool User::matchPassword(string pass)
{
	if (password == pass)
		return true;
	else 
		return false;
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
	if (pst->getUserId() == userName){
		MyTweet Tweeting(pst);
		myTweets.addFront(Tweeting);
	}
	UserTweet newsTweet(pst);
	newsFeed.add(newsTweet);
}

void User::deleteTweet(MyTweet pst)
{
	if (pst.getTweet()->getUserId() == userName){
		if (pst.isReTweet() == true)
			myRetweets.delInfo(pst);
		else
			myTweets.delInfo(pst);
	}
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

//Since the user class does not interact with the hash table
//to remove and add tweets to users who are following you need to be done in main
//in order to do that we need to stream the people who are following you
//input those string into the has table and add or remove the tweet from their newsfeed

Queue<string> User::toQueueFollowers()
{
	return followers.toQueue();
}

UserTweet User::getUserTweet(Tweet* twt){
	UserTweet temp(twt);
	return newsFeed.get(temp);
}

MyTweet User::getMyReTweet(Tweet* twt){
	MyTweet temp(twt);
	return myRetweets.getData(temp);
}