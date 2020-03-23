#include "stdafx.h"
#include "Monitor.h"
#include <iostream>

using namespace std;

Monitor::Monitor(unsigned _serialNumber, unsigned _price, unsigned _age) : Equipment(_serialNumber, _price), age(_age) {};

Monitor::~Monitor()
{
}

void Monitor::print() const {
	Equipment::print(); // Lesz�rmazottban megh�vjuk az �soszt�lyb�l �r�k�lt print f�ggv�nyt
	cout << " age: " << age << endl;
}
