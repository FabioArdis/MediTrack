#include "Plan.hpp"

Plan::Plan()
{
	name = "PlanName";
	if (meds.empty())
	{
		Medicine testMedicine;
		meds.push_back(testMedicine);
	}
}

Plan::Plan(std::string name)
{
	this->name = name;
}

void Plan::addMed(Medicine& med)
{
	meds.push_back(med);
}

void Plan::setName(std::string name)
{
	this->name = name;
}

std::string Plan::getName() const
{
	return name;
}

std::vector<Medicine> Plan::getMeds() const
{
	return meds;
}