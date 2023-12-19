#ifndef USERDAO_HPP
#define USERDAO_HPP

#include <vector>
#include "bcrypt.h"

class User; //foward declaration, per evitare che ci sia un'inclusione ciclica.

class UserDAO
{
private:
	User* testUser = nullptr;
	static UserDAO* instance;
	static unsigned int nextUserId;
	std::vector<unsigned int> usedIds;
	UserDAO() {}

public:
	static UserDAO* getInstance();

	/*
	* che sia ben chiaro, sta classe è un semplice
	* placeholder. poi avrà l'implementazione effettiva
	* via un vero database da gestire.
	*/
	unsigned int getNextUserId();

	bool authUser(const std::string& email, const std::string& password);
};

#endif // !USERDAO_HPP
