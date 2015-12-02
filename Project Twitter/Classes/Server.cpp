#include "Server.h"
//checks if a key is taken or not returns true if not taken
bool Server::checkKey(std::string key){
	return overLord.freeKey(key);
}
//adds a user
void Server::addUser(User* user){
	if(user != NULL)
		overLord.add(user->getUsername(), user);
}
//removes a user
void Server::removeUser(User* user){
	if(user != NULL){
		Queue<string> stream;
		user->toQueueFollowing(stream);
		while(!stream.isEmpty()){
			unFollow(user, stream.pop());
		}
		user->toQueueFollowers(stream);
		while(!stream.isEmpty()){
			User* u2 = overLord.getData(stream.pop());
			unFollow(u2, user->getUsername());
		}
		overLord.remove(user->getUsername());
	}
}
//gets a user if the password matches
User* Server::getUser(std::string userName, std::string pass){
	if(!overLord.freeKey(userName)){
		User* temp = overLord.getData(userName);
		if(temp->matchPassword(pass)){
			return temp;
		}
	}
	return NULL;
}
//adds a tweet by a user and puts it into their followers
void Server::add(User* user, std::string post){
	//creates the tweet
	Tweet* twt = new Tweet(user->getUsername(), post);
	//gets a stream of their followers
	Queue<string> followerStream;
	user->toQueueFollowers(followerStream);
	//while the stream is not empty
	while(!followerStream.isEmpty()){
		//gets the follower's user object and adds the tweet
		User* temp = overLord.getData(followerStream.pop());
		temp->addTweet(twt);
	}
	//adds the tweet to the owners newsfeed too
	user->addTweet(twt);
}
//adds a tweet by user and tweet object
void Server::add(User* user, Tweet* twt){
	Queue<string> followerStream;
	user->toQueueFollowers(followerStream);
	//while the stream is not empty
	while(!followerStream.isEmpty()){
		//gets the follower's user object and adds the tweet
		User* temp = overLord.getData(followerStream.pop());
		temp->addTweet(twt);
	}
	//adds the tweet to the owners newsfeed too
	user->addTweet(twt);
}
//removes a tweet
void Server::remove(User* user, MyTweet pst){
	//gets a stream of the users followers
	Queue<string> followerStream;
	user->toQueueFollowers(followerStream);
	//while the follower stream is not empty
	while (!followerStream.isEmpty()){
		//gets the follower's user object and deletes the tweet
		User* temp = overLord.getData(followerStream.pop());
		temp->deleteTweet(pst);
	}
	//deletes it for the owner
	user->deleteTweet(pst);
}
//follow a user
void Server::follow(User* user, std::string unam){
	//follow them
	user->addFollowing(unam);
	User* u2 = overLord.getData(unam);
	//gets a stream of their tweets
	Queue<MyTweet> tStream;
	u2->toQueueMyTweet(tStream);
	//add the tweets to your newsfeed
	while(!tStream.isEmpty()){
		user->addTweet(tStream.pop().getTweet());
	}
	//add you as their follower
	u2->addFollower(user->getUsername());
}
//unfollow someone
void Server::unFollow(User* user, std::string unam){
	//removes them from your following
	user->removeFollowing(unam);
	User* u2 = overLord.getData(unam);
	//gets a stream of their tweets
	Queue<MyTweet> tStream;
	u2->toQueueMyTweet(tStream);
	//removes their tweets from your newsfeed
	while(!tStream.isEmpty()){
		user->deleteTweet(tStream.pop());
	}
	//remove you from their followers
	u2->removeFollower(user->getUsername());
}

void Server::addFollower(User* user, std::string unam){
	user->addFollower(unam);
	User* u2 = overLord.getData(unam);
	u2->addFollowing(user->getUsername());
}

//display all the users
void Server::displayUsers(){
	overLord.displayKeys();
}
//display the bst which holds the users
void Server::showIndentedKey(){
	overLord.showIndent();
}
//gets the efficenecy of inserting a string
void Server::getEff(){
	overLord.efficiency();
}

void Server::writeKey(){
	overLord.writeKeys();
}