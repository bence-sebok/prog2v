#ifndef Printer_H // Include guard == #pragma once
#define Printer_H

#include "Equipment.h"

class Printer: public Equipment {
    int cartridgePrice;

public:
    // inicializációs lista
    Printer(int sN, int p, int cP): Equipment(sN, p), cartridgePrice(cP) {};
    void print() const;
};

#endif // Printer_H

