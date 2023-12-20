#ifndef USER_HPP
#define USER

#include <string>
#include <chrono>
#include "UserDAO.hpp"
#include "Plan.hpp"

class User
{
private:
	unsigned const int id;
	std::string name, surname, email, hashedPassword, birthDate;
	std::chrono::system_clock::time_point registrationTime, lastAccess;
	std::vector<Plan> plans;

public:
	User(const std::string& name, const std::string& surname, const std::string& email, const std::string& hashedPassword, const std::string& birthDate)
		: id(UserDAO::getInstance()->getNextUserId()), name(name), surname(surname), email(email), hashedPassword(hashedPassword), birthDate(birthDate)
	{
		this->registrationTime = std::chrono::system_clock::now();
		this->lastAccess = std::chrono::system_clock::now();
	}

	void Update();
	void addPlan(Plan& plan);

	const std::string& getHashedPassword() const;
	const std::string& getEmail() const;
	const std::string getFullName() const;
	const std::vector<Plan> getPlans() const;
};
#endif // !USER_HPP
