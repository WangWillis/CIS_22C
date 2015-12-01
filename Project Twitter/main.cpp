#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <fstream>
#include "Classes/Server.h"
#include "Classes/User.h"

using namespace std;
void inputfromfile();

int main(){
	Server helper;
	
	string filename;
	Queue<string> KeysHash;
	filename = "Keys.txt";
	ifstream infile;
	infile.open(filename);

	//Reads keys of the hashtable from input file and puts them in a queue
	if (infile)
	{
		while (!infile.eof())
		{
			string key;
			getline(infile, key);
			KeysHash.add(key);
		}
	}
	else
		cout << "File that holds keys of the hash table couldn't be open...\n";
	infile.close();


	while (!KeysHash.isEmpty())
	{
		User* userin=new User();
		string username, password, follower, follwng;
		int numFollower, numFollowing;
		
		filename = KeysHash.get() + ".txt";
		infile.open(filename);

		if (infile)
		{
			KeysHash.pop();
			//Username
			getline(infile, username);
			userin->setUsername(username);
			//password
			getline(infile, password);
			userin->setPassword(password);
			//number of followers
			infile >> numFollower;
			userin->setFollowers(numFollower);
			//number following
			infile >> numFollowing;
			userin->setFollowing(numFollowing);

			//Followers
			Queue<string> followers;

			for (int i = 0; i < numFollower; i++)
			{
				getline(infile, follower);
				followers.add(follower);
				userin->addFollower(follower);
			}

			//Following
			Queue<string> following;
			for (int i = 0; i < numFollowing; i++)
			{
				getline(infile, follwng);
				following.add(follwng);
				userin->addFollowing(follwng);
			}

			//myTweets
			while (!infile.eof())
			{
				Tweet *temp=new Tweet;

				string post;
				long int hold;
				time_t timeTemp;
				getline(infile, username);
				temp->setUser(username);
				infile >> hold;
				timeTemp = static_cast<time_t>(hold);
				temp->setpostim(timeTemp);
				getline(infile, post);
				temp->setTweets(post);
				userin->addTweet(temp);
			}

			helper.addUser(userin); //Adds user to the hash table using the server			
			infile.close();
		}

		else
		{
			cout << "File of user " << KeysHash.get() << " could not be opened";
			KeysHash.pop();
		}

	}
	
	cout << string(94, '=') << endl << endl;
	cout << " /$$$$$$$$            /$$   /$$     /$$                                              .--.     " << endl;
	cout << "|__  $$__/           |__/  | $$    | $$                                            .'  o \\__ " << endl;
	cout << "   | $$ /$$  /$$  /$$ /$$ /$$$$$$ /$$$$$$    /$$$$$$   /$$$$$$                 _.-'    , (  ` " << endl;
	cout << "   | $$| $$ | $$ | $$| $$|_  $$_/|_  $$_/   /$$__  $$ /$$__  $$           _.-''      ,;; |    " << endl;
	cout << "   | $$| $$ | $$ | $$| $$  | $$    | $$    | $$$$$$$$| $$  \\__/      _.-=' _,'      ,,;;;'    " << endl;
	cout << "   | $$| $$ | $$ | $$| $$  | $$ /$$| $$ /$$| $$_____/| $$         .-'`_.- '``-..,,;;;;:'      " << endl;
	cout << "   | $$|  $$$$$/$$$$/| $$  |  $$$$/|  $$$$/|  $$$$$$$| $$         `''`           `\\`\\       " << endl;
	cout << "   |__/ \\_____/\\___/ |__/   \\___/   \\___/   \\_______/|__/                         /^\\\\\\    " << endl << endl;
	cout << string(94, '=') << endl;
	int choice;
	do{
		cout << endl << "Welcome to Twitter!  Please enter a number to indicate what you wish to do." << endl;
		cout << "1. Login" << endl;
		cout << "2. Register" << endl;
		cout << "3. Show Users in BST" << endl;
		cout << "4. Exit" << endl;
		cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		if(choice == 1){
			string username, pass;
			cout << "Please enter your username" << endl;
			getline(cin, username);
			cout << "Please enter your password" << endl;
			getline(cin, pass);
			User* user = helper.getUser(username, pass);
			if(user != NULL){
				int userChoice;
				cout << endl << "Welcome " << user->getUsername() << "!" << endl;
				do{
					cout << endl << "What would you like to do?  Please enter a valid choice." << endl;
					cout << "1. Add Tweet" << endl;
					cout << "2. View Newsfeed" << endl;
					cout << "3. View My Profile" << endl;
					cout << "4. Display all Users" << endl;
					cout << "5. Follow User" << endl;
					cout << "6. Logout" << endl;
					cin >> userChoice;
					cin.clear();
					cin.ignore(numeric_limits <streamsize> ::max(), '\n');
					if(userChoice == 1){
						string msg;
						cout << endl <<"What's on your mind?" << endl;
						cout << "Tweet Msg: " << endl;
						getline(cin, msg);
						helper.add(user, msg); //crashes here
					}else if(userChoice == 2){
						cout << endl;
						user->displayNewsFeed();
					}else if(userChoice == 3){
						int pChoice;
						do{
							cout << endl << "What would you like to do?  Please enter a valid choice." << endl;
							cout << "1. View My Tweets" << endl;
							cout << "2. Delete a Tweet" << endl;
							cout << "3. View My Followers" << endl;
							cout << "4. View who I am Following" << endl;
							cout << "5. Unfollow" << endl;
							cout << "6. Back" << endl;
							cin >> pChoice;
							cin.clear();
							cin.ignore(numeric_limits <streamsize> ::max(), '\n');
							if(pChoice == 1){
								cout << endl;
								user->displayMyTweets();
							}else if(pChoice == 2){
								Queue<MyTweet> myTweetStream;
								user->toQueueMyTweet(myTweetStream);
								int i = 1;
								int option;
								if(!myTweetStream.isEmpty()){ 
									while(!myTweetStream.isEmpty()){ //somehow the queue is not empty even when it should be
										cout << i << ". " << myTweetStream.pop() << endl;
										i++;
									}
									cout << "Please select the Tweet you would like to delete by entering its number." << endl;
									cin >> option;
									cin.clear();
									cin.ignore(numeric_limits <streamsize> ::max(), '\n');
									if(option <= i && option >= 1){
										MyTweet temp = user->getMyTweet(option-1);
										helper.remove(user, temp);
										cout << "The Tweet has been successfully deleted" << endl;
									}else{
										cout << "I'm sorry, that's an invalid input!" << endl;
									}
								}else{
									cout << "There are currently no tweets to delete." << endl;
								}
							}else if(pChoice == 3){
								cout << endl << "Number of Followers: " << user->getFollowers() << endl;
								user->displayFollowers();
							}else if(pChoice == 4){
								cout << endl << "Number of People I Follow: " << user->getFollowing() << endl;
								user->displayFollowing();
							}else if(pChoice == 5){
								string temp;
								cout << endl << "Please enter the username of the person you would like to Unfollow." << endl;
								getline(cin, temp);
								if(user->amFollowing(temp)){
									helper.unFollow(user, temp);
									cout << "You have now unfollowed " << temp << "!" << endl;
								}else{
									cout << temp << " is not valid choice/you are not following " << temp << "!" << endl;
								}
							}else if(pChoice != 6){
								cout << "I'm sorry, that's an invalid input!" << endl;
							}
						}while(pChoice != 6);
					}else if(userChoice == 4){
						cout << endl;
						helper.displayUsers();
					}else if(userChoice == 5){
						string temp;
						cout << endl << "Please enter the username of the person you would like to follow." << endl;
						getline(cin, temp);
						if(!helper.checkKey(temp)){
							helper.follow(user, temp);  //crashes here
							cout << "You are now following " << temp << "!" << endl;
						}else{
							cout << temp << " is not a valid user!" << endl;
						}
					}else if(userChoice == 6){
						cout << "Goodbye!" << user->getUsername() << endl;
						user = NULL;
					}else{
						cout << "I'm sorry, that's an invalid input!" << endl;
					}
				}while(userChoice != 6);
			}else{
				cout << "Invalid Username and/or Password!" << endl;
			}
		}else if(choice == 2){
			string username, pass, test;
			bool isGood = false;
			do{
				cout << endl << "Enter your desired username. Or type 'exit' to exit this process." << endl;
				cout << "Your username cannot be user" << endl;
				getline(cin, username);
				test = username;
				for (int i = 0; i < test.length(); i++)
				{
					test[i] = tolower(test[i]);
				}
				isGood = helper.checkKey(username);
				if ((!isGood || test == "user") && test != "exit"){
					cout << "Invalid User name" << endl;
				}
			}while((test != "exit") && (!isGood || test == "user"));
			if(test != "exit"){
				cout << "Please enter your desired password." << endl;
				getline(cin, pass);
				//can put a make sure for password here
				User* user = new User(username, pass);
				helper.addUser(user);
				cout << "Your account has successfully been created!" << endl << endl;
			}
		}else if(choice == 3){
			helper.showIndentedKey();
		}else if(choice == 4){
			cout << "Goodbye!" << endl << endl;
		}else{
			cout << "I'm sorry, that's an invalid input!" << endl << endl;
		}
	}while(choice != 4);
	return 0; //crashes if a user was created.  User destructor must be broken
}

