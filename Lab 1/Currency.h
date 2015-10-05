//Interface class
#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>

using namespace std;

class Currency;

class Currency{
	public:
		virtual int getWhole() = 0;
		virtual int getParts() = 0;
		//to check in add and sub functions if right type
		virtual string getWholeName() = 0;
		virtual void toString() = 0;
		virtual bool add(Currency*) = 0;
		virtual bool sub(Currency*) = 0;
};
#endif