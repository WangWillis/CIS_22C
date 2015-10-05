#include "Wallet.h"

Wallet::Wallet(){
	//10 different types of money
	storage = new Currency* [10];
	numEle = 0;
	//need to make sure does not point to random place
	for(int i = 0; i < 10; i++){
		storage[i] = NULL;
	}
}
Wallet::~Wallet(){
	//frees up storage
	removeAll();
	delete [] storage;
}
void Wallet::removeAll(){
	numEle = 0;
	//set all pointers in storage as NULL
	for(int i = 0; i < 10; i++){
		delete storage[i];
		storage[i] = NULL;
	}
}
bool Wallet::addCurrency(MonType type, Currency* mon){
	//store money object in the same place as its enum place
	int temp = static_cast<int>(type);
	if(MoneyNames[temp] == mon->getWholeName()){
		if(storage[temp] == NULL){
			numEle++;
			storage[temp] = mon;
			return true;
		} else {
			if(!storage[temp]->add(mon)){
				//free up the dynamically allocated mon since dont need it anymore
				delete mon;
				return false;
			}
			//free up the dynamically allocated mon since dont need it anymore
			delete mon;
			return true;
		}
	}
	delete mon;
	return false;
}
//subtracts currency returns null when fails
bool Wallet::subCurrency(MonType type, Currency* mon){
	int temp = static_cast<int>(type);
	if(storage[temp] != NULL){
		if(!storage[temp]->sub(mon)){
			//free up the dynamically allocated mon since dont need it anymore
			delete mon;
			return false;
		};
		//free up the dynamically allocated mon since dont need it anymore
		delete mon;
		return true;
	}
	//free up the dynamically allocated mon since dont need it anymore
	delete mon;
	return false;
}
//removes one type of currency fully aka set one type to null
bool Wallet::removeCurrency(MonType type){
	int temp = static_cast<int>(type);
	if(numEle > 0 && storage[temp] != NULL){
		delete storage[temp];
		storage[temp] = NULL;
		numEle--;
		return true;
	}
	return false;
}
//checks if a certain type of currency exists
bool Wallet::exists(MonType type){
	int temp = static_cast<int>(type);
	if(storage[temp] != NULL){
		return true;
	}
	return false;
}
//checks if the wallet is empty
bool Wallet::isEmpty(){
	if(numEle == 0){
		return true;
	}
	return false;
}
//returns a currency of type m
Currency* Wallet::getCurrency(MonType type){
	int temp = static_cast<int>(type);
	return storage[temp];
}
//displays all the non null money values
void Wallet::displayAll(){
	for(int i = 0; i < 10; i++){
		if(storage[i] != NULL){
			storage[i]->toString();
		}
	}
}