#include "stdafx.h"
#include "Person.h"
#include <iostream>

using namespace std;

// Konstruktorok
Person::Person() : Partner(), firstName("John"), lastName("Done"), taxNumber("") {}
Person::Person(const string firstName, const string lastName, const string taxNumber) : firstName(firstName), lastName(lastName), taxNumber(taxNumber) {}
Person::Person(const Person & other) : Partner(other), firstName(other.getFirstName()), lastName(other.getLastName()), taxNumber(other.getTaxNumber()) {}
// Destruktor
Person::~Person() {
	cout << id << " Person descturctor" << endl;
}
// Setterek
void Person::setTaxNumber(const string taxNumber) {
	this->taxNumber = taxNumber;
}
void Person::setFirstName(const string firstName) {
	this->firstName = firstName;
}
void Person::setLastName(const string lastName) {
	this->lastName = lastName;
}
// Getterek
string Person::getFirstName() const {
	return firstName;
}
string Person::getLastName() const {
	return lastName;
}
string Person::getTaxNumber() const {
	return taxNumber;
}
