#pragma once
#include "Equipment.h"
class Monitor :
	public Equipment
{
private:
	unsigned age;
public:
	Monitor(unsigned _serialNumber = 0, unsigned _price = 0, unsigned _age = 0);
	unsigned getAge() const { return age; }
	void setAge(unsigned _age) { age = _age; }
	void print() const;
	~Monitor();
};

