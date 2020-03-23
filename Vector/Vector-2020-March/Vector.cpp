#include <cstddef>
#include <iostream>
#include <cstdlib>
#include "Vector.h"

using namespace std; // std::cout, std::cin

// Konstruktor
// Inicializációs lista
Vector::Vector(unsigned maxElementsNum) //: pData(nullptr), elementNum(0), maxElementsNum(maxElementsNum) {}
{
    cout << "Vector::Vector(unsigned maxElementsNum)" << endl;
    cout << "maxElementsNum: " << maxElementsNum <<endl;
    // Ezt kizárólag tesztelési célből írtuk, ehelyett az inic. listás megoldás a cél
    // 0...9 számok tárolása teszteléshez
    elementNum = 10;
    pData = new int[elementNum];
    maxElementsNum = maxElementsNum;
    for(unsigned i = 0; i < elementNum; i++)
    {
        pData[i] = i;
    }
}

// Visszatér a tömb maximális méretével.
unsigned Vector::getMaxElementsNum() const
{
    return maxElementsNum;
}

// Destruktor
Vector::~Vector()
{
    // new[]-val foglaltunk
    delete[] pData;
}

// Visszatér a tömb méretével.
unsigned Vector::size() const
{
    return elementNum;
}

// Törli a tömböt.
// clear után újra szeretném használni a tömböt!
// clear vs destruktor: nem elég a delete[]
void Vector::clear()
{
    delete[] pData;
    pData = nullptr;
    elementNum = 0;
}

// operator=
// FONTOS: másoló konstruktorban meghívjuk az operator=-t
// Vector v2;
// Vector v3;
// v2, v3 feltöltése
// v2 = v3; // v2-re mutat this, v3 a theOther
Vector& Vector::operator=(const Vector& theOther)
{
    cout << "Vector::operator=" << endl;
    if(this == &theOther)
    {
        return *this; // *: mert a this az egy pointer, viszont a Vector& az NEM pointert vár
    }

    delete[] pData; // delete[] this->pData;
    maxElementsNum = theOther.maxElementsNum;

    // Üres Vectorral írjuk felül a mi Vectorunkat
    if(theOther.elementNum == 0)
    {
        elementNum = 0;
        pData = nullptr;
    }
    else { // Nem üres a theOther, ezért másolunk
        elementNum = theOther.elementNum;
        pData = new int[elementNum];
        for(unsigned i = 0; i < elementNum; i++)
        {
            pData[i] = theOther.pData[i];
        }
    }

    return *this;
}

// Másoló konstruktor az operator= hívásával!!!
Vector::Vector(const Vector& theOther)
{
    cout << "Vector::Vector(const Vector& theOther)" << endl;
    pData = nullptr;
    *this = theOther; // operator= hívása
}

// Két operator[]
// Vector v;
// v feltöltése
// v[2]
int& Vector::operator[](unsigned index)
{
    // Érvénytelen indexek:
    // - nagyobb indexek, mint a tárolt elemekhez tartozó indexek
    // - negatív indexek
    if(index > elementNum || index < 0) // this->elementNum
    {
        cout << "Ervenytelen index: " << index << endl;
    }
    else
    {
        return pData[index]; // this->pData[index]
    }
}

const int& Vector::operator[](unsigned index) const
{
    // Érvénytelen indexek:
    // - nagyobb indexek, mint a tárolt elemekhez tartozó indexek
    // - negatív indexek
    if(index > elementNum || index < 0) // this->elementNum
    {
        cout << "Ervenytelen index: " << index << endl;
    }
    else
    {
        return pData[index]; // this->pData[index]
    }
}

// Diagnosztikai célú globális kiiratóoperátor
// cout << v;
ostream& operator<<(ostream& os, const Vector& v)
{
    for(unsigned i = 0; i < v.elementNum; i++)
    {
        os << ' ' << v[i]; // operator[]
    }
    return os; // <<, <<, <<: összefűzött kiíratás
}

