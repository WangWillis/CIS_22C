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
		string text, userId;
		time_t postTime;
	public:
		Tweet(){};
		Tweet(const string, const string);
		void setUser(string);
		void setTweets(string);
		void setpostim(time_t);
		time_t getTime() const;
		string getText() const;
		string getUserId() const;
		friend bool operator<(const Tweet& lhs, const Tweet& rhs){
			return lhs.getTime() < rhs.getTime();
		}
		friend ostream &operator << (ostream& strm, const Tweet& obj){
			time_t temp = obj.getTime();
			strm << "User: " << obj.getUserId() << endl;
			strm << "Time Posted: " << ctime(&temp);
			strm << "Tweet: " << endl << obj.getText() << endl << endl;
			return strm;
		}
};

#endif
