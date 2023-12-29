#include "UserDAO.hpp"
#include "User.hpp"

UserDAO* UserDAO::instance = nullptr;

unsigned int UserDAO::nextUserId = 1;

User* UserDAO::getUser()
{
	if (this->testUser == nullptr)
		testUser = new User("TestName", "TestSurname", "a", "$2a$10$tyGozBhl7eajm5QwP4K9XeDosk8ROWKM1iHsN1ZuwRhlld6Ko7fiq", "2002-11-15");
	
	return testUser;
}

UserDAO* UserDAO::getInstance()
{
	if (instance == nullptr)
		instance = new UserDAO();

	return instance;
}

unsigned int UserDAO::getNextUserId()
{
	unsigned int newId = nextUserId++;

	usedIds.push_back(newId);

	return newId;
}

bool UserDAO::authUser(const std::string& email, const std::string& password)
{
	if (this->testUser == nullptr)
		testUser = new User("TestName", "TestSurname", "a", "$2a$10$tyGozBhl7eajm5QwP4K9XeDosk8ROWKM1iHsN1ZuwRhlld6Ko7fiq", "2002-11-15");

	if (email == this->testUser->getEmail() && bcrypt::validatePassword(password, testUser->getHashedPassword()))
	{
		this->testUser->Update();
		return true;
	}

	return false;
}