#ifndef PLAN_HPP
#define PLAN_HPP

#include <vector>

#include "Medicine.hpp"

class Plan
{
private:
	std::string name, length, type;
	std::vector<Medicine*> meds;
public:
	Plan();
	Plan(std::string name);
	Plan(std::string name, std::string length, std::string type) : name(name), length(length), type(type) {}
	Plan(std::string name, std::vector<Medicine*>& meds) : name(name), meds(meds) {}

	void addMed(Medicine* med);
	void setName(std::string name);
	void setLength(std::string length);
	void setType(std::string type);
	std::string getName() const;
	std::string getLength() const;
	std::string getType() const;
	std::vector<Medicine*> getMeds() const;
};

#endif // !PLAN_HPP
