#include "Server.h"

bool Server::checkKey(string key){
	return overLord.freeKey(key);
}

void Server::addUser(User* user){
	overLord.add(user->getUsername(), user);
}

void Server::removeUser(User* user){
	overLord.remove(user->getUsername());
}

User* Server::getUser(string userName, string pass){
	if(!overLord.freeKey(userName)){
		User* temp = overLord.getData(userName);
		if(temp->matchPassword(pass)){
			return temp;
		}
	}
	return NULL;
}

void Server::add(User* user, string post){
	Tweet* twt = new Tweet(user->getUsername(), post);
	user->addTweet(twt);
	Queue<string> followerStream = user->toQueueFollowers();
	while(!followerStream.isEmpty()){
		User* temp = hash->getData(followerStream.pop());
		temp->addTweet(twt);
	}
}

void Server::remove(User* user, MyTweet pst){
	Queue<string> followerStream = user->toQueueFollowers();
	while(!followerStream.isEmpty()){
		User* temp = hash->getData(followerStream.pop());
		UserTweet utt = temp->getUserTweet(pst.getTweet());
		if(utt.isReTweet()){
			remove(temp, temp->getMyReTweet(utt.getRePost()), hash);
		}
		temp->deleteTweet(pst);
	}
	user->deleteTweet(pst);
}