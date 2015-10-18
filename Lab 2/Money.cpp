#include <iostream>
#include "Money.h"

Dollar::Dollar(int whol, int par){
	//setting the values right
	whole = whol;
	parts = par;
	wholeName = "Dollar";
	partsName = "Cent";
	makeGood();
}
void Dollar::makeGood(){
	//if parts is negative
	if(parts < 0){
		//int div and the -1 to account for negative
		whole += (parts/100 - 1);
		//gives parts a value between 0 and 100
		parts = 100 + (parts%100);
	}else{
		//int div
		whole += (parts/100);
		//gives parts its value between 0 and 100
		parts = parts%100;
	}
	//if whole goes negative means no more of type of money
	if(whole < 0){
		whole = 0;
		parts = 0;
	}
}
bool Dollar::add(Currency* mon){
	if(mon->getWholeName() == wholeName){
		//add each part to eachother
		whole += mon->getWhole();
		parts += mon->getParts();
		//this is why can add like above
		makeGood();
		return true;
	}
	return false;
}
bool Dollar::sub(Currency* mon){
	//if the currrencies are the same
	if(mon->getWholeName() == wholeName){
		//normal subtraction
		whole -= mon->getWhole();
		parts -= mon->getParts();
		//this is why can subtract like above to
		makeGood();
		return true;
	}
	return false;
}
int Dollar::getWhole(){
	return this->whole;
}
int Dollar::getParts(){
	return this->parts;
}
string Dollar::getWholeName(){
	return this->wholeName;
}
void Dollar::toString(){
	cout << whole << " " << wholeName << " and " << parts << " " << partsName << endl;
}
//all other code is the same a Dollar just different object name
Pounds::Pounds(int whol, int par){
	whole = whol;
	parts = par;
	wholeName = "Pound";
	partsName = "Pence";
	makeGood();
}
void Pounds::makeGood(){
	//if parts is negative
	if(parts < 0){
		//int div and the -1 to account for negative
		whole += (parts/100 - 1);
		//gives parts a value between 0 and 100
		parts = 100 + (parts%100);
	}else{
		//int div
		whole += (parts/100);
		//gives parts its value between 0 and 100
		parts = parts%100;
	}
	if(whole < 0){
		whole = 0;
		parts = 0;
	}
}
bool Pounds::add(Currency* mon){
	if(mon->getWholeName() == wholeName){
		whole += mon->getWhole();
		parts += mon->getParts();
		makeGood();
		return true;
	}
	return false;
}
bool Pounds::sub(Currency* mon){
	if(mon->getWholeName() == wholeName){
		whole -= mon->getWhole();
		parts -= mon->getParts();
		makeGood();
		return true;
	}
	return false;
}
int Pounds::getWhole(){
	return this->whole;
}
int Pounds::getParts(){
	return this->parts;
}
string Pounds::getWholeName(){
	return this->wholeName;
}
void Pounds::toString(){
	cout << whole << " " << wholeName << " and " << parts << " " << partsName << endl;
}

Euros::Euros(int whol, int par){
	whole = whol;
	parts = par;
	wholeName = "Euro";
	partsName = "Cent";
	makeGood();
}
void Euros::makeGood(){
	//if parts is negative
	if(parts < 0){
		//int div and the -1 to account for negative
		whole += (parts/100 - 1);
		//gives parts a value between 0 and 100
		parts = 100 + (parts%100);
	}else{
		//int div
		whole += (parts/100);
		//gives parts its value between 0 and 100
		parts = parts%100;
	}
	if(whole < 0){
		whole = 0;
		parts = 0;
	}
}
bool Euros::add(Currency* mon){
	if(mon->getWholeName() == wholeName){
		whole += mon->getWhole();
		parts += mon->getParts();
		makeGood();
		return true;
	}
	return false;
}
bool Euros::sub(Currency* mon){
	if(mon->getWholeName() == wholeName){
		whole -= mon->getWhole();
		parts -= mon->getParts();
		makeGood();
		return true;
	}
	return false;
}
int Euros::getWhole(){
	return this->whole;
}
int Euros::getParts(){
	return this->parts;
}
string Euros::getWholeName(){
	return this->wholeName;
}
void Euros::toString(){
	cout << whole << " " << wholeName << " and " << parts << " " << partsName << endl;
}

