#include "string.h"
#include <cstring>

namespace HomeMadeString {

	String String::concatenate(const String& string1, const String& string2)
	{
		String s;
		s.elementNum = string1.elementNum + string2.elementNum;
		if (s.elementNum == 0)
		{
			s.pData = nullptr;
			return s;
		}

		s.pData = new char[s.elementNum + 1];

		for (unsigned i = 0; i<string1.elementNum; i++)
		{
			s.pData[i] = string1.pData[i];
		}
	
		for (unsigned j = string1.elementNum; j<=s.elementNum; j++)
		{
			s.pData[j] = string2.pData[j - string1.elementNum];
		}

		return s;
	}

	bool String::compare(const String& string1,const String& string2)
	{
		if (string1.elementNum != string2.elementNum)
		{
			return false;
		}

		for (unsigned i = 0; i < string1.elementNum; i++)
		{
			if (string1.pData[i] != string2.pData[i])
			{
				return false;
			}
		}

		return true;
	}

	void String::copy(String& destination, const String& source)
	{
		delete[] destination.pData;

		destination.elementNum = source.elementNum;

		if (destination.elementNum == 0)
		{
			destination.pData = nullptr;
			return;
		}

		destination.pData = new char[destination.elementNum + 1];
		for (unsigned i = 0; i <= destination.elementNum; i++)
		{
			destination.pData[i] = source.pData[i];
		}
	}


	String::String(): elementNum(0), pData(NULL) {}

	String::String(const String& other): pData(NULL)
	{
		copy(*this, other);
	}

	String::String(const char* str)
	{
		elementNum = strlen(str);
		
		// 0 elemű sztring kezelese
		if(elementNum == 0)
		{
			pData = nullptr;
			return;
		}

		pData = new char[elementNum + 1];
		strcpy(pData, str);
	}

	String::String(char c, unsigned times): elementNum(times)
	{
		elementNum = times;

		if(elementNum == 0)
		{
			pData = nullptr;
			return;
		}

		pData = new char[elementNum+1];
		for (unsigned i = 0; i < times; i++)
			pData[i] = c;
		pData[elementNum] = '\0';
	}

	String::~String()
	{
		delete[] pData;
	}

	const char* String::getCString() const
	{
		return pData;
	}

	int String::getLength() const
	{
		return elementNum;
	}

	void String::print(std::ostream& os) const
	{
		if (pData == nullptr) 
		{
			return;
		}
		os << pData;
	}

	char String::at(unsigned pos) const
	{
		if(pos >= 0 && pos < elementNum)
		{
			return pData[pos];
		}
		else
		{
			return 0;
		}
	}

}