// void inputfromfile()
// {
// 	Server input;
	
// 	string filename;
// 	Queue<string> KeysHash;
// 	filename = "Keys.txt"; 
// 	ifstream infile;
// 	infile.open(filename);

// 	//Reads keys of the hashtable from input file and puts them in a queue
// 	if (infile)
// 	{
// 		while (!infile.eof())
// 		{
// 			string key;
// 			getline(infile, key);
// 			KeysHash.add(key);
// 		}
// 	}
// 	else
// 		cout << "File that holds keys of the hash table couldn't be open...\n";
// 	infile.close();

	
// 	while (!KeysHash.isEmpty())
// 	{
// 		User* user = new User();
// 		string username,password,follower,follwng;
// 		int numFollower,numFollowing;
// 	filename = KeysHash.get() + ".txt";
// 	infile.open(filename);

// 	if (infile)
// 	{
// 		KeysHash.pop();
// 		//Username
// 		getline(infile, username);
// 		user->setUsername(username);
// 		//password
// 		getline(infile, password);
// 		user->setPassword(password);
// 		//number of followers
// 		infile >> numFollower;
// 		user->setFollowers(numFollower);
// 		//number following
// 		infile >> numFollowing;
// 		user->setFollowing(numFollowing);
		
// 		//Followers
// 		Queue<string> followers;
// 		cin.clear();
// 		cin.ignore(numeric_limits<streamsize>::max(), '\n');
// 		for (int i = 0; i < numFollower; i++)
// 		{
// 			getline(infile, follower);
// 			followers.add(follower);
// 			user->addFollower(follower);
// 		}

// 		//Following
// 		Queue<string> following;
// 		for (int i = 0; i < numFollowing; i++)
// 		{
// 			getline(infile, follwng);
// 			following.add(follwng);
// 			user->addFollowing(follwng);
// 		}

// 		//myTweets
// 		while (!infile.eof())
// 		{
// 			Tweet* temp = new Tweet();
// 			string post;
// 			time_t timeTemp;
// 			getline(infile, username);
// 			temp->setUser(username);
// 			infile >> timeTemp;
// 			temp->setpostim(timeTemp);
// 			cin.clear();
// 			cin.ignore(numeric_limits<streamsize>::max(), '\n');
// 			getline(infile, post);
// 			temp->setTweets(post);
// 			user->addTweet(temp); 

// 			input.addUser(user); //Adds user to the hash table using the server
// 			delete temp;
// 		}

// 		delete user;
// 		infile.close();
// 	}

// 	else
// 	{
// 		cout << "File of user " << KeysHash.get() << " could not be opened";
// 		KeysHash.pop();
// 	}
// 	}

// }

