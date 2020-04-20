#include "Person.h"

unsigned int Person::getAge() const {
    return age;
}
void Person::setAge(unsigned int a)
{
    if(a > 0)
    {
        age = a;
    }
}

bool Person::operator<(const Comparable& other) const {
	Person* pPerson = (Person*)&other;
	return this->age < pPerson->age;
}

bool Person::operator==(const Comparable& other) const {
    Person * personOther = (Person*)&other;
    if(this->age == personOther->age)
    {
        return true;
    }
    else {
        return false;
    }
}
