#include "stdafx.h"
#include "Monitor.h"
#include <iostream>

using namespace std;

Monitor::Monitor(unsigned _serialNumber, unsigned _price, unsigned _age) : Equipment(_serialNumber, _price), age(_age) {};

Monitor::~Monitor()
{
}

void Monitor::print() const {
	Equipment::print(); // Leszármazottban meghívjuk az õsosztályból örökölt print függvényt
	cout << " age: " << age << endl;
}
