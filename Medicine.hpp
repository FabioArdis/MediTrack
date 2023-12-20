#ifndef MEDICINE_HPP
#define MEDICINE_HPP

#include <vector>
#include <string>
#include <chrono>

class Medicine
{
private:
	unsigned const int id;
	std::string name, dosage, manufacturer,
		batchNo, expirationTime;

public:
	Medicine();
	std::vector<std::string> getInfo() const;
	std::string getInfo(std::string info) const;

};
#endif // !MEDICINE_HPP
