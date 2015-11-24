#ifndef SERVER_H
#define SERVER_H

#include "User.h"
#include "Data Structures/HashTable.h"
#include "Tweet/Tweet.h"
#include "Data Structures/BinaryTree/List&Queue/Queue.h"
#include "Tweet/TweetContainer.h"

class Server;

class Server{
	private:
		Server();
		HashTable<User*> overLord;
	public:
		Server(HashTable<User*> hash);
		bool checkKey(std::string);  //returns true if user is not taken
		void addUser(User*);
		void removeUser(User*);
		User* getUser(std::string, std::string);
		void add(User*, std::string);
		void remove(User*, MyTweet);
		void follow(User*, std::string);
		void unFollow(User*, std::string);
};

#endif