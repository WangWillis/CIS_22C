#ifndef WALLET_H
#define WALLET_H

#include "Currency.h"
#include "Money.h"

class Wallet;

enum MonType {DOLLAR, POUNDS, EUROS, PESOS, RUBLES, YEN, FRANC, COLON, RUPEE, SHEKEL};
static const std::string MoneyNames[] = {"Dollar", "Pound", "Euro", "Peso", "Ruble", "Yen", "Franc", "Colon", "Rupee", "Shekel"};

class Wallet{
	private:
		//want it to store pointers
		Currency** storage;
		//counts the different types of money in the array and allows for O(1) run time instead of O(n) for isEmpty() fucntion
		int numEle;
	public:
		Wallet();
		~Wallet();
		//adds n amount of type m to wallet
		bool addCurrency(MonType, Currency*);
		//removes n amount of type m from wallet
		bool subCurrency(MonType, Currency*);
		//removes all of type m from wallet
		bool removeCurrency(MonType);
		//checks to see if certain currency exist
		bool exists(MonType);
		//checks if wallet is empty
		bool isEmpty();
		//for when need to get the certain currency object
		Currency* getCurrency(MonType);
		//removes all money from wallet
		void removeAll();
		void displayAll();
};
#endif