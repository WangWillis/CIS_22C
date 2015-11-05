#include "Tweet.h"

Tweet::Tweet(const string user, const string msg) : likes(0), reTweets(0){
	id = user;
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

time_t Tweet::getTime() const{
	return postTime;
}

string Tweet::getPost() const{
	return text;
}

string Tweet::getId() const{
	return id;
}

int Tweet::getLikes() const{
	return likes;
}

int Tweet::getReTweets() const{
	return reTweets;
}

UserTweet::UserTweet(){
	liked = false;
	reTweet = false;
	post = NULL;
}

UserTweet::UserTweet(Tweet* twt) : liked(false), reTweet(false){
	post = twt;
}

bool UserTweet::isLiked() const{
	return liked;
}

bool UserTweet::isReTweet() const{
	return reTweet;
}

Tweet* UserTweet::getTweet() const{
	return post;
}

void UserTweet::changeLiked(){
	if(liked){
		post->unLike();
		liked = false;
	}else{
		post->like();
		liked = true;
	}
}