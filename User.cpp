#include "User.hpp"

void User::Update()
{
    this->lastAccess = std::chrono::system_clock::now();
}

const std::string& User::getHashedPassword() const
{
    return hashedPassword;
}

const std::string& User::getEmail() const
{
    return email;
}