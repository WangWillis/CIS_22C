#include "TweetContainer.h"

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

void UserTweet::changeReTweet(){
	if(reTweet){
		post->unReTweet();
		reTweet = false;
	}else{
		post->reTweet();
		reTweet = true;
	}
}

MyTweet::MyTweet(Tweet* post) : UserTweet(post){}

MyTweet::~MyTweet(){delete post;}

MyReTweet::MyReTweet(Tweet* post) : MyTweet(post){reTweet = false;}

MyReTweet::~MyReTweet(){delete post;}