Pesos::Pesos(int whol, int par){
	whole = whol;
	parts = par;
	wholeName = "Peso";
	partsName = "Centavo";
	makeGood();
}
void Pesos::makeGood(){
	//if parts is negative
	if(parts < 0){
		//int div and the -1 to account for negative
		whole += (parts/100 - 1);
		//gives parts a value between 0 and 100
		parts = 100 + (parts%100);
	}else{
		//int div
		whole += (parts/100);
		//gives parts its value between 0 and 100
		parts = parts%100;
	}
	if(whole < 0){
		whole = 0;
		parts = 0;
	}
}
bool Pesos::add(Currency* mon){
	if(mon->getWholeName() == wholeName){
		whole += mon->getWhole();
		parts += mon->getParts();
		makeGood();
		return true;
	}
	return false;
}
bool Pesos::sub(Currency* mon){
	if(mon->getWholeName() == wholeName){
		whole -= mon->getWhole();
		parts -= mon->getParts();
		makeGood();
		return true;
	}
	return false;
}
int Pesos::getWhole(){
	return this->whole;
}
int Pesos::getParts(){
	return this->parts;
}
string Pesos::getWholeName(){
	return this->wholeName;
}
void Pesos::toString(){
	cout << whole << " " << wholeName << " and " << parts << " " << partsName << endl;
}

Rubles::Rubles(int whol, int par){
	whole = whol;
	parts = par;
	wholeName = "Ruble";
	partsName = "Kopek";
	makeGood();
}
void Rubles::makeGood(){
	//if parts is negative
	if(parts < 0){
		//int div and the -1 to account for negative
		whole += (parts/100 - 1);
		//gives parts a value between 0 and 100
		parts = 100 + (parts%100);
	}else{
		//int div
		whole += (parts/100);
		//gives parts its value between 0 and 100
		parts = parts%100;
	}
	if(whole < 0){
		whole = 0;
		parts = 0;
	}
}
bool Rubles::add(Currency* mon){
	if(mon->getWholeName() == wholeName){
		whole += mon->getWhole();
		parts += mon->getParts();
		makeGood();
		return true;
	}
	return false;
}
bool Rubles::sub(Currency* mon){
	if(mon->getWholeName() == wholeName){
		whole -= mon->getWhole();
		parts -= mon->getParts();
		makeGood();
		return true;
	}
	return false;
}
int Rubles::getWhole(){
	return this->whole;
}
int Rubles::getParts(){
	return this->parts;
}
string Rubles::getWholeName(){
	return this->wholeName;
}
void Rubles::toString(){
	cout << whole << " " << wholeName << " and " << parts << " " << partsName << endl;
}

Yen::Yen(int whol, int par){
	whole = whol;
	parts = par;
	wholeName = "Yen";
	partsName = "Cen";
	makeGood();
}
void Yen::makeGood(){
	//if parts is negative
	if(parts < 0){
		//int div and the -1 to account for negative
		whole += (parts/100 - 1);
		//gives parts a value between 0 and 100
		parts = 100 + (parts%100);
	}else{
		//int div
		whole += (parts/100);
		//gives parts its value between 0 and 100
		parts = parts%100;
	}
	if(whole < 0){
		whole = 0;
		parts = 0;
	}
}
bool Yen::add(Currency* mon){
	if(mon->getWholeName() == wholeName){
		whole += mon->getWhole();
		parts += mon->getParts();
		makeGood();
		return true;
	}
	return false;
}
bool Yen::sub(Currency* mon){
	if(mon->getWholeName() == wholeName){
		whole -= mon->getWhole();
		parts -= mon->getParts();
		makeGood();
		return true;
	}
	return false;
}
int Yen::getWhole(){
	return this->whole;
}
int Yen::getParts(){
	return this->parts;
}
string Yen::getWholeName(){
	return this->wholeName;
}
void Yen::toString(){
	cout << whole << " " << wholeName << " and " << parts << " " << partsName << endl;
}

Franc::Franc(int whol, int par){
	whole = whol;
	parts = par;
	wholeName = "Franc";
	partsName = "Centime";
	makeGood();
}
void Franc::makeGood(){
	//if parts is negative
	if(parts < 0){
		//int div and the -1 to account for negative
		whole += (parts/100 - 1);
		//gives parts a value between 0 and 100
		parts = 100 + (parts%100);
	}else{
		//int div
		whole += (parts/100);
		//gives parts its value between 0 and 100
		parts = parts%100;
	}
	if(whole < 0){
		whole = 0;
		parts = 0;
	}
}
bool Franc::add(Currency* mon){
	if(mon->getWholeName() == wholeName){
		whole += mon->getWhole();
		parts += mon->getParts();
		makeGood();
		return true;
	}
	return false;
}
bool Franc::sub(Currency* mon){
	if(mon->getWholeName() == wholeName){
		whole -= mon->getWhole();
		parts -= mon->getParts();
		makeGood();		return true;
	}
	return false;
}
int Franc::getWhole(){
	return this->whole;
}
int Franc::getParts(){
	return this->parts;
}
string Franc::getWholeName(){
	return this->wholeName;
}
void Franc::toString(){
	cout << whole << " " << wholeName << " and " << parts << " " << partsName << endl;
}

