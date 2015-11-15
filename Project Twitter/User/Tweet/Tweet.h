#ifndef TWEET_H
#define TWEET_H

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class Tweet;
class ReTweet;

class Tweet{
	protected:
		string text, userId;
		int likes, reTweets;
		time_t postTime;
	public:
		Tweet();
		Tweet(const string, const string);
		virtual void like();
		virtual void unLike();
		virtual void reTweet();
		virtual void unReTweet();
		virtual void toString();
		void setUser(string);
		void setTweets(string);
		void setlikes(int);
		void setRT(int);
		void setpostim(time_t);
		Tweet* getPost();
		time_t getTime() const;
		string getUserId() const;
		int getLikes() const;
		int getReTweets() const;
		friend bool operator<(const Tweet& lhs, const Tweet& rhs){
			return lhs.getTime() < rhs.getTime();
		}
};

class ReTweet : public Tweet{
	private:
		ReTweet();
		Tweet* orgPost;
	public:
		ReTweet(Tweet*, const string, const string);
		void toString();
		void like();
		void unLike();
		void reTweet();
		void unReTweet();
};

#endif
