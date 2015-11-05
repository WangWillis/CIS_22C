#ifndef TWEET_H
#define TWEET_H

#include <string>
#include <time.h>

using namespace std;

class Tweet;
class UserTweet;
class MyTweet;
class ReTweet;
class MyReTweet;

class Tweet{
	private:
		//no point in using default constructor
		Tweet();
	protected:
		string text, id;
		int likes, reTweets;
		time_t postTime;
	public:
		Tweet(const string, const string);
		virtual void like();
		virtual void unLike();
		void changeMsg(string);
		void toString();
		void reTweet();
		void unReTweet();
		time_t getTime() const;
		string getPost() const;
		string getId() const;
		virtual int getLikes() const;
		virtual int getReTweets() const;
		friend bool operator<(const Tweet& lhs, const Tweet rhs){
			return lhs.getTime() < rhs.getTime();
		}
};

class MyReTweet : Tweet{
	private:
		Tweet* rePost;
	public:
};

class UserTweet{
	private:
		bool liked, reTweet;
	protected:
		Tweet* post;
	public:
		UserTweet();
		UserTweet(const Tweet*);
		bool isLiked() const;
		bool isReTweet() const;
		Tweet* getTweet() const;
		void changeLiked();
		void changeReTweet();

};
//whenever a new MyTweet update all followers
class MyTweet : public UserTweetCont{
	public:
		MyTweet();
		~MyTweet();
		virtual void edit(const string);
		void deletePost();
};
//to contain retweets
class MyReTweet : public MyTweet{
	private:
		
	public:

};
#endif