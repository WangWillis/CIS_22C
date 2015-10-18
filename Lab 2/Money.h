#ifndef MONEY_H
#define MONEY_H

#include "Currency.h"

class Dollar;
class Pounds;
class Euros;
class Pesos;
class Rubles;
class Yen;
class Franc;
class Colon;
class Rupee;
class Shekel;

class Dollar : public Currency{
	private:
		//dont want a default constructor to be used
		Dollar();
		//dont want default constructor used
		string wholeName, partsName;
		int whole, parts;
		//if parts is not a good number
		void makeGood();
	public:
		Dollar(int, int);
		int getWhole();
		int getParts();
		//to check in add and sub functions if right type
		string getWholeName();
		void toString();
		bool add(Currency*);
		bool sub(Currency*);
};
class Pounds : public Currency{
	private:
		//dont want a default constructor to be used
		Pounds();
		//dont want default constructor used
		string wholeName, partsName;
		int whole, parts;
		//if parts is not a good number
		void makeGood();
	public:
		Pounds(int, int);
		int getWhole();
		int getParts();
		//to check in add and sub functions if right type
		string getWholeName();
		void toString();
		bool add(Currency*);
		bool sub(Currency*);
};
class Euros : public Currency{
	private:
		//dont want a default constructor to be used
		Euros();
		string wholeName, partsName;
		int whole, parts;
		//if parts is not a good number
		void makeGood();
	public:
		Euros(int, int);
		int getWhole();
		int getParts();
		//to check in add and sub functions if right type
		string getWholeName();
		void toString();
		bool add(Currency*);
		bool sub(Currency*);
};
class Pesos : public Currency{
	private:
		//dont want a default constructor to be used
		Pesos();
		string wholeName, partsName;
		int whole, parts;
		//if parts is not a good number
		void makeGood();
	public:
		Pesos(int, int);
		int getWhole();
		int getParts();
		//to check in add and sub functions if right type
		string getWholeName();
		void toString();
		bool add(Currency*);
		bool sub(Currency*);
};
class Rubles : public Currency{
	private:
		//dont want a default constructor to be used
		Rubles();
		string wholeName, partsName;
		int whole, parts;
		//if parts is not a good number
		void makeGood();
	public:
		Rubles(int, int);
		int getWhole();
		int getParts();
		//to check in add and sub functions if right type
		string getWholeName();
		void toString();
		bool add(Currency*);
		bool sub(Currency*);
};
class Yen : public Currency{
	private:
		//dont want a default constructor to be used
		Yen();
		string wholeName, partsName;
		int whole, parts;
		//if parts is not a good number
		void makeGood();
	public:
		Yen(int, int);
		int getWhole();
		int getParts();
		//to check in add and sub functions if right type
		string getWholeName();
		void toString();
		bool add(Currency*);
		bool sub(Currency*);
};
class Franc : public Currency{
	private:
		//dont want a default constructor to be used
		Franc();
		string wholeName, partsName;
		int whole, parts;
		//if parts is not a good number
		void makeGood();
	public:
		Franc(int, int);
		int getWhole();
		int getParts();
		//to check in add and sub functions if right type
		string getWholeName();
		void toString();
		bool add(Currency*);
		bool sub(Currency*);
};
class Colon : public Currency{
	private:
		//dont want a default constructor to be used
		Colon();
		string wholeName, partsName;
		int whole, parts;
		//if parts is not a good number
		void makeGood();
	public:
		Colon(int, int);
		int getWhole();
		int getParts();
		//to check in add and sub functions if right type
		string getWholeName();
		void toString();
		bool add(Currency*);
		bool sub(Currency*);
};
class Rupee : public Currency{
	private:
		//dont want a default constructor to be used
		Rupee();
		string wholeName, partsName;
		int whole, parts;
		//if parts is not a good number
		void makeGood();
	public:
		Rupee(int, int);
		int getWhole();
		int getParts();
		//to check in add and sub functions if right type
		string getWholeName();
		void toString();
		bool add(Currency*);
		bool sub(Currency*);
};
class Shekel : public Currency{
	private:
		//dont want a default constructor to be used
		Shekel();
		string wholeName, partsName;
		int whole, parts;
		//if parts is not a good number
		void makeGood();
	public:
		Shekel(int, int);
		int getWhole();
		int getParts();
		//to check in add and sub functions if right type
		string getWholeName();
		void toString();
		bool add(Currency*);
		bool sub(Currency*);
};
#endif