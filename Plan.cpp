#include "Plan.hpp"

Plan::Plan()
{
	name = "PlanName";
	length = "PlanLength";
	type = "PlanType";
	if (meds.empty())
	{
		Medicine* testMedicine = new Medicine();
		meds.push_back(testMedicine);
	}
}

Plan::Plan(std::string name)
{
	this->name = name;
	length = "PlanLength";
	type = "PlanType";
}

void Plan::addMed(Medicine* med)
{
	meds.push_back(med);
}

void Plan::setName(std::string name)
{
	this->name = name;
}

void Plan::setLength(std::string length)
{
	this->length = length;
}

void Plan::setType(std::string type)
{
	this->type = type;
}

std::string Plan::getName() const
{
	return name;
}

std::string Plan::getLength() const
{
	return length;
}

std::string Plan::getType() const
{
	return type;
}

std::vector<Medicine*> Plan::getMeds() const
{
	return meds;
}