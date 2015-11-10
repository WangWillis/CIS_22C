#include "Tweet.h"

Tweet::Tweet(string user, const string msg) : likes(0), reTweets(0){
	userId = user;
	text = msg;
	time(&postTime);
}

void Tweet::like(){
	likes++;
}

void Tweet::unLike(){
	likes--;
}

void Tweet::reTweet(){
	reTweets++;
}

void Tweet::unReTweet(){
	reTweets--;
}

void Tweet::toString(){
	cout << "User: " << userId << endl;
	cout << "Time Posted: " << ctime(&postTime);
	cout << "Likes: " << likes << "\t ReTweets: " << reTweets << endl << endl;
	cout << "Tweet: " << endl << text << endl << endl;
}

Tweet* Tweet::getPost(){
	return this;
}

time_t Tweet::getTime() const{
	return postTime;
}

string Tweet::getUserId() const{
	return userId;
}

int Tweet::getLikes() const{
	return likes;
}

int Tweet::getReTweets() const{
	return reTweets;
}

ReTweet::ReTweet(Tweet* post, const string user, const string msg) : Tweet(user, msg){
	orgPost = post;
}

void ReTweet::like(){
	likes++;
	orgPost->like();
}

void ReTweet::unLike(){
	likes--;
	orgPost->unLike();
}

void ReTweet::reTweet(){
	reTweets++;
	orgPost->reTweet();
}

void ReTweet::unReTweet(){
	reTweets--;
	orgPost->unReTweet();
}

void ReTweet::toString(){
	cout << "User: " << userId << endl;
	cout << "Time Posted: " << ctime(&postTime);
	cout << "Likes: " << likes << "\t ReTweets: " << reTweets << endl << endl;
	cout << "Tweet: " << endl << text << endl << endl;
	cout << "ReTweet:" << endl;
	orgPost->toString();
}