#ifndef TWEET_H
#define TWEET_H
#define _CRT_SECURE_NO_WARNINGS_
#define _CRT_SECURE_NO_DEPRECATE_

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class Tweet;

class Tweet{
	private:
		//holds the body of the tweet and the user id
		string text, userId;
		//holds the post time
		time_t postTime;
	public:
		Tweet(){};
		//sets the username and the body
		Tweet(const string, const string);
		Tweet(const string, const string, const time_t);
		//sets the username
		void setUser(string);
		//sets the body
		void setTweets(string);
		//sets the post time
		void setpostim(time_t);
		//gets the post time
		time_t getTime() const;
		//gets the body
		string getText() const;
		//gets the username
		string getUserId() const;
		//so tweets can be compaired
		friend bool operator<(const Tweet& lhs, const Tweet& rhs){
			//compaired by time if time is before return true
			if(difftime(lhs.getTime(), rhs.getTime()) < 0){
				return true;
			}
			return false;
		}
		//for printing the tweets
		friend ostream &operator << (ostream& strm, const Tweet& obj){
			time_t temp = obj.getTime();
			strm << "User: " << obj.getUserId() << endl;
			strm << "Time Posted: " << ctime(&temp);
			strm << "Tweet: " << endl << obj.getText() << endl << endl;
			return strm;
		}
};

#endif
