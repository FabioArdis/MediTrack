#include <stdexcept>

#include "Medicine.hpp"

Medicine::Medicine()
{
	id = IDs++;
	name = "Medicine" + std::to_string(id);
	dosage = "Insert dosage...";
	manufacturer = "Insert manufacturer...";
	batchNo = "Insert batch number...";
	expirationTime = "Insert expiration time...";
}

Medicine::Medicine(std::string name) : name(name)
{
	id = IDs++;
	dosage = "Insert dosage...";
	manufacturer = "Insert manufacturer...";
	batchNo = "Insert batch number...";
	expirationTime = "Insert expiration time...";
}

std::vector<std::string> Medicine::getInfo() const
{
	std::vector<std::string> info;

	info.push_back(name);
	info.push_back(dosage);
	info.push_back(manufacturer);
	info.push_back(batchNo);
	info.push_back(expirationTime);

	return info;
}

std::string Medicine::getInfo(std::string info) const
{
	if (info == "name")
		return name;
	else if (info == "dosage")
		return dosage;
	else if (info == "manufacturer")
		return manufacturer;
	else if (info == "batchNo")
		return batchNo;
	else if (info == "expirationTime")
		return expirationTime;

	throw std::invalid_argument("Invalid argument: " + info);
}