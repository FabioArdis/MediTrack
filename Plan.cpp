#include "Plan.hpp"

Plan::Plan()
{
	name = "PlanName";
	Medicine prova;
	meds.push_back(prova);
}

Plan::Plan(std::string name)
{
	this->name = name;
	Medicine prova;
	meds.push_back(prova);
}

std::string Plan::getName() const
{
	return name;
}

std::vector<Medicine> Plan::getMeds() const
{
	return meds;
}