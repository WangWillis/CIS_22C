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
	Queue<string> userQueue;
	Queue<string> passQueue;
	filename = "Users/user.txt";
	ifstream infile;
	infile.open(filename.c_str());

	//Reads keys of the hashtable from input file and puts them in a queue
	if (infile)
	{
		string key;
		while (getline(infile, key))
		{
			string pass;
			getline(infile, pass);
			User* temp = new User(key, pass);
			helper.addUser(temp);
			userQueue.add(key);
			passQueue.add(pass);
		}
	}
	else
		cout << "File that holds keys of the hash table couldn't be open...\n";
	infile.close();
	while (!userQueue.isEmpty())
	{
		
		string userName = userQueue.pop();
		int numFollower;
		
		filename = "Users/" + userName + ".txt";
		infile.open(filename.c_str());

		if (infile)
		{
			User* user = helper.getUser(userName, passQueue.pop());
			//number following
			string lines;
			getline(infile, lines);
			numFollower = atoi(lines.c_str());
			for (int i = 0; i < numFollower; i++)
			{
				getline(infile, lines);
				helper.addFollower(user, lines);
			}
			while(getline(infile, lines))
			{
				string post;
				int date = 0, hr = 0, mn = 0, sec = 0, year = 0,holdWdat = 0, holdMonth = 0;
				char day[3], month[3],dtm[200];
				infile.getline(dtm, 200, '\n');
				sscanf(dtm, "%s %s %d %d:%d:%d %d", day, month, &date, &hr, &mn, &sec, &year);
				
				string Month[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
				for (int i = 0; i < 12; i++)
				{
					if (Month[i] == month)
					{
						holdMonth = i;
						break;
					}
				}
				string Wday[7] = { "Sun","Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
				for (int i = 0; i < 7; i++)
				{
					if (Wday[i] == day)
					{
						holdWdat = i;
						break;
					}
				}
				time_t rawtime;
				struct tm *timeinfo;
				time(&rawtime);
				timeinfo = localtime(&rawtime);

				timeinfo->tm_wday = holdWdat;
				timeinfo->tm_mon = holdMonth;
				timeinfo->tm_mday = date;
				timeinfo->tm_hour = hr;
				timeinfo->tm_min = mn;
				timeinfo->tm_sec = sec;
				timeinfo->tm_year = year-1900;
				timeinfo->tm_isdst = 0;
				time_t timeTemp = mktime(timeinfo);
				getline(infile, post);
				Tweet* temp = new Tweet(lines, post, timeTemp);
				helper.add(user, temp);
				//time_t does not always work so there are sometimes incorrect time comparisons
			}	
		}
		infile.close();
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
	//choice for first menu
	int choice;
	do{
		//main menu
		cout << endl << "Welcome to Twitter!  Please enter a number to indicate what you wish to do." << endl;
		cout << "1. Login" << endl;
		cout << "2. Register" << endl;
		cout << "3. Show Users in BST" << endl;
		cout << "4. Show Efficiency" << endl;
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
					cout << "7. Delete Account" << endl;
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
								int i = 0;
								int option;
								if(!myTweetStream.isEmpty()){ 
									while(!myTweetStream.isEmpty()){ //somehow the queue is not empty even when it should be
										i++;
										cout << i << ". " << myTweetStream.pop() << endl;
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
						if(!helper.checkKey(temp) && !user->amFollowing(temp) && temp != user->getUsername()){
							helper.follow(user, temp);
							cout << "You are now following " << temp << "!" << endl;
						}else{
							cout << temp << " is not a valid user or already following!" << endl;
						}
					}else if(userChoice == 6){//exit the user logout 
						cout << "Goodbye! " << user->getUsername() << endl;
						user = NULL;
					}else if(userChoice == 7){
						int sure;
						cout << "enter 1 for confirmation" << endl;
						cin >> sure;
						cin.clear();
						cin.ignore(numeric_limits <streamsize> ::max(), '\n');
						if(sure == 1){
							string fileNam = "Users/" + user->getUsername() + ".txt";
							helper.removeUser(user);
							user = NULL;
							remove(fileNam.c_str());
							cout << "Your account has been deleted" << endl;
						}else{
							userChoice = 0;
						}
					}else{//for invalid inputs
						cout << "I'm sorry, that's an invalid input!" << endl;
					}
				}while(userChoice != 6 && userChoice != 7);
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
