#ifndef USERDAO_HPP
#define USERDAO_HPP

#include <vector>

class UserDAO
{
private:
	static UserDAO* instance;
	static unsigned int nextUserId;
	std::vector<unsigned int> usedIds;
	UserDAO() {}

public:
	static UserDAO* getInstance();

	/*
	* che sia ben chiaro, sta classe � un semplice
	* placeholder. poi avr� l'implementazione effettiva
	* via un vero database da gestire.
	*/
	unsigned int getNextUserId();
};

#endif // !USERDAO_HPP
