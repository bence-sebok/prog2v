#ifndef Monitor_H // Include guard == #pragma once
#define Monitor_H

#include "Equipment.h"

class Monitor: public Equipment {
    int age;

public:
    // inicializációs lista
    Monitor(int sN, int p, int a): Equipment(sN, p), age(a) {};
    void print() const;
};

#endif // Monitor_H
