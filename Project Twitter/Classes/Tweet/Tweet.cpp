#include "Tweet.h"

Tweet::Tweet(string user, const string msg){
	//sets the username and body
	userId = user;
	text = msg;
	//sets the post time
	time(&postTime);
}
Tweet::Tweet(const string user, const string msg, const time_t tim){
	userId = user;
	text = msg;
	postTime = tim;
}
//setters and getters
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