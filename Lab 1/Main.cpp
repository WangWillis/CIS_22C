// Names: Randy Manzanarez, Willis Wang
// Lab 1
// Assume when people pass in enum and money they pass in the right money type for the enum so no pass in (DOLLAR, Pounds object) will return false
// Assume all money object gets memory from the heap
// if sub more than have will become 0 w 0 p but have to remove that with option 3 since like to show it has been handled 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Wallet.h"

using namespace std;

//function to get a new money object
Currency* getMoney(int c2){
	unsigned seed = time(0);
	srand(seed);
	int whole = rand()%100;
	int part = rand()%100;
	if(c2 == 1){
		return new Dollar(whole, part);
	}else if(c2 == 2){
		return new Pounds(whole, part);
	}else if(c2 == 3){
		return new Euros(whole, part);
	}else if(c2 == 4){
		return new Pesos(whole, part);
	}else if(c2 == 5){
		return new Rubles(whole, part);
	}else if(c2 == 6){
		return new Yen(whole, part);
	}else if(c2 == 7){
		return new Franc(whole, part);
	}else if(c2 == 8){
		return new Colon(whole, part);
	}else if(c2 == 9){
		return new Rupee(whole, part);
	}else if(c2 == 10){
		return new Shekel(whole, part);
	}
}
//get the Enum for money
MonType getType(int c2){
	if(c2 == 1){
		return DOLLAR;
	}else if(c2 == 2){
		return POUNDS;
	}else if(c2 == 3){
		return EUROS;
	}else if(c2 == 4){
		return PESOS;
	}else if(c2 == 5){
		return RUBLES;
	}else if(c2 == 6){
		return YEN;
	}else if(c2 == 7){
		return FRANC;
	}else if(c2 == 8){
		return COLON;
	}else if(c2 == 9){
		return RUPEE;
	}else if(c2 == 10){
		return SHEKEL;
	}
}

int main(){
	int c1 = 0, c2 = 0;
	Wallet wallie;
	do{
		cout << endl;
		cout << "Welcome to your Wallet! (Wallie)" << endl;
		cout << "1. Add Random Ammounts of Money" << endl;
		cout << "2. Sub Random Ammounts of Money" << endl;
		cout << "3. Fully Remove One Type of Money" << endl;
		cout << "4. Display Contents of Wallet" << endl;
		cout << "5. Empty Wallet" << endl;
		cout << "6. Quit" << endl;
		cin >> c1;
		cout << endl;
		if(c1 >= 1 && c1 <= 3){
			cout << "Select Currency Type" << endl;
			cout << "1. Dollar" << endl;
			cout << "2. Pounds" << endl;
			cout << "3. Euros" << endl;
			cout << "4. Pesos" << endl;
			cout << "5. Rubles" << endl;
			cout << "6. Yen" << endl;
			cout << "7. Franc" << endl;
			cout << "8. Colon" << endl;
			cout << "9. Rupee" << endl;
			cout << "10. Shekel" << endl;
			cin >> c2;
			cout << endl;
		}
		if(c1 == 1 && c2 >= 1 && c2 <= 10){
			Currency* temp = getMoney(c2);
			//display how much is being added
			cout << "Adding ";
			temp->toString();
			cout << " to Wallie" << endl;
			//will always add so dont need to check
			wallie.addCurrency(getType(c2), temp);
		}else if(c1 == 2 && c2 >= 1 && c2 <= 10){
			Currency* temp = getMoney(c2);
			cout << "Attempting to remove ";
			temp->toString();
			cout << "from Wallie" << endl;
			if(!wallie.subCurrency(getType(c2), temp)){
				cout << "There is no money of type that type cannot subtract!" << endl;
			} else {
				cout << "Succesfully Removed" << endl;
			}
		}
		else if(c1 == 3 && c2 >= 1 && c2 <= 10){
			//if the object being removed exists
			if(wallie.exists(getType(c2))){
				Currency* temp = wallie.getCurrency(getType(c2));
				cout << "Removing ";
				temp->toString();
				cout << endl;
				wallie.removeCurrency(getType(c2));
			}else{
				cout << "Currency of that Type does not Exist!" << endl;
			}
		}
		else if(c1 == 4){
			//can only display if wallet is not empty
			if(!wallie.isEmpty()){
				wallie.displayAll();
			}else{
				cout << "Wallie is Empty!!!" << endl;
			}
		}
		else if(c1 == 5){
			wallie.removeAll();
			cout << "All Types of Currency Removed" << endl;
		}else if(c1 == 6){
			//destructor handles the mem
			cout << "Bye Bye Wallie" << endl;
		}else{
			//if user selects an invalid option
			cin.clear();
			cin.ignore();
			cout << "Not a Valid Input" << endl;
		}
	}while(c1 != 6);
	return 0;
}