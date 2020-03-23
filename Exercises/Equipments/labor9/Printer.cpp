#include "stdafx.h"
#include "Printer.h"
#include <iostream>

using namespace std;

Printer::Printer(unsigned _serialNumber, unsigned _price, unsigned _cartridgeprice) : Equipment(_serialNumber, _price), cartridgePrice(_cartridgeprice) {}


Printer::~Printer()
{
}

void Printer::print() const {
	Equipment::print(); // Lesz�rmazottban megh�vjuk az �soszt�lyb�l �r�k�lt print f�ggv�nyt
	cout << " cartridge price: " << cartridgePrice << endl;
}
