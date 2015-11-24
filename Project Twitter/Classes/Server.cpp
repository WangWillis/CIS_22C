#include "Server.h"

Server::Server(HashTable<User*> hash)
{
	overLord = hash;
}

bool Server::checkKey(std::string key){
	return overLord.freeKey(key);
}

void Server::addUser(User* user){
	overLord.add(user->getUsername(), user);
}

void Server::removeUser(User* user){
	overLord.remove(user->getUsername());
}

User* Server::getUser(std::string userName, std::string pass){
	if(!overLord.freeKey(userName)){
		User* temp = overLord.getData(userName);
		if(temp->matchPassword(pass)){
			return temp;
		}
	}
	cout << "User not found." << endl;
	return NULL;
}

void Server::add(User* user, std::string post){
	Tweet* twt = new Tweet(user->getUsername(), post);
	Queue<std::string> followerStream = user->toQueueFollowers();
	while(!followerStream.isEmpty()){
		User* temp = overLord.getData(followerStream.pop());
		temp->addTweet(twt);
	}
	user->addTweet(twt);
}

void Server::remove(User* user, MyTweet pst){
	Queue<std::string> followerStream = user->toQueueFollowers();
	while(!followerStream.isEmpty()){
		User* temp = overLord.getData(followerStream.pop());
		temp->deleteTweet(pst);
	}
	user->deleteTweet(pst);
}

void Server::follow(User* user, std::string unam){
	user->addFollowing(unam);
	overLord.getData(unam)->addFollower(user->getUsername());
}

void Server::unFollow(User* user, std::string unam){
	user->removeFollowing(unam);
	overLord.getData(unam)->removeFollower(user->getUsername());
}