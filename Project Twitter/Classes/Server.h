#ifndef SERVER_H
#define SERVER_H

#include "User.h"
#include "Data Structures/HashTableForPointers.h"
#include "Tweet/Tweet.h"
#include "Data Structures/BinaryTree/List&Queue/Queue.h"
#include "Tweet/TweetContainer.h"

class Server;
//used for interations between users and hashtable
class Server{
	private:
		//hash table holds a user*
		HashTable<User*> overLord;
	public:
		bool checkKey(std::string);  //returns true if user is not taken
		//adds a user to the hash table
		void addUser(User*);
		//removes a user from the hash table
		void removeUser(User*);
		//gets a user from the hash table need username and password
		User* getUser(std::string, std::string);
		//adds a tweet by a user
		void add(User*, std::string);
		void add(User*, Tweet*);
		//removes a tweets by a user
		void remove(User*, MyTweet);
		//makes a user follow another
		void follow(User*, std::string);
		//makes a user unfollow another
		void unFollow(User*, std::string);
		void addFollower(User*, std::string);
		//display all the users
		void displayUsers();
		//display all the users plus their level in the bst
		void showIndentedKey();
		//gets the efficiency of inserting a string
		void getEff();
		void writeKey();
};

#endif