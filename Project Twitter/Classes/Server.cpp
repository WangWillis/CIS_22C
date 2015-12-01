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
	Queue<string> followerStream;
	user->toQueueFollowers(followerStream);
	while(!followerStream.isEmpty()){
		User* temp = overLord.getData(followerStream.pop()); //crashes here
		temp->addTweet(twt);
	}
	user->addTweet(twt);
}

void Server::remove(User* user, MyTweet pst){
	Queue<string> followerStream;
	user->toQueueFollowers(followerStream);
	while (!followerStream.isEmpty()){
		User* temp = overLord.getData(followerStream.pop());
		temp->deleteTweet(pst);
	}
	user->deleteTweet(pst);
}

void Server::follow(User* user, std::string unam){
	user->addFollowing(unam);
	User* u2 = overLord.getData(unam);
	Queue<MyTweet> tStream;
	u2->toQueueMyTweet(tStream);
	while(!tStream.isEmpty()){
		user->addTweet(tStream.pop().getTweet());
	}
	u2->addFollower(user->getUsername());
}

void Server::unFollow(User* user, std::string unam){
	user->removeFollowing(unam);
	User* u2 = overLord.getData(unam);
	Queue<MyTweet> tStream;
	u2->toQueueMyTweet(tStream);
	while(!tStream.isEmpty()){
		user->deleteTweet(tStream.pop());
	}
	u2->removeFollower(user->getUsername());
}

void Server::displayUsers(){
	overLord.displayKeys();
}

void Server::showIndentedKey(){
	overLord.showIndent();
}