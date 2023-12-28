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
	notes = "Insert notes....";
}

Medicine::Medicine(std::string name) : name(name)
{
	id = IDs++;
	dosage = "Insert dosage...";
	manufacturer = "Insert manufacturer...";
	batchNo = "Insert batch number...";
	expirationTime = "Insert expiration time...";
	notes = "Insert notes....";
}

void Medicine::setInfo(std::vector<std::string> data)
{
	/*
	* a sto punto ha più senso usare un costruttore di copia, no?
	*/
}

void Medicine::setInfo(MedInfo info, std::string data)
{
	switch (info)
	{
	case MedInfo::NAME:
		name = data;
		break;
	case MedInfo::DSGE:
		dosage = data;
		break;
	case MedInfo::MNFC:
		manufacturer = data;
		break;
	case MedInfo::BTNO:
		batchNo = data;
		break;
	case MedInfo::EXPT:
		expirationTime = data;
		break;
	case MedInfo::NOTE:
		notes = data;
		break;
	default:
		throw std::invalid_argument("Invalid argument");
	}
}

std::vector<std::string> Medicine::getInfo() const
{
	std::vector<std::string> info;

	info.push_back(name);
	info.push_back(dosage);
	info.push_back(manufacturer);
	info.push_back(batchNo);
	info.push_back(expirationTime);
	info.push_back(notes);

	return info;
}

std::string Medicine::getInfo(MedInfo info) const
{
	switch (info)
	{
	case MedInfo::NAME:
		return name;
		break;
	case MedInfo::DSGE:
		return dosage;
		break;
	case MedInfo::MNFC:
		return manufacturer;
		break;
	case MedInfo::BTNO:
		return batchNo;
		break;
	case MedInfo::EXPT:
		return expirationTime;
		break;
	case MedInfo::NOTE:
		return notes;
		break;
	default:
		throw std::invalid_argument("Invalid argument");
	}
}