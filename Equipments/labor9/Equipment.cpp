#include "stdafx.h"
#include "Equipment.h"
#include <iostream>

using namespace std;

Equipment::~Equipment()
{
}

void Equipment::print() const {
	cout << "Serial number:" << serialNumber << " price: " << price;
}
