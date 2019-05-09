#pragma once

#include <string>

// Õsosztály
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

// Leszármazott
class DivisionManager : public Employee
{
	static const double divisionManagerSalaryFactor; // static const!

public:
	// Leszármazott konstruktora hívja meg az õsosztály konstruktorát!
	DivisionManager(const std::string &nm) : Employee(nm) {}

	double getSalary() const // const!
	{
		return baseSalary * divisionManagerSalaryFactor;
	}
};

// Leszármazott
class VicePresident : public Employee {
	static const double vicePresidentSalaryFactor; // static const!

public:
	// Leszármazott konstruktora hívja meg az õsosztály konstruktorát!
	VicePresident(const std::string &nm) : Employee(nm) {}

	double getSalary() const // const!
	{
		return baseSalary * vicePresidentSalaryFactor;
	}
};

// Leszármazott
class President : public Employee {
	static const double presidentSalaryFactor; // static const!

public:
	// Leszármazott konstruktora hívja meg az õsosztály konstruktorát!
	President(const std::string &nm) : Employee(nm) {}

	double getSalary() const // const!
	{
		return baseSalary * presidentSalaryFactor;
	}
};