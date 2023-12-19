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
	std::string getName() const;
	std::vector<Medicine> getMeds() const;
};

#endif // !PLAN_HPP
