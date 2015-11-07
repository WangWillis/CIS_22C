#include "TweetContainer.h"

UserTweet::UserTweet(){
	liked = false;
	reTweet = false;
	post = NULL;
}

UserTweet::UserTweet(Tweet* twt) : liked(false), reTweet(false){
	post = twt;
}

UserTweet::~UserTweet(){}

bool UserTweet::isLiked() const{
	return liked;
}

bool UserTweet::isReTweet() const{
	return reTweet;
}

Tweet* UserTweet::getTweet() const{
	return post->getPost();
}

void UserTweet::setPost(Tweet* tweet){
	post = tweet;
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

void UserTweet::changeReTweet(){
	if(reTweet){
		post->unReTweet();
		reTweet = false;
	}else{
		post->reTweet();
		reTweet = true;
	}
}

void UserTweet::toString(){
	post->toString();
}

bool UserTweet::operator==(const UserTweet& lhs){
	if(post == lhs.getTweet()){
		return true;
	}
	return false;
}

MyTweet::MyTweet(Tweet* post) : UserTweet(post){}

MyTweet::~MyTweet(){delete post;}