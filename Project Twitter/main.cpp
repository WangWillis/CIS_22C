#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Classes/Server.h"
#include "Classes/User.h"

using namespace std;

int main(){
	Server helper;
	cout << string(94, '=') << endl << endl;
	cout << " /$$$$$$$$            /$$   /$$     /$$                                              .--.     " << endl;
	cout << "|__  $$__/           |__/  | $$    | $$                                            .'  o \\__ " << endl;
	cout << "   | $$ /$$  /$$  /$$ /$$ /$$$$$$ /$$$$$$    /$$$$$$   /$$$$$$                 _.-'    , (  ` " << endl;
	cout << "   | $$| $$ | $$ | $$| $$|_  $$_/|_  $$_/   /$$__  $$ /$$__  $$           _.-''      ,;; |    " << endl;
	cout << "   | $$| $$ | $$ | $$| $$  | $$    | $$    | $$$$$$$$| $$  \\__/      _.-=' _,'      ,,;;;'    " << endl;
	cout << "   | $$| $$ | $$ | $$| $$  | $$ /$$| $$ /$$| $$_____/| $$         .-'`_.- '``-..,,;;;;:'      " << endl;
	cout << "   | $$|  $$$$$/$$$$/| $$  |  $$$$/|  $$$$/|  $$$$$$$| $$         `''`           `\\`\\       " << endl;
	cout << "   |__/ \\_____/\\___/ |__/   \\___/   \\___/   \\_______/|__/                         /^\\\\\\    " << endl << endl;
	cout << string(94, '=') << endl << endl;
	int choice;
	do{
		cout << "1. Login" << endl;
		cout << "2. Register" << endl;
		cout << "3. Exit" << endl;
		cin >> choice;
		if(choice == 1){
			cin.ignore();
			string username, pass;
			cout << "Please enter your username" << endl;
			getline(cin, username);
			cout << "Please enter your password" << endl;
			getline(cin, pass);
			User* user = helper.getUser(username, pass);
			if(user != NULL){
				int userChoice;
				cout << "Welcome " << user->getUsername() << endl;
				do{
					cout << "1. Add Tweet" << endl;
					cout << "2. View Newsfeed" << endl;
					cout << "3. View My Profile" << endl;
					cout << "4. Display all users" << endl;
					cout << "5. Follow User" << endl;
					cout << "6. Logout" << endl;
					cin >> userChoice;
					if(userChoice == 1){
						cin.ignore();
						string msg;
						cout << "Tweet Msg: " << endl;
						getline(cin, msg);
						helper.add(user, msg);
					}else if(userChoice == 2){
						user->displayNewsFeed();
					}else if(userChoice == 3){
						int pChoice;
						do{
							cout << "1. View My Tweets" << endl;
							cout << "2. Delete a Tweet" << endl;
							cout << "3. View My Followers" << endl;
							cout << "4. View who I am Following" << endl;
							cout << "5. Back" << endl;
							cin >> pChoice;
							if(pChoice == 1){
								user->displayMyTweets();
							}else if(pChoice == 2){
								Queue<MyTweet> myTweetStream = user->toQueueMyTweet();
								int i = 1;
								int option;
								if(!myTweetStream.isEmpty()){
									while(!myTweetStream.isEmpty()){
										cout << i << ". " << myTweetStream.pop() << endl;
										i++;
									}
									cout << "Please select the Tweet you would like to delete by number" << endl;
									cin >> option;
									if(option <= i && option >= 1){
										MyTweet temp = user->getMyTweet(option-1);
										helper.remove(user, temp);
										cout << "Deleted" << endl;
									}else{
										cin.clear();
										cin.ignore();
										cout << "Invalid Input" << endl;
									}
								}else{
									cout << "No Tweets to Delete" << endl;
								}
							}else if(pChoice == 3){
								cout << "Number of Followers: " << user->getFollowers() << endl;
								user->displayFollowers();
							}else if(pChoice == 4){
								cout << "Number of People I Follow " << user->getFollowing() << endl;
								user->displayFollowing();
							}else if(pChoice != 5){
								cin.clear();
								cin.ignore();
								cout << "Invalid input" << endl;
							}
						}while(pChoice != 5);
					}else if(userChoice == 4){
						helper.displayUsers();
					}else if(userChoice == 5){
						cin.ignore();
						string temp;
						cout << "Enter the username of the person you would like to follow" << endl;
						getline(cin, temp);
						if(!helper.checkKey(temp)){
							helper.follow(user, temp);
							cout << "You are now following " << temp << endl;
						}else{
							cout << temp << " is not a valid user" << endl;
						}
					}else if(userChoice == 6){
						cout << "Goodbye " << user->getUsername() << endl;
						user = NULL;
					}else{
						cin.clear();
						cin.ignore();
						cout << "Invalid input" << endl;
					}
				}while(userChoice != 6);
			}else{
				cout << "Invalid Username and/or Password" << endl;
			}
		}else if(choice == 2){
			cin.ignore();
			string username, pass;
			bool isGood = false;
			do{
				cout << "Enter your desired username. Type exit to exit this process" << endl;
				cout << "Your username cannot be user" << endl;
				getline(cin, username);
				isGood = helper.checkKey(username);
				if((!isGood || username == "user") && (username != "exit" || username != "Exit")){
					cout << "Invalid User name" << endl;
				}
			}while((username != "exit" || username != "Exit") && (!isGood || username == "user"));
			if((username != "exit" && username != "Exit")){
				cout << "Please enter your desired password" << endl;
				getline(cin, pass);
				//can put a make sure for password here
				User* user = new User(username, pass);
				helper.addUser(user);
				cout << "New user created" << endl;
			}
		}else if(choice == 3){
			cout << "Goodbye" << endl;
		}else{
			cin.ignore();
			cin.clear();
			cin.ignore();
			cout << "Invalid input" << endl;
		}
	}while(choice != 3);
	return 0;
}