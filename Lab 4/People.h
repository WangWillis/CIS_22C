#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>

class People;

class People{
	private:
		std::string name, birthday;
	public:
		People();
		People(const std::string, const std::string);
		std::string getName() const;
		std::string getBirthday() const;
		void setName(const std::string);
		void setBirthday(const std::string);
		bool operator==(const People&) const;
		bool operator!=(const People&) const;
		friend bool operator<(const People& lhs, const People& rhs){
			return lhs.getName() < rhs.getName();
		}
};

#endif