#include <limits.h>
#include <iostream>

// Egy dinamikus tömb osztály.
template <class T>
class Vector
{
	// A tömb mérete.
	unsigned elementNum;

	// Az adatokra mutató pointer.
	T *pData;

	// Diagnosztikai célú globális kiiratóoperátor.
	friend std::ostream& operator<<(std::ostream&, const Vector&);

public:
	// Konstruktorok, destruktor.
	Vector();
	Vector(const Vector& other);
	~Vector();

	// Visszatér a tömb méretével. 
	unsigned  size() const;

	// Törli a tömböt.
	void clear();

	// Törli a megadott indexû elemet. A 0 és size()-1 közötti indexek érvényesek.
	// Igazzal tér vissza, ha sikeres a törlés, különben hamissal.
	bool erase(unsigned position);

	// Visszatér a megadott indexu elemmel, amely módosítható is egyben.
	// A 0 és size()-1 közötti indexek érvényesek.
	T& at(unsigned position);

	// Visszatér a megadott indexu elemmel, amely csak olvasható.
	// A 0 és size()-1 közötti indexek érvényesek.
	const T& at(unsigned position) const;

	// Beszúr egy elemet a megadott indexû helyre. 
	// Ha az index nagyobb, mint a tömb mérete, megnöveli a tömb méretét, 
	// és a szükséges új helyeket nullákkal tölti fel.
	bool insert(unsigned position, T element);

	// A bal oldali vektort felülírja a jobb oldalival.
	const Vector& operator=(const Vector& theOther);

	// Két operator[]. Az at() tagfüggvény operator formában is.
	T& operator[](unsigned position);
	const T& operator[](unsigned position) const;
};

// Diagnosztikai célú kiiratás.
template <class T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v)
{
	for (unsigned i = 0; i < v.elementNum; i++)
		os << ' ' << v.at(i);
	return os;
}

template <class T>
Vector<T>::Vector(): elementNum(0), pData(nullptr) { }

template <class T>
Vector<T>::Vector(const Vector& other): pData(nullptr)
{
	*this = other;
}

template <class T>
Vector<T>::~Vector()
{
	delete[] pData;
}

template <class T>
unsigned Vector<T>::size() const
{
	return elementNum;
}

template <class T>
void Vector<T>::clear()
{
	delete[] pData;
	pData = nullptr;
	elementNum = 0;
}

template <class T>
bool Vector<T>::erase(unsigned position)
{
	if (position >= elementNum)
		return false;

	if (elementNum == 1)
	{
		delete[] pData;
		pData = nullptr;
		elementNum = 0;
		return true;
	}

	T* pTemp = new T[--elementNum];

	for (unsigned i = 0, j = 0; i < elementNum + 1; i++, j++)
	{
		if (i == position)
			j--;
		else
			pTemp[j] = pData[i];
	}

	delete[] pData;
	pData = pTemp;
	return true;
}

template <class T>
T& Vector<T>::at(unsigned position)
{
	return pData[position];
}

template <class T>
const T& Vector<T>::at(unsigned position) const
{
	return pData[position];
}

template <class T>
bool Vector<T>::insert(unsigned position, T element)
{
	if (elementNum == UINT_MAX)
		return false;

	T* pTemp = nullptr;
	if (position < elementNum)
	{
		pTemp = new T[elementNum + 1];
		for (unsigned i = 0, j = 0; i < elementNum; i++, j++)
		{
			if (j == position)
			{
				pTemp[position] = element;
				i--;
			}
			else
				pTemp[j] = pData[i];
		}

		elementNum++;
	}
	else
	{
		pTemp = new T[position + 1];
		for (unsigned i = 0; i<position; i++)
		{
			if (i < elementNum)
				pTemp[i] = pData[i];
			else
				pTemp[i] = 0;
		}

		pTemp[position] = element;
		elementNum = position + 1;
	}

	delete[] pData;
	pData = pTemp;

	return true;
}

template <class T>
T& Vector<T>::operator[](unsigned position)
{
	return at(position);
}

template <class T>
const T& Vector<T>::operator[](unsigned position) const
{
	return at(position);
}

template <class T>
const Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this == &other)
		return *this;

	delete[] pData;

	if (!other.elementNum)
	{
		elementNum = 0;
		pData = nullptr;
	}
	else
	{
		elementNum = other.elementNum;
		pData = new T[elementNum];
		for (unsigned i = 0; i < elementNum; i++)
			pData[i] = other.pData[i];
	}

	return *this;
}