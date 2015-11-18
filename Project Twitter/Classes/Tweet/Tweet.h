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
		void setUser(string);
		void setTweets(string);
		void setlikes(int);
		void setRT(int);
		void setpostim(time_t);
		time_t getTime() const;
		string getText() const;
		string getUserId() const;
		int getLikes() const;
		int getReTweets() const;
		friend bool operator<(const Tweet& lhs, const Tweet& rhs){
			return lhs.getTime() < rhs.getTime();
		}
		friend ostream &operator << (ostream& strm, const Tweet& obj){
			time_t temp = obj.getTime();
			strm << "User: " << obj.getUserId() << endl;
			strm << "Time Posted: " << ctime(&temp);
			strm << "Likes: " << obj.getLikes() << "\t ReTweets: " << obj.getReTweets() << endl << endl;
			strm << "Tweet: " << endl << obj.getText() << endl << endl;
			return strm;
		}
};

class ReTweet : public Tweet{
	private:
		ReTweet();
		Tweet* orgPost;
	public:
		ReTweet(Tweet*, const string, const string);
		Tweet* getPost() const;
		void like();
		void unLike();
		void reTweet();
		void unReTweet();
		friend ostream &operator << (ostream& strm, const ReTweet& obj){
			time_t temp = obj.getTime();
			strm << "User: " << obj.getUserId() << endl;
			strm << "Time Posted: " << ctime(&temp);
			strm << "Likes: " << obj.getLikes() << "\t ReTweets: " << obj.getReTweets() << endl << endl;
			strm << "Tweet: " << endl << obj.getText() << endl << endl;
			strm << "ReTweet:" << endl;
			strm << obj.getPost();
			return strm;
		}
};

#endif
