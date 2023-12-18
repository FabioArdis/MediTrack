#ifndef USER_HPP
#define USER

#include <string>
#include <chrono>
#include "UserDAO.hpp"

class User
{
private:
	unsigned const int id;
	std::string name, surname, email, hashedPassword, birthDate;
	std::chrono::system_clock::time_point registrationTime, lastAccess;

public:
	User(const std::string& name, const std::string& surname, const std::string& email, const std::string& hashedPassword, const std::string& birthDate)
		: id(UserDAO::getInstance()->getNextUserId()), name(name), surname(surname), email(email), hashedPassword(hashedPassword), birthDate(birthDate)
	{
		this->registrationTime = std::chrono::system_clock::now();
		this->lastAccess = std::chrono::system_clock::now();
	}

	void Update();

	const std::string& getHashedPassword() const;
	const std::string& getEmail() const;
};
#endif // !USER_HPP
