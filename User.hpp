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
	std::chrono::system_clock::time_point registrationTime;

public:
	User(const std::string& name, const std::string& surname, const std::string& email, const std::string& hashedPassword, const std::string& birthDate)
		: id(UserDAO::getInstance()->getNextUserId()), name(name), surname(surname), email(email), hashedPassword(hashedPassword), birthDate(birthDate)
	{
		registrationTime = std::chrono::system_clock::now();
	}
};

class Patient : public User
{
private:

};
#endif // !USER_HPP
