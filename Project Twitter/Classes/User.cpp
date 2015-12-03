#include "User.h"
//constructor
User::User(string username, string psswrd)
{
	userName = username;
	password = psswrd;
	numFollower = 0;
	numFollowing = 0;
	numTweets = 0;
}
//destructor
User::~User(){
	ofstream outFile;
    outFile.open("Users/user.txt", std::fstream::app);
    //Username
    outFile << userName << endl;
    //password
    outFile << password << endl;
    outFile.close();
    string file = "Users/" + userName + ".txt";
    outFile.open(file.c_str(), std::fstream::trunc);
    //number following
    outFile << numFollower << endl;
    //Following
    Queue<string> folw;
    followers.toQueue(folw);
    while( !folw.isEmpty())
    {
        outFile << folw.pop() << endl;
    }
    //myTweets
    Queue<MyTweet> theQ2;
    myTweets.toQueue(theQ2);
    while(!theQ2.isEmpty())
    {
        Tweet* temp = theQ2.pop().getTweet();
        time_t timeTemp = temp->getTime();
        outFile << temp->getUserId() << endl;
        outFile << ctime(&timeTemp);
        outFile << temp->getText()  << endl;
    }
    outFile.close();
	//freeing up the dynamically allocated tweets from myTweets
	Queue<MyTweet> theQ;
	myTweets.toQueue(theQ);
	while(!theQ.isEmpty()){
		theQ.pop().clearTweet();
	}
}
//setters / getters / input checkers 20 - 75
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
//end of setters / getters / input checkers
//adds a tweet
void User::addTweet(Tweet* pst)
{
	//creates a User tweet and adds it to the user's newsfeed
	UserTweet newsTweet(pst);
	newsFeed.add(newsTweet);
	//if the person who created the tweet is the user add it to their myTweets
	if (pst->getUserId() == userName){
		MyTweet Tweeting(pst);
		myTweets.addFront(Tweeting);
		numTweets++;
	}
}
//deletes a tweet from the user
void User::deleteTweet(MyTweet pst)
{
	//REMOVE FROM NEWSFEED FIRST
	newsFeed.remove(pst);
	//if it is there tweet
	if (pst.getTweet()->getUserId() == userName){
		MyTweet temp = myTweets.getData(pst);
		//remove the tweet from my tweet
		myTweets.delInfo(pst);
		//return mem used for the tweet
		temp.clearTweet();
		numTweets--;
	}
}
//outputs
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
//end outputs
//add a follower
void User::addFollower(string fol){
	//adds it to tree increments follower count
	followers.add(fol);
	numFollower++;
}
//add a following
void User::addFollowing(string fol){
	//adds to tree increments the following count
	following.add(fol);
	numFollowing++;
}
//removes a follower
void User::removeFollower(string fol){
	//makes sure the number of followers is greater than 0
	if(numFollower > 0){
		followers.remove(fol);
		numFollower--;
	}
}
//removes a following
void User::removeFollowing(string fol){
	//makes sure the number of following is greater than 0
	if(numFollowing > 0){
		following.remove(fol);
		numFollowing--;
	}
}

//Since the user class does not interact with the hash table
//to remove and add tweets to users who are following you need to be done in main
//in order to do that we need to stream the people who are following you
//input those string into the has table and add or remove the tweet from their newsfeed

//get a queue stream for the followers
void User::toQueueFollowers(Queue<string>& temp)
{
	followers.toQueue(temp);
}
//get a queue stream for the people you follow
void User::toQueueFollowing(Queue<string>& temp)
{
	following.toQueue(temp);
}
//get a certain user tweet
UserTweet User::getUserTweet(Tweet* twt){
	UserTweet temp(twt);
	return newsFeed.get(temp);
}
//get a certain my tweet
MyTweet User::getMyTweet(const int pos){
	return myTweets.getDataPos(pos);
}
//get a queue stream for this user's tweets
void User::toQueueMyTweet(Queue<MyTweet>& temp){
	myTweets.toQueue(temp);
}
