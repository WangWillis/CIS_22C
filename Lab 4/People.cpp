#include "People.h"

People::People(){
	name = "";
	birthday = "";
}

People::People(const std::string nam, const std::string birth){
	name = nam;
	birthday = birth;
}

std::string People::getName() const{
	return name;
}

std::string People::getBirthday() const{
	return birthday;
}

void People::setName(const std::string nam){
	name = nam;
}

void People::setBirthday(const std::string birth){
	birthday = birth;
}

bool People::operator==(const People& rhs) const{
	return name == rhs.getName() || birthday == rhs.getBirthday();
}

bool People::operator!=(const People& rhs) const{
	return name != rhs.getName() || birthday != rhs.getBirthday();
}