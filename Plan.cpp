#include "Plan.hpp"

std::string Plan::getName() const
{
	return name;
}

std::vector<Medicine> Plan::getMeds() const
{
	return meds;
}