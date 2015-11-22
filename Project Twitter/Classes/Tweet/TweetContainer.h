#ifndef TWEETCONTAINER_H
#define TWEETCONTAINER_H

#include "Tweet.h"

class UserTweet;
class MyTweet;

class UserTweet{
	protected:
		Tweet* post;
	public:
		UserTweet();
		UserTweet(Tweet*);
		~UserTweet();
		Tweet* getTweet() const;
		void setPost(Tweet*);
		bool operator==(const UserTweet&) const;
		bool operator!=(const UserTweet&) const;
		friend bool operator<(const UserTweet& lhs, const UserTweet& rhs){
			return lhs.getTweet() < rhs.getTweet();
		}
		friend ostream &operator << (ostream& strm, const UserTweet& obj){
			strm << *obj.getTweet();
			return strm;
		}
};
//whenever a new MyTweet update all followers
class MyTweet : public UserTweet{
	public:
		MyTweet();
		MyTweet(Tweet*);
		void clearTweet();
};

#endif
