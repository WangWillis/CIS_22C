#include "BST.h"
#include "List.h"
#include "Tweet.h"
#include <string>

using namespace std;

class User;

class User{
	private:
		string userName, password;
	public:
		User();
		~User();
};