Colon::Colon(int whol, int par){
	whole = whol;
	parts = par;
	wholeName = "Colon";
	partsName = "Centmo";
	makeGood();
}
void Colon::makeGood(){
	//if parts is negative
	if(parts < 0){
		//int div and the -1 to account for negative
		whole += (parts/100 - 1);
		//gives parts a value between 0 and 100
		parts = 100 + (parts%100);
	}else{
		//int div
		whole += (parts/100);
		//gives parts its value between 0 and 100
		parts = parts%100;
	}
	if(whole < 0){
		whole = 0;
		parts = 0;
	}
}
bool Colon::add(Currency* mon){
	if(mon->getWholeName() == wholeName){
		whole += mon->getWhole();
		parts += mon->getParts();
		makeGood();
		return true;
	}
	return false;
}
bool Colon::sub(Currency* mon){
	if(mon->getWholeName() == wholeName){
		whole -= mon->getWhole();
		parts -= mon->getParts();
		makeGood();
		return true;
	}
	return false;
}
int Colon::getWhole(){
	return this->whole;
}
int Colon::getParts(){
	return this->parts;
}
string Colon::getWholeName(){
	return this->wholeName;
}
void Colon::toString(){
	cout << whole << " " << wholeName << " and " << parts << " " << partsName << endl;
}

Rupee::Rupee(int whol, int par){
	whole = whol;
	parts = par;
	wholeName = "Rupee";
	partsName = "Paise";
	makeGood();
}
void Rupee::makeGood(){
	//if parts is negative
	if(parts < 0){
		//int div and the -1 to account for negative
		whole += (parts/100 - 1);
		//gives parts a value between 0 and 100
		parts = 100 + (parts%100);
	}else{
		//int div
		whole += (parts/100);
		//gives parts its value between 0 and 100
		parts = parts%100;
	}
	if(whole < 0){
		whole = 0;
		parts = 0;
	}
}
bool Rupee::add(Currency* mon){
	if(mon->getWholeName() == wholeName){
		whole += mon->getWhole();
		parts += mon->getParts();
		makeGood();
		return true;
	}
	return false;
}
bool Rupee::sub(Currency* mon){
	if(mon->getWholeName() == wholeName){
		whole -= mon->getWhole();
		parts -= mon->getParts();
		makeGood();
		return true;
	}
	return false;
}
int Rupee::getWhole(){
	return this->whole;
}
int Rupee::getParts(){
	return this->parts;
}
string Rupee::getWholeName(){
	return this->wholeName;
}
void Rupee::toString(){
	cout << whole << " " << wholeName << " and " << parts << " " << partsName << endl;
}

Shekel::Shekel(int whol, int par){
	whole = whol;
	parts = par;
	wholeName = "Shekel";
	partsName = "Agorot";
	makeGood();
}
void Shekel::makeGood(){
	//if parts is negative
	if(parts < 0){
		//int div and the -1 to account for negative
		whole += (parts/100 - 1);
		//gives parts a value between 0 and 100
		parts = 100 + (parts%100);
	}else{
		//int div
		whole += (parts/100);
		//gives parts its value between 0 and 100
		parts = parts%100;
	}
	if(whole < 0){
		whole = 0;
		parts = 0;
	}
}
bool Shekel::add(Currency* mon){
	if(mon->getWholeName() == wholeName){
		whole += mon->getWhole();
		parts += mon->getParts();
		makeGood();
		return true;
	}
	return false;
}
bool Shekel::sub(Currency* mon){
	if(mon->getWholeName() == wholeName){
		whole -= mon->getWhole();
		parts -= mon->getParts();
		makeGood();
		return true;
	}
	return false;
}
int Shekel::getWhole(){
	return this->whole;
}
int Shekel::getParts(){
	return this->parts;
}
string Shekel::getWholeName(){
	return this->wholeName;
}
void Shekel::toString(){
	cout << whole << " " << wholeName << " and " << parts << " " << partsName << endl;
}