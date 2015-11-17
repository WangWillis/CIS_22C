#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Classes\Data Structures\Hash.h"
#include "Classes\User.h"

using namespace std;

void DisplayLogo();
void Readfromfile(fstream&,HashTable <User*>);
int LoggedinSuccess(HashTable<User*>&, string, string);

int main()
{
	int menu = 0;
	int menu1=0;
	char input1;
	string user;
	string password;
	HashTable <User*> Data;
		//Read data of the users from an input file (We need 25 users...)
	string filename;
	filename = "UserData.txt"; //Change for address of this file 
	fstream UserFile;
	UserFile.open(filename, ios::in | ios::out);
	Queue<string> KeysHash;
	
	//Read keys of hash table and put them in a queue
	if (UserFile)
	{
		for (int cont = 0; UserFile.peek() != EOF; cont++)
		{
			getline(UserFile, user);
			KeysHash.add(user);
		}
	}

	//For all users of the hash table get their file and read their info
	for (int i = 0; i < KeysHash.numEle(); i++,KeysHash.pop()) //I will change this later :)
	{
		filename=KeysHash.get()+".txt";
		UserFile.open(filename, ios::in | ios::out);
		Readfromfile(UserFile, Data);
	}

	do
	{
		DisplayLogo();

		input1 = '\0';
		cout << " Welcome to Twitter. How may we assist you?..." << endl<<endl;
		cout << " Please enter 'L' to log in, 'N' to create a new account, or 'Q' to quit.\n ";
		cin.get(input1);
		input1 = toupper(input1);
		cin.clear();
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		while (input1 != 'L' && input1 != 'N' && input1 != 'Q')
		{
			cout << "\n Invalid input." << endl<<endl;
			cout << string(94, '-')<<endl;
			cout << "\n Please enter 'L' to log in, 'N' to create a new account, or 'Q' to quit.\n ";
			cin.get(input1);
			input1 = toupper(input1);
			cin.clear();
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		}
		cout <<endl <<string(94, '-') << endl<<endl;

		switch (input1)
		{
		case 'L':
		{
					menu1 = 0;
					cout << " Please enter your username: ";
					getline(cin, user);
					//check user against table
					while (Data.inSet(user) == false) //Search in the hash table for user 
					{
						cout << "\n I'm sorry, that username is not in our data banks.  Please try again..." << endl << endl;
						cout << " Username: ";
						getline(cin, user);  //loop this
					}

					cout << "\n Please enter your password:";
					getline(cin, password);

					User* obj = new User; 
					obj = Data.getData(user);

					//check password in the hash table
					while (obj->matchPassword(password) == false) //if not in table
					{
						cout << "\nI'm sorry, that password is incorrect.  Please try again..." << endl << endl;
						cout << " Password: ";
						getline(cin, password);  //loop this
					}
					delete obj;

					//on succcessful login you can do stuff
					cout << "\n You have successfully logged in." << endl;
					do
					{
						menu1 = LoggedinSuccess(Data, user, password);

					} while (menu1 == 0);
					break;
		}
		case 'N':
		{
					cout << " Please enter your desired username: ";
					getline(cin, user);
					//check if username is taken or is viable
					while (Data.inSet(user) == true) //if not viable
					{
						cout << "\n I'm sorry, that username is not available.  Please try again." << endl;
						cout << " Username: ";
						getline(cin, password);  //loop this
					}
					cout << "\n Please enter your desired password: ";
					getline(cin, password);
	
					//check if password is viable ?????Why????? 
					while (false) //if not viable
					{
						cout << "I'm sorry, that password is unavailable.  Please try again." << endl;
						getline(cin, password); //loop this
					}

					//Hash table needs to take care of dynamically allocated memory
					User* cur = new User(user, password);
					Data.addItem(user, cur);
					cout << "\n\n Your account has been successfully created." << endl;
					cout << string(94, '=')<<endl<<endl;
					do
					{
						menu1=LoggedinSuccess(Data, user, password);

					} while (menu1 == 0);
					break;
		}
		case 'Q':
			cout << "Thank you for using Twitter.  Good bye!" << endl;
			menu = 1;
			break;
		}
	} while (menu == 0);
	return 0;
}

void DisplayLogo()
{
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
}
void Readfromfile(fstream& UserFile,HashTable<User*> Data)
{
	if (UserFile)
	{
		for (int cont = 0; UserFile.peek() != EOF; cont++)
		{
			User* userobj = new User;
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
				Tweet *Tweetobj = NULL;
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
				ReTweet *RTweetobj = NULL;
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
				Tweets.addFront(Usertweetobj);
			}

			//Read newsfeed from input file
			cin.clear();
			cin.ignore();
			for (int i = 0; i < NTNewsF; i++)
			{
				getline(UserFile, tweet);
				Tweet *Tweetobj = NULL;
				Tweetobj->setUser(user);
				Tweetobj->setTweets(tweet);
				UserFile >> likes;
				Tweetobj->setlikes(likes);
				UserFile >> reTweets;
				Tweetobj->setRT(reTweets);
				UserFile >> postTime;
				Tweetobj->setpostim(postTime);
				UserTweet Usertweetobj;
				Usertweetobj.setPost(Tweetobj); //Does not take into account Tweet* rePost... WRONG
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

			Data.addItem(user,userobj); //Put all (not really) this information in the hash table :D
		}
	}

}

