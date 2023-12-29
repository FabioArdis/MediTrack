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
	User* getUser();

	static UserDAO* getInstance();

	unsigned int getNextUserId();

	bool authUser(const std::string& email, const std::string& password);
};

#endif // !USERDAO_HPP
