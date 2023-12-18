#include "UserDAO.hpp"

UserDAO* UserDAO::instance = nullptr;
unsigned int UserDAO::nextUserId = 1;

UserDAO* UserDAO::getInstance()
{
	if (!instance)
		instance = new UserDAO();
	return instance;
}

unsigned int UserDAO::getNextUserId()
{
	unsigned int newId = nextUserId++;
	usedIds.push_back(newId);
	return newId;
}
