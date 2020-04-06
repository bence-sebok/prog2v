#include "Printer.h"
#include <iostream>

using namespace std;

void Printer::print() const {
    cout << "Printer::print(): " << endl;
    Equipment::print();
    cout << "CartridgePrice: " << cartridgePrice << endl;
}

