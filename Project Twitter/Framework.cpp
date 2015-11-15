#include <iostream>
#include <string>
#include "Data Structures\Hash\Hash.h"
using namespace std;

int main()
{
	//Read data of the users from an input file (We need 25 users...)
	string filename;
	filename = "UserData.txt"; //Change for address of this file 
	fstream UserFile;
	UserFile.open(filename, ios::in | ios::out);

	if (UserFile)
	{
		for (int cont = 0; UserFile.peek() != EOF; cont++)
		{
			User* userobj=NULL;
			string user, passwr;
			int NFollowrs, NFollowng, NTweets, NRetweets, NTNewsF;
			
			List<UserTweet>Tweets;
			string tweet;
			int likes, reTweets;
			time_t postTime;
			List <UserTweet> retweets;
			
			AVLTree <UserTweet> newsF;
			
			AVLTree <string> Followrs;
			string followr;
			
			AVLTree <string> Followng;
			string followng;
			
			getline(UserFile, user);
			userobj->setUsername(user);
			getline(UserFile, passwr);
			userobj->setPassword(passwr);
			UserFile >> NFollowrs;
			userobj->setFollowers(NFollowrs);
			UserFile >> NFollowng;
			userobj->setFollowing(NFollowng);
			UserFile >> NTweets;
			userobj->setNumTweets(NTweets);
			UserFile >> NRetweets;
			userobj->setNumRTweets(NRetweets);
			UserFile >> NTNewsF;
			userobj->setNumNewsF(NTNewsF);

			//Read tweets from input file
			cin.clear();
			cin.ignore();
			for (int i = 0; i < NTweets; i++)
			{
				getline(UserFile, tweet);
				Tweet *Tweetobj=NULL;
				Tweetobj->setUser(user);
				Tweetobj->setTweets(tweet);
				UserFile >> likes;
				Tweetobj->setlikes(likes); 
				UserFile >> reTweets;
				Tweetobj->setRT(reTweets);
				UserFile >> postTime;
				Tweetobj->setpostim(postTime); 
				UserTweet Usertweetobj;
				Usertweetobj.setPost(Tweetobj); //Does not take into account Tweet* rePost and bool liked, reTweet..... WRONG
				Tweets.addFront(Usertweetobj);
			}

			//Read Retweets from input file
			cin.clear();
			cin.ignore();
			for (int i = 0; i < NRetweets; i++)
			{
				getline(UserFile, tweet);
				ReTweet *RTweetobj=NULL;
				RTweetobj->setUser(user);
				RTweetobj->setTweets(tweet);
				UserFile >> likes;
				RTweetobj->setlikes(likes);
				UserFile >> reTweets;
				RTweetobj->setRT(reTweets);
				UserFile >> postTime;
				RTweetobj->setpostim(postTime);
				UserTweet Usertweetobj;
				Usertweetobj.setPost(RTweetobj); //Does not take into account Tweet* rePost and bool liked, reTweet..... WRONG
				retweets.addFront(Usertweetobj);
			}

			//Read newsfeed from input file
			cin.clear();
			cin.ignore();
			for (int i = 0; i < NTNewsF; i++)
			{
				getline(UserFile, tweet);
				Tweet *Tweetobj=NULL;
				Tweetobj->setUser(user);
				Tweetobj->setTweets(tweet);
				UserFile >> likes;
				Tweetobj->setlikes(likes);
				UserFile >> reTweets;
				Tweetobj->setRT(reTweets);
				UserFile >> postTime;
				Tweetobj->setpostim(postTime);
				UserTweet Usertweetobj;
				Usertweetobj.setPost(Tweetobj); //Does not take into account Tweet* rePost and bool liked, reTweet..... WRONG
				newsF.add(Usertweetobj);
			}

			//Read followers from input file
			for (int i = 0; i < NFollowrs; i++)
			{
				getline(UserFile, followr);
				Followrs.add(followr);
				//Add this tree to the user object......
			}

			//Read following from input file
			for (int i = 0; i < NFollowng; i++)
			{
				getline(UserFile, followng);
				Followng.add(followng);
				//Add this tree to the user object
			}

			//Put all this information in the hash table :D
		}
	}
	
	int menu = 0;
	int menu1;
	char input1;
	char input2;
	char inputDelete;
	
	do
	{
		cout << string(94,'=')<<endl<<endl;
		cout << " /$$$$$$$$            /$$   /$$     /$$                                              .--.     " << endl;
		cout << "|__  $$__/           |__/  | $$    | $$                                            .'  o \\__ " << endl;
		cout << "   | $$ /$$  /$$  /$$ /$$ /$$$$$$ /$$$$$$    /$$$$$$   /$$$$$$                 _.-'    , (  ` " << endl;
		cout << "   | $$| $$ | $$ | $$| $$|_  $$_/|_  $$_/   /$$__  $$ /$$__  $$           _.-''      ,;; |    " << endl;
		cout << "   | $$| $$ | $$ | $$| $$  | $$    | $$    | $$$$$$$$| $$  \\__/      _.-=' _,'      ,,;;;'    " << endl;
		cout << "   | $$| $$ | $$ | $$| $$  | $$ /$$| $$ /$$| $$_____/| $$         .-'`_.- '``-..,,;;;;:'      " << endl;
		cout << "   | $$|  $$$$$/$$$$/| $$  |  $$$$/|  $$$$/|  $$$$$$$| $$         `''`           `\\`\\       " << endl;
		cout << "   |__/ \\_____/\\___/ |__/   \\___/   \\___/   \\_______/|__/                         /^\\\\\\    " << endl<<endl;
		cout << string(94, '=') << endl << endl;
		
		input1 = '\0';
		cout << "Welcome to Twatter.  How may we assist you?" << endl;
		cout << "Please enter 'L' to log in, 'N' to create a new account, or 'Q' to quit." << endl;
		cin.get(input1);
		input1 = toupper(input1);
		cin.clear();
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		while (input1 != 'L' && input1 != 'N' && input1 != 'Q')
		{
			cout << "Invalid input." << endl;
			cout << "Please enter 'L' to log in, 'N' to create a new account, or 'Q' to quit." << endl;
			cin.get(input1);
			input1 = toupper(input1);
			cin.clear();
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		}
		switch (input1)
		{
		case 'L':
			menu1 = 0;
			cout << "Please enter your username, or 'exit' to quit." << endl;
			getline(cin, user);
			cin.clear();
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
			//check user against table
			if (false) //if not in table
			{
				cout << "I'm sorry, that username is not in our data banks.  Please try again." << endl;
				cin >> user;  //loop this
			}
			cout << "Please enter your password, or exit to quit." << endl;
			getline(cin, password);
			cin.clear();
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
			//check user against hash
			if (false) //if not in table
			{
				cout << "I'm sorry, that password is incorrect.  Please try again." << endl;
				getline(cin, password);  //loop this
			}
			//on succcessful login you can do stuff
			cout << "You have successfully logged in." << endl;
			do
			{
				input2 = '\0';
				cout << "What would you like to do?" << endl;
				cout << "Input (A) to view followers, (B) to view who you're following," << endl;
				cout << "(F) to follow people, (M) view your tweets, (N) to view newsfeed," << endl;
				cout << "(T) to make a tweet, (D) to delete account, or (L) to logout." << endl;
				cin.get(input2);
				input2 = toupper(input2);
				cin.clear();
				cin.ignore(numeric_limits <streamsize> ::max(), '\n');
				while (input2 != 'A' && input2 != 'B' && input2 != 'F' && input2 != 'M' && input2 != 'N' && input2 != 'T' && input2 != 'D' && input2 != 'L')
				{
					cout << "Invalid input." << endl;
					cout << "Input (A) to view followers, (B) to view who you're following," << endl;
					cout << "(F) to follow people, (M) view your tweets, (N) to view newsfeed," << endl;
					cout << "(T) to make a tweet, (D) to delete account, or (L) to logout." << endl;
					cin.get(input2);
					input2 = toupper(input2);
					cin.clear();
					cin.ignore(numeric_limits <streamsize> ::max(), '\n');
				}
				switch (input2)
				{
				case 'A':
					//case view followers
					//display who is following you
					break;
				case 'B':
					//case view following
					//display who you are following
					//option to unfollow people
					//asks for username and if you are sure
					//if sure, unfollow, if not go back to view following, Q to quit
					break;
				case 'F':
					//case follow people
					//display people you aren't following (is this possible?)  If not possible, show all people, but distinguish who you're already following
					//ask for username and if you're sure
					//if sure follow, if not go back to view all people, q to quit
					break;
				case 'M':
					//case view my tweets
					//cout my tweets
					//possible delete a tweet?  Edit a tweet?
					break;
				case 'N':
					//case view newsfeed
					//cout newsfeed
					//like a tweet?  comment on tweet?  retweet? (how do we input which tweet we want to act on?
					break;
				case 'D':
					cout << "Please enter your username, or 'exit' to quit." << endl;
					cin >> user;
					cin.clear();
					cin.ignore(numeric_limits <streamsize> ::max(), '\n');
					//check user against table
					if (false) //if not in table
					{
						cout << "I'm sorry, that username is not in our data banks.  Please try again." << endl;
						cin >> user;  //loop this
					}
					cout << "Please enter your password, or exit to quit." << endl;
					cin >> password;
					cin.clear();
					cin.ignore(numeric_limits <streamsize> ::max(), '\n');
					//check user against hash
					if (false) //if not in table
					{
						cout << "I'm sorry, that password is incorrect.  Please try again." << endl;
						cin >> password;  //loop this
					}
					inputDelete = '\0';
					cout << "Are you sure you wish to delete your account? (Y/N)" << endl;
					cin.get(inputDelete);
					inputDelete = toupper(inputDelete);
					cout << inputDelete << endl;
					cin.clear();
					cin.ignore(numeric_limits <streamsize> ::max(), '\n');
					while (inputDelete != 'Y' && inputDelete != 'N')
					{
						cout << "Invalid input." << endl;
						cout << "Are you sure you wish to delete your account? (Y/N)" << endl;
						cin.get(inputDelete);
						inputDelete = toupper(inputDelete);
						cin.clear();
						cin.ignore(numeric_limits <streamsize> ::max(), '\n');
					}
					if (inputDelete == 'Y')
					{
						//delete account
						cout << "Your account has successfully been deleted." << endl;
						cout << "Logging out.  Good bye!" << endl;
						menu1 = 1;
					}
					else if (inputDelete == 'N')
					{
						cout << "Canceling deletion." << endl;
					}
					break;
				case 'L':
					cout << "Logout successful." << endl;
					cout << "Good bye! See you again next time!" << endl;
					menu1 = 1;
					break;
				}
			} while (menu1 == 0);
			break;
		case 'N':
			string user;
			string password;
			cout << "Please enter your desired username, or exit to quit." << endl;
			getline(cin, user);
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
			//check if username is taken or is viable
			if (false) //if not viable
			{
				cout << "I'm sorry, that username is not available.  Please try again." << endl;
				getline(cin, password);  //loop this
			}
			cout << "Please enter your desired password, or exit to quit." << endl;
			getline(cin, password);
			cin.clear();
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
			//check if password is viable
			if (false) //if not viable
			{
				cout << "I'm sorry, that password is unavailable.  Please try again." << endl;
				getline(cin, password); //loop this
			}
			//Hash table needs to take care of dynamically allocated memory
			User* cur = new User(user, password);
			cout << "Your account has been successfully created." << endl;
			break;
		case 'Q':
			cout << "Thank you for using Twatter.  Good bye!" << endl;
			menu = 1;
			break;
		}
	} while (menu == 0);
	return 0;
}

//lab46 input validation maybe 55
