#include <iostream>
#include <string>
using namespace std;

int main()
{
	char input;
	string user;
	string password;
	cout << "Welcome to Twatter.  How may we assist you?" << endl;
	cout << "Please enter 'L' to log in, 'N' to create a new account, 'D' to delte an old account, or 'Q' to quit." << endl;
	cin.get(input);
	switch (input)
	{
	case 'L':
		cout << "Please enter your username, or 'exit' to quit." << endl;
		cin >> user;
		//check user against table
		if (false) //if not in table
		{
			cout << "I'm sorry, that username is not in our data banks.  Please try again." << endl;
			cin >> user;  //loop this
		}
		cout << "Please enter your password, or exit to quit." << endl;
		cin >> password;
		//check user against hash
		if (false) //if not in table
		{
			cout << "I'm sorry, that password is incorrect.  Please try again." << endl;
			cin >> password;  //loop this
		}
		//on succcessful login you can do stuff
		cout << "What would you like to do?" << endl;
		cout << "View followers, view who you're following, follow people, view your tweets, view newsfeed, delete account, logout." << endl;
		
		//case view followers
		//display who is following you

		//case view following
		//display who you are following
		//option to unfollow people
		//asks for username and if you are sure
		//if sure, unfollow, if not go back to view following, Q to quit

		//case follow people
		//display people you aren't following (is this possible?)  If not possible, show all people, but distinguish who you're already following
		//ask for username and if you're sure
		//if sure follow, if not go back to view all people, q to quit

		//case view my tweets
		//cout my tweets
		//possible delete a tweet?  Edit a tweet?

		//case view newsfeed
		//cout newsfeed
		//like a tweet?  comment on tweet?  retweet? (how do we input which tweet we want to act on?

		//case delete account, move the code from below to here

		//case logout
		//logout
		//go back to main menu
		break;
	case 'N':
		cout << "Please enter your desired username, or exit to quit." << endl;
		cin >> user;
		//check if username is taken or is viable
		if (false) //if not viable
		{
			cout << "I'm sorry, that username is not available.  Please try again." << endl;
			cin >> user;  //loop this
		}
		cout << "Please enter your desired password, or exit to quit." << endl;
		cin >> password;
		//check if password is viable
		if (false) //if not viable
		{
			cout << "I'm sorry, that password is unavailable.  Please try again." << endl;
			cin >> password;  //loop this
		}
		cout << "Your account has been successfully created." << endl;
		break;
	case 'D': //actually move this case to when you're logged in
		cout << "Please enter your username, or 'exit' to quit." << endl;
		cin >> user;
		//check user against table
		if (false) //if not in table
		{
			cout << "I'm sorry, that username is not in our data banks.  Please try again." << endl;
			cin >> user;  //loop this
		}
		cout << "Please enter your password, or exit to quit." << endl;
		cin >> password;
		//check user against hash
		if (false) //if not in table
		{
			cout << "I'm sorry, that password is incorrect.  Please try again." << endl;
			cin >> password;  //loop this
		}
		cout << "Are you sure you wish to delete your account? (Y/N)" << endl;
		cin >> input;
		if (input == 'Y')
		{
			//delete account
		}
		else if (input == 'N')
		{
			//quit to main menu
		}
		break;
	case 'Q':
		cout << "Thank you for using Twatter.  Good bye!" << endl;
		return 0;
	}

}

//lab46 input validation maybe 55