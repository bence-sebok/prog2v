#pragma once
#include "Partner.h"
#include <string> // --> std::string
class Person :
	public Partner
{
private:
	std::string firstName;
	std::string lastName;
	std::string taxNumber;
public:
	Person();
	~Person();
	Person(const Person&);
	Person(std::string fN, std::string lN, std::string tN);
	// Getterek:
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getTaxNumber() const;
	// Setterek:
	void setFirstName(const std::string firstName);
	void setLastName(const std::string lastName);
	void setTaxNumber(const std::string taxNumber);
};

