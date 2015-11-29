#include "Server.h"

bool Server::checkKey(std::string key){
	return overLord.freeKey(key);
}

void Server::addSingleTweet(User* user, Tweet* twt){
	user->addTweet(twt);
}

void Server::delSingleTweet(User* user, MyTweet twt){
	user->deleteTweet(twt);
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
	cout << "hi" << endl;
	Queue<std::string> followerStream = user->toQueueFollowers();
	cout << "hi" << endl;
	while(!followerStream.isEmpty()){
		cout << "hi" << endl;
		User* temp = overLord.getData(followerStream.pop()); //crashes here
		cout << "hi" << endl;
		temp->addTweet(twt);
		cout << "hi" << endl;
	}
	cout << "hi" << endl;
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
	cout << "hop" << endl;
	user->addFollowing(unam);
	cout << "hop" << endl;
	User* u2 = overLord.getData(unam);
	cout << "hop" << endl;
	Queue<MyTweet> tStream = u2->toQueueMyTweet();
	cout << "hop" << endl;
	while(!tStream.isEmpty()){
		addSingleTweet(user, tStream.pop().getTweet());  //crashes here
		cout << "hop" << endl;
	}
	cout << "hop" << endl;
	u2->addFollower(user->getUsername());
	cout << "hop" << endl;
}

void Server::unFollow(User* user, std::string unam){
	user->removeFollowing(unam);
	User* u2 = overLord.getData(unam);
	Queue<MyTweet> tStream = u2->toQueueMyTweet();
	while(!tStream.isEmpty()){
		delSingleTweet(user, tStream.pop());
	}
	u2->removeFollower(user->getUsername());
}

void Server::displayUsers(){
	overLord.displayKeys();
}