int LoggedinSuccess(HashTable<User*>& Data,string user,string password)
{
	User* USERobj = new User;
	USERobj = Data.getData(user);
	int input2, menu1=0;
	system("pause");
	system("CLS");
	DisplayLogo();
	cout << " Hi " << user << ", What would you like to do?..." << endl << endl;
	cout << "\t1) View my followers" << endl;
	cout << "\t2) View who I am following " << endl;
	cout << "\t3) Search for people to follow" << endl;
	cout << "\t4) View my Tweets" << endl;
	cout << "\t5) View my Newsfeed" << endl;
	cout << "\t6) Write a Tweet" << endl;
	cout << "\t7) Delete my account" << endl;
	cout << "\t8) Logout" << endl << endl;

	cout << " Please insert the number of your choice: ";
	cin >> input2;
	while ((input2<1) && (input2>8))
	{
		cout << " Invalid input." << endl;
		cout << " Try again... Please insert the number of your choice: ";
		cin >> input2;
	}

	cout <<endl <<endl<<string(94, '=')<<endl<<endl;
	switch (input2)
	{
	case 1://View Followers
	{
			   if (USERobj->getFollowers() == false)
				   cout << " Nobody is following you :("<<endl<<endl;
			   else{
				   List<string>* followrsList = new List<string>;
				   USERobj->toListFollowers();
				   int lenght = followrsList->countNodes();

				   cout << " Your Followers are:" << endl;
				   for (int i = 0; i < lenght; i++)
					   cout << followrsList->getDataPos(i) << endl;
				   cout << endl << string(94, '=') << endl << endl;
				   delete followrsList;

			   }
			     
			  break;
	}
	case 2: //View who are you following and unfollow someone
	{
				if (USERobj->getFollowing() == false)
					cout << " You are not following anybody" << endl << endl;
				else{
					cout << " You are Following:" << endl;
					List<string>* followngList = new List<string>;
					USERobj->toListFollowing();
					int lenght = followngList->countNodes();
					for (int i = 0; i < lenght; i++)
						cout << followngList->getDataPos(i) << endl;

					char choice;
					cout << endl << " Would you like to unfollow someone? Press 'Y' for Yes, or 'N' for No" << endl;
					cin.get(choice);
					choice = toupper(choice);
					cin.clear();
					cin.ignore(numeric_limits <streamsize> ::max(), '\n');
					while (choice != 'Y' && choice != 'N')
					{
						cout << "\n Invalid input." << endl << endl;
						cout << string(94, '-') << endl;
						cout << "\n Please press 'Y' for Yes, or 'N' for No\n ";
						cin.get(choice);
						choice = toupper(choice);
						cin.clear();
						cin.ignore(numeric_limits <streamsize> ::max(), '\n');
					}

					if (choice == 'Y')
					{
						string tounfollow;
						cout << " Please insert the username of the person you would like to unfollow\n";
						getline(cin, tounfollow);
						while (Data.inSet(tounfollow) == false)
						{
							cout << " This person does not exist in the people you follow" << endl;
							cout << " Please try again...\n";
							getline(cin, tounfollow);
						}
						char choice2;
						cout << "\n\n Are you sure you would like to unfollow " << tounfollow << " ?";
						cin.get(choice2);
						choice2 = toupper(choice2);
						cin.clear();
						cin.ignore(numeric_limits <streamsize> ::max(), '\n');
						while (choice2 != 'Y' && choice2 != 'N')
						{
							cout << "\n Invalid input." << endl << endl;
							cout << string(94, '-') << endl;
							cout << "\n Please press 'Y' for Yes, or 'N' for No\n ";
							cin.get(choice2);
							choice2 = toupper(choice2);
							cin.clear();
							cin.ignore(numeric_limits <streamsize> ::max(), '\n');
						}
						if (choice2 == 'Y')
						{
							followngList->delInfo(tounfollow);
							//Is there a function in the hash table to update the data?
							//Go to the person you unfollowed and erase your name from the followers list 
						}
					}
					delete followngList;
				}
			  break;
	}
	case 3:
		//case follow people
		//display people you aren't following (is this possible?)  If not possible, show all people, but distinguish who you're already following
		//ask for username and if you're sure
		//if sure follow, if not go back to view all people, q to quit
		break;
	case 4:
		//case view my tweets
		//cout my tweets
		//possible delete a tweet?  Edit a tweet?
		break;
	case 5:
		//case view newsfeed
		//cout newsfeed
		//like a tweet?  comment on tweet?  retweet? (how do we input which tweet we want to act on?
		break;
	case 6:
		//Case write a tweet
		break;
	case 7:
	{
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
			  char inputDelete = '\0';
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
	}
	case 8:
		cout << "Logout successful." << endl;
		cout << "Good bye! See you again next time!" << endl;
		menu1 = 1;
		break;
	}
	return menu1;
}
