#ifndef PLAN_HPP
#define PLAN_HPP

#include <vector>

#include "Medicine.hpp"

class Plan
{
private:
	std::string name;
	std::vector<Medicine> meds;
public:
	Plan();
	Plan(std::string name);
	Plan(std::string name, std::vector<Medicine>& meds) : name(name), meds(meds) {}
	std::string getName() const;
	std::vector<Medicine> getMeds() const;
};

#endif // !PLAN_HPP
