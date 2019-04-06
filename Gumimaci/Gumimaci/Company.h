#pragma once
#include "Partner.h"
#include <string>
class Company :
	public Partner
{
private:
	std::string businessName;
	std::string VATIN; // Value Added Tax Identifier Name
public:
	Company();
	~Company();
	Company(const Company&);
	Company(const std::string bN, const std::string v);
	// Getterek:
	std::string getBusinessName() const;
	std::string getVATIN() const;
	// Setterek:
	void setVATIN(const std::string v);
	void setBusinessName(const std::string bN);
};

