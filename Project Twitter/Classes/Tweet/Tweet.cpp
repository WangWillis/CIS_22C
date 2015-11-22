#include "Tweet.h"

Tweet::Tweet(string user, const string msg){
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

void Tweet::setpostim(time_t tm){
	postTime = tm;
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