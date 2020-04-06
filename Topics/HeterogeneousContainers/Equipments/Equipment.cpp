#include "Equipment.h"
#include <iostream>

using namespace std;

void Equipment::print() const
{
    cout << "Equipment::print(): ";
    cout << "serialNumber: " << serialNumber << ", ";
    cout << "price: " << price << endl;
}
