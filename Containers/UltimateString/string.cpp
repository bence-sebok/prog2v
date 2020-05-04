#include <iostream>
#include <cstring> // strlen
#include "string.h"

using namespace std;

namespace TheUltimateString
{
	String String::concatenate(const String& string1, const String& string2)
	{
		String s;
		s.elementsNum = string1.elementsNum + string2.elementsNum;

		if (s.elementsNum == 0)
		{
			s.pData = NULL;
			return s;
		}

		s.pData = new char[s.elementsNum + 1];

		for (int i = 0; i<string1.elementsNum; i++)
			s.pData[i] = string1.pData[i];

		for (int j = string1.elementsNum; j<s.elementsNum; j++)
			s.pData[j] = string2.pData[j - string1.elementsNum];

		s.pData[s.elementsNum] = '\0';
		return s;
	}

	bool String::compare(const String& string1, const String& string2)
	{
		if (string1.elementsNum != string2.elementsNum)
			return false;

		for (int i = 0; i < string1.elementsNum; i++)
			if (string1.pData[i] != string2.pData[i])
				return false;

		return true;
	}

	void String::copy(String &to, const String& from)
	{
		delete[] to.pData;
		to.elementsNum = from.elementsNum;
		if (to.elementsNum == 0)
		{
			to.pData = NULL;
			return;
		}

		to.pData = new char[to.elementsNum + 1];

		for (int i = 0; i<to.elementsNum; i++)
			to.pData[i] = from.pData[i];

		to.pData[to.elementsNum] = '\0';
	}

	String::String() : pData(NULL), elementsNum(0) { }

	String::String(const String& string) : pData(NULL)
	{
		copy(*this, string);
	}

	String::String(const char c, int times) : elementsNum(times)
	{
		if (elementsNum == 0)
		{
			pData = NULL;
			return;
		}

		pData = new char[elementsNum + 1];
		for (int i = 0; i<elementsNum; i++)
			pData[i] = c;

		pData[elementsNum] = '\0';
	}

	String::~String()
	{
		delete[] pData;
	}

	int String::getLength() const
	{
		return elementsNum;
	}


	void String::print(ostream& os) const
	{
		os << *pData;
	}

	bool String::operator!=(const String& theOther) const
	{
		return !(*this == theOther);
	}

	// Konverziós konstruktor
	String::String(const char* str)
	{
	    elementsNum = strlen(str);

        // üres stringet kapok
	    if(elementsNum == 0)
        {
            pData = NULL;
            return;
        }

        // nem üres stringet kapok --> el kell tárolni
        pData = new char[elementsNum + 1];
        for(int i = 0; i < elementsNum; i++)
        {
            pData[i] = str[i];
        }
        pData[elementsNum] = '\0';
	}

	char& String::operator[](int position)
	{
	    return pData[position];
	}

    const char& String::operator[](int position) const
	{
	    // TODO: const String* --> String*
	    return *(const_cast<String*>(this))[position];
	}

	String String::operator+(const String& theOther) const
	{
	    return concatenate(*this, theOther);
	}

	const String& String::operator+=(const String& theOther)
	{
	    // használat: str1 += str2; --> str1 = str1 + str2;
	    *this = *this + theOther; // operator+
	    return *this; // * kell, mert const String& típussal térünk vissza
	}

	const String& String::operator=(const String& theOther)
	{
	    // használat: str1 = str2;
	    copy(*this, theOther); // *this <-- theOther
	    return *this;
	}

	bool String::operator==(const String& theOther) const
	{
	    return compare(*this, theOther);
	}

	String::operator const char*() const
	{
	    return pData; // const char*-ként adjuk vissza a pData-t
	}
}
