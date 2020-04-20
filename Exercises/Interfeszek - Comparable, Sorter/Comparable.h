// #pragma once
#ifndef COMPARABLE_H
#define COMPARABLE_H

// Interfész: tisztán virtuális ősosztály ---> absztrakt osztály
class Comparable {
public:
    virtual bool operator<(const Comparable& other) const = 0;
    virtual bool operator==(const Comparable& other) const = 0;
};

#endif // COMPARABLE_H

