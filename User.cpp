#include "User.hpp"

void User::Update()
{
    this->lastAccess = std::chrono::system_clock::now();
}

const std::string& User::getHashedPassword() const
{
    return hashedPassword;
}

void User::addPlan(Plan& plan)
{
    plans.push_back(plan);
}

const std::string& User::getEmail() const
{
    return email;
}

const std::string User::getFullName() const
{
    return (name + " " + surname);
}

std::vector<Plan> User::getPlans()
{
    return plans;
}
