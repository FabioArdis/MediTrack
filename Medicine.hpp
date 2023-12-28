#ifndef MEDICINE_HPP
#define MEDICINE_HPP

#include <vector>
#include <string>
#include <chrono>

unsigned static IDs = 0;

class Medicine
{
private:
	unsigned int id;
	std::string name, dosage, manufacturer,
		batchNo, expirationTime;

public:
	Medicine();
	Medicine(std::string name);
	std::vector<std::string> getInfo() const;
	std::string getInfo(std::string info) const;

};
#endif // !MEDICINE_HPP
