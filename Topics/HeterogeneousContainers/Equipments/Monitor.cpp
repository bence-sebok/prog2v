#include "Monitor.h"
#include <iostream>

using namespace std;

void Monitor::print() const {
    cout << "Monitor::print(): " << endl;
    Equipment::print();
    cout << "Age: " << age << endl;
}
