#include "stdafx.h"
#include "Company.h"
#include <iostream>

using namespace std; // std::string --> string

// Ősosztály konstruktor hívása, adatok beállítása
Company::Company() : Partner(), businessName("Business name"), VATIN("") {}

// Két paraméteres konstruktor
Company::Company(const string businessName, const string VATIN) : businessName(businessName), VATIN(VATIN) {}

// Másoló konstruktor
Company::Company(const Company& other) : businessName(other.businessName), VATIN(other.VATIN) {}

// Destruktor
Company::~Company() {
	cout << id << " company desctructor" << endl;
}

// Setterek
void Company::setVATIN(const string VATIN) {
	this->VATIN = VATIN;
}
void Company::setBusinessName(const string businessName) {
	this->businessName = businessName;
}
// Getterek
string Company::getBusinessName() const {
	return businessName;
}
string Company::getVATIN() const {
	return VATIN;
}
