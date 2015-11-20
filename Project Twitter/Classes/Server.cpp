#include "Server.h"

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
	return NULL;
}

void Server::add(User* user, std::string post){
	Tweet* twt = new Tweet(user->getUsername(), post);
	user->addTweet(twt);
	Queue<std::string> followerStream = user->toQueueFollowers();
	while(!followerStream.isEmpty()){
		User* temp = overLord.getData(followerStream.pop());
		temp->addTweet(twt);
	}
}

void Server::remove(User* user, MyTweet pst){
	Queue<std::string> followerStream = user->toQueueFollowers();
	while(!followerStream.isEmpty()){
		User* temp = overLord.getData(followerStream.pop());
		UserTweet utt = temp->getUserTweet(pst.getTweet());
		if(utt.isReTweet()){
			remove(temp, temp->getMyReTweet(utt.getRePost()));
		}
		temp->deleteTweet(pst);
	}
	user->deleteTweet(pst);
}

void Server::reTweet(User* user, UserTweet& pst, std::string cmt){
	Tweet* twt = pst.changeReTweet(user->getUsername(), cmt);
	Queue<std::string> followerStream = user->toQueueFollowers();
	while(!followerStream.isEmpty()){
		User* temp = overLord.getData(followerStream.pop());
		temp->addTweet(twt);
	}
	user->addTweet(twt);
}