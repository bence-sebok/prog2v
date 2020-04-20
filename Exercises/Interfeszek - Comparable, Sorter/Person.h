// #pragma once
#ifndef PERSON_H
#define PERSON_H

#include "Comparable.h"

class Person : public Comparable {
private:
    unsigned int age;
public:
    Person(unsigned int a) : age(a) {}
    unsigned int getAge() const;
    void setAge(unsigned int a);
    bool operator<(const Comparable& other) const;
    bool operator==(const Comparable& other) const;
};

#endif // PERSON_H
