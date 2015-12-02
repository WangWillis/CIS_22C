#include "Tweet.h"

Tweet::Tweet(string user, const string msg){
	//sets the username and body
	userId = user;
	text = msg;
	//sets the post time
	time(&postTime);
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