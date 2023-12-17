#ifndef USER_HPP
#define USER

#include <string>
#include <chrono>

class User
{
private:
	unsigned const int id;
	std::string name, surname, email, hashedPassword;
	std::chrono::system_clock::time_point registrationTime, birthDate;

public:
};

class Patient : public User
{
private:

};
#endif // !USER_HPP
