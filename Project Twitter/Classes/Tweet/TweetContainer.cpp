#include "TweetContainer.h"
//sets post to NULL
UserTweet::UserTweet(){
	post = NULL;
}
//sets the tweet
UserTweet::UserTweet(Tweet* twt){
	post = twt;
}
//gets the tweet
Tweet* UserTweet::getTweet() const{
	return post;
}
//sets the tweet
void UserTweet::setPost(Tweet* tweet){
	post = tweet;
}
//checks if the address of the tweet object is equal
bool UserTweet::operator==(const UserTweet& rhs) const{
	if(post == rhs.getTweet()){
		return true;
	}
	return false;
}
//checks if the address of the tweet object is not equal
bool UserTweet::operator!=(const UserTweet& rhs) const{
	if(post != rhs.getTweet()){
		return true;
	}
	return false;
}
//calls the usertweet constructor
MyTweet::MyTweet() : UserTweet(){}
//calls the usertweet constructor
MyTweet::MyTweet(Tweet* post) : UserTweet(post){}
//cleares out the tweet
void MyTweet::clearTweet(){
	//returns the mem for the tweet
	delete post;
	//sets the post to NULL so dont mess up
	post = NULL;
}