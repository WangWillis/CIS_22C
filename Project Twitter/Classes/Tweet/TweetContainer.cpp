#include "TweetContainer.h"

UserTweet::UserTweet(){
	post = NULL;
}

UserTweet::UserTweet(Tweet* twt){
	post = twt;
}

UserTweet::~UserTweet(){}

Tweet* UserTweet::getTweet() const{
	return post;
}

void UserTweet::setPost(Tweet* tweet){
	post = tweet;
}

bool UserTweet::operator==(const UserTweet& rhs) const{
	if(post == rhs.getTweet()){
		return true;
	}
	return false;
}

bool UserTweet::operator!=(const UserTweet& rhs) const{
	if(post != rhs.getTweet()){
		return true;
	}
	return false;
}

MyTweet::MyTweet() : UserTweet(){}

MyTweet::MyTweet(Tweet* post) : UserTweet(post){}

void MyTweet::clearTweet(){
	delete post;
	post = NULL;
}