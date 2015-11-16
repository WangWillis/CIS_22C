void add(User* user, string post, HashTable hash){
	Tweet* twt = new Tweet(user->getUsername(), post);
	user->addTweet(twt);
	Queue followerStream = user->toQueueFollowers();
	while(!followerStream.isEmpty()){
		User* temp = hash.getData(followerStream.pop());
		temp->addTweet(twt);
	}
}

void remove(User* user, MyTweet pst, HashTable hash){
	Queue followerStream = user->toQueueFollowers();
	while(!followerStream.isEmpty()){
		User* temp = hash.getData(followerStream.pop());
		UserTweet utt = temp->getUserTweet(pst.getTweet());
		if(utt.isReTweet()){
			remove(temp, temp->getMyReTweet(utt.getRePost()), hash);
		}
		temp->deleteTweet(pst);
	}
	user->deleteTweet(pst);
}