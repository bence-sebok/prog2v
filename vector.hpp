#include <limits.h>
#include <iostream>

// Egy dinamikus t�mb oszt�ly.
template <class T>
class Vector
{
	// A t�mb m�rete.
	unsigned elementNum;

	// Az adatokra mutat� pointer.
	T *pData;

	// Diagnosztikai c�l� glob�lis kiirat�oper�tor.
	friend std::ostream& operator<<(std::ostream&, const Vector&);

public:
	// Konstruktorok, destruktor.
	Vector();
	Vector(const Vector& other);
	~Vector();

	// Visszat�r a t�mb m�ret�vel. 
	unsigned  size() const;

	// T�rli a t�mb�t.
	void clear();

	// T�rli a megadott index� elemet. A 0 �s size()-1 k�z�tti indexek �rv�nyesek.
	// Igazzal t�r vissza, ha sikeres a t�rl�s, k�l�nben hamissal.
	bool erase(unsigned position);

	// Visszat�r a megadott indexu elemmel, amely m�dos�that� is egyben.
	// A 0 �s size()-1 k�z�tti indexek �rv�nyesek.
	T& at(unsigned position);

	// Visszat�r a megadott indexu elemmel, amely csak olvashat�.
	// A 0 �s size()-1 k�z�tti indexek �rv�nyesek.
	const T& at(unsigned position) const;

	// Besz�r egy elemet a megadott index� helyre. 
	// Ha az index nagyobb, mint a t�mb m�rete, megn�veli a t�mb m�ret�t, 
	// �s a sz�ks�ges �j helyeket null�kkal t�lti fel.
	bool insert(unsigned position, T element);

	// A bal oldali vektort fel�l�rja a jobb oldalival.
	const Vector& operator=(const Vector& theOther);

	// K�t operator[]. Az at() tagf�ggv�ny operator form�ban is.
	T& operator[](unsigned position);
	const T& operator[](unsigned position) const;
};

// Diagnosztikai c�l� kiirat�s.
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