#pragma once

#include <string>

// �soszt�ly
class Employee
{
protected:
	static const double baseSalary; // static const!
	std::string name;

public:
	Employee(const std::string &nm)
	{
		name = nm;
	}

	std::string getName() const
	{
		return name;
	}

	virtual double getSalary() const
	{
		return baseSalary;
	}
};

// Lesz�rmazott
class DivisionManager : public Employee
{
	static const double divisionManagerSalaryFactor; // static const!

public:
	// Lesz�rmazott konstruktora h�vja meg az �soszt�ly konstruktor�t!
	DivisionManager(const std::string &nm) : Employee(nm) {}

	double getSalary() const // const!
	{
		return baseSalary * divisionManagerSalaryFactor;
	}
};

// Lesz�rmazott
class VicePresident : public Employee {
	static const double vicePresidentSalaryFactor; // static const!

public:
	// Lesz�rmazott konstruktora h�vja meg az �soszt�ly konstruktor�t!
	VicePresident(const std::string &nm) : Employee(nm) {}

	double getSalary() const // const!
	{
		return baseSalary * vicePresidentSalaryFactor;
	}
};

// Lesz�rmazott
class President : public Employee {
	static const double presidentSalaryFactor; // static const!

public:
	// Lesz�rmazott konstruktora h�vja meg az �soszt�ly konstruktor�t!
	President(const std::string &nm) : Employee(nm) {}

	double getSalary() const // const!
	{
		return baseSalary * presidentSalaryFactor;
	}
};