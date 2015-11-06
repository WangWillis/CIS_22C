#ifndef TWEETCONTAINER_H
#define TWEETCONTAINER_H

#include "Tweet.h"

class UserTweet;
class MyTweet;
class MyReTweet;

class UserTweet{
	private:
		UserTweet();
	protected:
		Tweet* post;
		bool liked, reTweet;
	public:
		UserTweet(Tweet*);
		bool isLiked() const;
		bool isReTweet() const;
		Tweet* getTweet() const;
		void changeLiked();
		void changeReTweet();

};
//whenever a new MyTweet update all followers
class MyTweet : public UserTweet{
	public:
		MyTweet(Tweet*);
		~MyTweet();
		virtual void edit(const string);
};
//to contain retweets
class MyReTweet : public MyTweet{
	public:
		MyReTweet(Tweet*);
		~MyReTweet();
		void edit(const string);
};

#endif