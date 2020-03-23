#include "Vector.h"
#include <cassert>

using namespace std;

// Diagnosztikai célú kiiratás
ostream& operator<<(ostream& os, const Vector& v)
{
    for (unsigned i = 0; i < v.elementNum; i++)
    {
        os << ' ' << v.at(i);
    }
    return os; // Sorbafűzés lehetősége miatt
}

// Tömbfeltöltés operátor túlterheléssel
istream& operator>>(istream& is, Vector& v)
{
    int nextItem;
    for (unsigned i = 0; i < v.getMaxElementsNum(); i++)
    {
        cout << "Input " << i << " from maximum number of " << v.getMaxElementsNum() - 1 << ": ";
        cin >> nextItem;
        v.insert(i, nextItem);
    }
    return is; // Sorbafűzés lehetősége miatt
}

// Konstruktor
Vector::Vector(unsigned maxElementsNum): elementNum(0), maxElementsNum(maxElementsNum), pData(nullptr) {}
// Másoló konstruktor
Vector::Vector(const Vector& theOther)
{
    pData = nullptr;
    *this = theOther; // operator= használata!
}
// Destruktor
Vector::~Vector()
{
    delete[] pData;
}
// Visszatér a tömb méretével.
unsigned Vector::size() const
{
    return elementNum;
}
// Visszatér a tömb maximális méretével.
unsigned Vector::getMaxElementsNum() const
{
    return maxElementsNum;
}
// Törli a tömböt.
// Fontos különbségek a destruktorhoz képest!
void Vector::clear()
{
    delete[] pData;
    pData = nullptr;
    elementNum = 0;
}
// Törli a megadott indexű elemet. A 0 és size()-1 közötti indexek érvényesek.
bool Vector::erase(unsigned position)
{
    // Rossz index
    if(position >= elementNum)
    {
        cout << "Wrong index: " << position << endl;
        return false;
    }

    // Utolsó elem
    if (elementNum == 1)
    {
        delete[] pData;
        pData = NULL;
        elementNum = 0;
        return true;
    }

    // Minden egyéb, értelmes index
    elementNum -= 1;
    int* pTemp = new int[elementNum];
    for (unsigned i = 0, j = 0; i < elementNum + 1; i++, j++)
    {
        // Törlendő kivételével többi elem shiftelése
        if (i == position)
        {
            j--;
        }
        else
        {
            pTemp[j] = pData[i];
        }
    }
    delete[] pData;
    pData = pTemp;
    return true;
}

// Visszatér a megadott indexű elemmel, amely módosítható is egyben.
// A 0 és size()-1 közötti indexek érvényesek.
int& Vector::at(unsigned position)
{
    // assert: baj van, ha position >= elementNum
    // assert-ről bővebben: https://en.cppreference.com/w/cpp/error/assert
	assert(position < elementNum);
    return pData[position];
}
// Visszatér a megadott indexű elemmel, amely csak olvasható.
// A 0 és size()-1 közötti indexek érvényesek. Az int típus esetén nem kellene
// const referencia (mert olcsó művelet a beépített típusú
// változók másolása), de saját típus esetén igen.
const int& Vector::at(unsigned position) const
{
    if (position >= elementNum)
    {
        cout << "Wrong index: " << position << endl;
    }
    return pData[position];
}
// Beszúr egy elemet a megadott indexű helyre.
// Ha az index nagyobb, mint a tömb mérete, megnöveli a tömb méretét,
// és a szükséges új helyeket nullákkal tölti fel.
bool Vector::insert(unsigned position, int element)
{
    // Nem tudunk több elemet beszúrni
    if (elementNum == maxElementsNum)
    {
        cerr << "No more free space in vector object, maximum space is " << getMaxElementsNum() << endl;
        return false;
    }
    // Tudunk még eleme(ke)t beszúrni
    int* pTemp = nullptr;
    if (position < elementNum)
    {
        pTemp = new int[elementNum + 1];
        
        for (unsigned i = 0, j = 0; i < elementNum; i++, j++)
        {
            if (j == position)
            {
                pTemp[position] = element;
                i--;
            }
            else
            {
                pTemp[j] = pData[i];
            }
        }
        elementNum++;
    }
    else
    {
        pTemp = new int[position + 1];
        for (unsigned i = 0; i < position; i++)
        {
            if (i < elementNum)
            {
                pTemp[i] = pData[i];
            }
            else
            {
                pTemp[i] = 0;
            }
        }
        pTemp[position] = element;
        elementNum = position + 1;
    }
    delete[]pData;
    pData = pTemp;
    return true;
}
// Két operator[]. Az at() tagfüggvény operator formában is.
int& Vector::operator[](unsigned position)
{
    return at(position);
}
const int& Vector::operator[](unsigned position) const
{
    return at(position);
}
// Minden elem megszorzása a jobb oldali operandussal.
void Vector::operator*=(unsigned right)
{
    for (unsigned i = 0; i < elementNum; i++)
    {
        pData[i] *= right;
    }
}
// A jobb oldali operandus hozzáadása minden elemhez.
void Vector::operator+=(unsigned right)
{
    for (unsigned i = 0; i < elementNum; i++)
    {
        pData[i] += right;
    }
}
// operator=
Vector& Vector::operator=(const Vector& theOther)
{
    // Legyen egyenlő önmagával (memóriacím szerinti egyezés)
    if (this == &theOther)
    {
        return *this;
    }
    
    delete[] pData;
    maxElementsNum = theOther.maxElementsNum;

    // "Nincs mit egyenlővé tenni"
    if(theOther.elementNum == 0)
    {
        elementNum = 0;
        pData = nullptr;
    }
    else // Van mit másolni
    {
        elementNum = theOther.elementNum;
        pData = new int[elementNum];
        for (unsigned i = 0; i < elementNum; i++)
        {
            pData[i] = theOther.pData[i];
        }
    }
    return *this;
}
