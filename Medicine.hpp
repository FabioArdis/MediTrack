#ifndef MEDICINE_HPP
#define MEDICINE_HPP

#include <vector>
#include <string>
#include <chrono>

enum class MedInfo
{
	NAME,
	DSGE,
	MNFC,
	BTNO,
	EXPT,
	NOTE
};

unsigned static IDs = 0;

class Medicine
{
private:
	unsigned int id;
	std::string name, dosage, manufacturer,
		batchNo, expirationTime, notes;

public:
	Medicine();
	Medicine(std::string name);

	void setInfo(std::vector<std::string> data);
	void setInfo(MedInfo info, std::string data);

	std::vector<std::string> getInfo() const;
	std::string getInfo(MedInfo info) const;

};
#endif // !MEDICINE_HPP
