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
	// while (!KeysHash.isEmpty())
	// {
	// 	string username, password, follower, follwng;
	// 	int numFollower, numFollowing;
	// 	if (infile)
	// 	{
	// 		KeysHash.pop();
	// 		//Username
	// 		getline(infile, username);
			
	// 		//password
	// 		getline(infile, password);
			

	// 		User* userin = new User(username,password);
	// 		//number of followers
	// 		infile >> numFollower;
	// 		userin->setFollowers(numFollower);
	// 		//number following
	// 		infile >> numFollowing;
	// 		userin->setFollowing(numFollowing);
	// 		if (infile.eof())
	// 		{
	// 			userin->setNumTweets(0);
	// 		}
	// 		else{
	// 			while (!infile.eof())
	// 			{
	// 				Tweet *temp = new Tweet;

	// 				string post;
	// 				long int hold;
	// 				time_t timeTemp;
	// 				getline(infile, username);
	// 				temp->setUser(username);
	// 				infile >> hold;
	// 				timeTemp = static_cast<time_t>(hold);
	// 				temp->setpostim(timeTemp);
	// 				getline(infile, post);
	// 				temp->setTweets(post);
	// 				userin->addTweet(temp);
	// 			}
	// 		}
	// 	}
	// }
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
	//choice for first menu
	int choice;
	do{
		//main menu
		cout << endl << "Welcome to Twitter!  Please enter a number to indicate what you wish to do." << endl;
		cout << "1. Login" << endl;
		cout << "2. Register" << endl;
		cout << "3. Show Users in BST" << endl;
		cout << "4. Show Efficiency of a key" << endl;
		cout << "5. Write Keys to file" << endl;
		cout << "6. Exit" << endl;
		cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		if(choice == 1){
			string username, pass;
			cout << "Please enter your username" << endl;
			getline(cin, username);
			cout << "Please enter your password" << endl;
			getline(cin, pass);
			//gets the user object returns NULL if not vaild pass or user
			User* user = helper.getUser(username, pass);
			//when not valid user or password
			if(user != NULL){
				int userChoice;
				cout << endl << "Welcome " << user->getUsername() << "!" << endl;
				do{
					//user's menu
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
					//adds a tweet
					if(userChoice == 1){
						string msg;
						cout << endl <<"What's on your mind?" << endl;
						cout << "Tweet Msg: " << endl;
						getline(cin, msg);
						helper.add(user, msg); 
					}else if(userChoice == 2){//displays the users newsfeed
						cout << endl;
						user->displayNewsFeed();
					}else if(userChoice == 3){//views their profile
						int pChoice;
						do{
							//menu for the users profile
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
							//views their tweets
							if(pChoice == 1){
								cout << endl;
								user->displayMyTweets();
							}else if(pChoice == 2){//deletes a tweet
								//displays all their tweets
								Queue<MyTweet> myTweetStream;
								user->toQueueMyTweet(myTweetStream);
								int i = 1;
								int option;
								if(!myTweetStream.isEmpty()){ 
									while(!myTweetStream.isEmpty()){ //somehow the queue is not empty even when it should be
										cout << i << ". " << myTweetStream.pop() << endl;
										i++;
									}
									//user selects a number to delete
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
								}else{//when the user has no tweets
									cout << "There are currently no tweets to delete." << endl;
								}
							}else if(pChoice == 3){//outputs the users followers
								cout << endl << "Number of Followers: " << user->getFollowers() << endl;
								user->displayFollowers();
							}else if(pChoice == 4){//out puts who the user follows
								cout << endl << "Number of People I Follow: " << user->getFollowing() << endl;
								user->displayFollowing();
							}else if(pChoice == 5){//unfollows a user
								string temp;
								cout << endl << "Please enter the username of the person you would like to Unfollow." << endl;
								getline(cin, temp);
								//checks to see if the user is following the person first
								if(user->amFollowing(temp)){
									helper.unFollow(user, temp);
									cout << "You have now unfollowed " << temp << "!" << endl;
								}else{//when a non vaild person is unfollowed
									cout << temp << " is not valid choice/you are not following " << temp << "!" << endl;
								}
							}else if(pChoice != 6){//for invalid inputs
								cout << "I'm sorry, that's an invalid input!" << endl;
							}
						}while(pChoice != 6);
					}else if(userChoice == 4){//display all the users for TWITTER
						cout << endl;
						helper.displayUsers();
					}else if(userChoice == 5){//following a user
						string temp;
						cout << endl << "Please enter the username of the person you would like to follow." << endl;
						getline(cin, temp);
						//checks if it is a valid user to follow
						if(!helper.checkKey(temp) && !user->amFollowing(temp)){
							helper.follow(user, temp);
							cout << "You are now following " << temp << "!" << endl;
						}else{
							cout << temp << " is not a valid user or already following!" << endl;
						}
					}else if(userChoice == 6){//exit the user logout 
						cout << "Goodbye! " << user->getUsername() << endl;
						user = NULL;
					}else{//for invalid inputs
						cout << "I'm sorry, that's an invalid input!" << endl;
					}
				}while(userChoice != 6);
			}else{//when user == NULL
				cout << "Invalid Username and/or Password!" << endl;
			}
		}else if(choice == 2){//for creating a new user
			string username, pass, test;
			//checking if good inputs
			bool isGood = false;
			do{
				cout << endl << "Enter your desired username. Or type 'exit' to exit this process." << endl;
				cout << "Your username cannot be user" << endl;
				getline(cin, username);
				test = username;
				//makes everything lowercase
				for (int i = 0; i < test.length(); i++)
				{
					test[i] = tolower(test[i]);
				}
				isGood = helper.checkKey(username);
				//checks the validity of the user name
				if ((!isGood || test == "user") && test != "exit"){
					cout << "Invalid User name" << endl;
				}
			}while((test != "exit") && (!isGood || test == "user"));//keeps going while the not exit or invalid user name
			if(test != "exit"){
				cout << "Please enter your desired password." << endl;
				getline(cin, pass);
				//creates the new user
				User* user = new User(username, pass);
				//adds user to the server
				helper.addUser(user);
				cout << "Your account has successfully been created!" << endl << endl;
			}
		}else if(choice == 3){
			//shows bst style keys
			helper.showIndentedKey();
		}else if(choice == 4){//gets the efficiency of the hash table
			helper.getEff();
		}else if(choice == 5){
			helper.writeKey();
			cout << "These keys were written to the file Keys.txt" << endl;
			helper.displayUsers();
		}else if(choice == 6){//exit
			cout << "Goodbye!" << endl << endl;
		}else{
			cout << "I'm sorry, that's an invalid input!" << endl << endl;
		}
	}while(choice != 6);//exit
	return 0;
}
