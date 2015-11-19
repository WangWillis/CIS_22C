#ifndef SERVER_H
#define SERVER_H

#include "User.h"
#include "Data Structures\HashTable.h"
#include "Tweet\Tweet.h"
#include "Data Structures\BinaryTree\List&Queue\Queue.h"
#include "Tweet\TweetContainer.h"

class Server;

class Server{
	private:
		HashTable<User*> overLord;
	public:
		bool checkKey(string);
		void addUser(User*);
		void removeUser(User*);
		User* getUser(string, string);
		void add(User*, string);
		void remove(User*, MyTweet);
		void reTweet(User*, UserTweet);
};

#endif