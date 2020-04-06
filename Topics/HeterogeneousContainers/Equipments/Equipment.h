#ifndef Equipment_H // Include guard == #pragma once
#define Equipment_H

class Equipment {
// proteceted
    int serialNumber;
    int price;

public:
    // inicializációs lista
    Equipment(int sN, int p): serialNumber(sN), price(p) {};
    virtual void print() const;
};

#endif // Equipment_H
