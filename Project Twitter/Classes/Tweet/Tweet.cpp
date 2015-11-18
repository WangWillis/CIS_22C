#include "Tweet.h"

Tweet::Tweet(string user, const string msg) : likes(0), reTweets(0){
	userId = user;
	text = msg;
	time(&postTime);
}

void Tweet::setUser(string us){
	userId = us;
}
void Tweet::setTweets(string msg){
	text = msg;
}
void Tweet::setlikes(int lk){
	likes = lk;
}
void Tweet::setRT(int RT){
	reTweets = RT;
}
void Tweet::setpostim(time_t tm){
	postTime = tm;
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

string Tweet::getText() const{
	return text;
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

Tweet* ReTweet::getPost() const{
	return orgPost;
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