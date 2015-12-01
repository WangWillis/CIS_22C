#include "User.h"

User::User(string username, string psswrd)
{
	userName = username;
	password = psswrd;
	numFollower = 0;
	numFollowing = 0;
	numTweets = 0;
}

User::~User(){
	Queue<MyTweet> theQ;
	myTweets.toQueue(theQ);
	while(!theQ.isEmpty()){
		theQ.pop().clearTweet();
	}
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

int User::getNumTweets()
{
	return numTweets;
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

bool User::amFollowing(string temp){
	return following.find(temp);
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
	UserTweet newsTweet(pst);
	newsFeed.add(newsTweet);
	if (pst->getUserId() == userName){
		MyTweet Tweeting(pst);
		myTweets.addFront(Tweeting);
		numTweets++;
	}
}

void User::deleteTweet(MyTweet pst)
{
	newsFeed.remove(pst);
	if (pst.getTweet()->getUserId() == userName){
		MyTweet temp = myTweets.getData(pst);
		myTweets.delInfo(pst);
		temp.clearTweet();
		numTweets--;
	}
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
	cout << userName << ": Newsfeed" << endl;
	newsFeed.toString();
}
void User::displayMyTweets(){
	cout << userName << ": My Tweets" << endl;
	myTweets.toString();
}
void User::addFollower(string fol){
	followers.add(fol);
	numFollower++;
}
void User::addFollowing(string fol){
	following.add(fol);
	numFollowing++;
}

void User::removeFollower(string fol){
	if(numFollower > 0){
		followers.remove(fol);
		numFollower--;
	}
}

void User::removeFollowing(string fol){
	if(numFollowing > 0){
		following.remove(fol);
		numFollowing--;
	}
}

//Since the user class does not interact with the hash table
//to remove and add tweets to users who are following you need to be done in main
//in order to do that we need to stream the people who are following you
//input those string into the has table and add or remove the tweet from their newsfeed

void User::toQueueFollowers(Queue<string>& temp)
{
	followers.toQueue(temp);
}

UserTweet User::getUserTweet(Tweet* twt){
	UserTweet temp(twt);
	return newsFeed.get(temp);
}

MyTweet User::getMyTweet(const int pos){
	return myTweets.getDataPos(pos);
}

void User::toQueueMyTweet(Queue<MyTweet>& temp){
	myTweets.toQueue(temp);
}