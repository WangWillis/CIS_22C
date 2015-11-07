#ifndef TWEETCONTAINER_H
#define TWEETCONTAINER_H

#include "Tweet.h"

class UserTweet;
class MyTweet;

class UserTweet{
	protected:
		Tweet* post;
		Tweet* rePost;
		bool liked, reTweet;
	public:
		UserTweet();
		UserTweet(Tweet*);
		~UserTweet();
		bool isLiked() const;
		bool isReTweet() const;
		Tweet* getTweet() const;
		void setPost(Tweet*);
		void changeLiked();
		Tweet* changeReTweet(const string, const string);
		Tweet* getRePost();
		void toString();
		bool operator==(const UserTweet&);
};
//whenever a new MyTweet update all followers
class MyTweet : public UserTweet{
	public:
		MyTweet(Tweet*);
		~MyTweet();
};

#endif