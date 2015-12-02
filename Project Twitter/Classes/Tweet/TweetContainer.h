#ifndef TWEETCONTAINER_H
#define TWEETCONTAINER_H

#include "Tweet.h"

class UserTweet;
class MyTweet;
//used to hold a tweet
class UserTweet{
	protected:
		//holds the tweet
		Tweet* post;
	public:
		UserTweet();
		UserTweet(Tweet*);
		//gets the tweet
		Tweet* getTweet() const;
		//resets the tweet
		void setPost(Tweet*);
		//overloaded operators for templatized data structures
		bool operator==(const UserTweet&) const;
		bool operator!=(const UserTweet&) const;
		friend bool operator<(const UserTweet& lhs, const UserTweet& rhs){
			return lhs.getTweet() < rhs.getTweet();
		}
		friend ostream &operator << (ostream& strm, const UserTweet& obj){
			//prints out the tweet
			strm << *obj.getTweet();
			return strm;
		}
};
//used to return the tweet memory
class MyTweet : public UserTweet{
	public:
		MyTweet();
		MyTweet(Tweet*);
		//returns the tweet memory
		void clearTweet();
};

#endif
