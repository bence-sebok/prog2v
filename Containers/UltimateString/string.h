#pragma once
#include <iostream>

namespace TheUltimateString
{
	class String
	{
		// A karakterek aktuális száma:
		int elementsNum;

		// A karaktereket tartalmazó memóriaterületre mutató pointer:
		char* pData;
	public:
		// Összefűz két stringet, és visszatér vele:
		static String concatenate(const String& string1, const String& string2);

		// Összehasonlít két stringet:
		static bool compare(const String& string1, const String& string2);

		// A második stringet az első stringbe másolja:
		static void copy(String& string1, const String& string2);

		// Argumentum nélküli konstruktor:
		String();

		// Másoló konstruktor:
		String(const String& string);

		// TODO: Egy NULL végű stringet váró konstruktor
		explicit String(const char * string); // Konverziós konstruktor

		// Egy karaktert és egy előjel nélküli egészet (times) váró konstruktor,
		// amely times darab c karakterrel inicializálja a stringet:
		String(char c, int times);

		// A destruktor:
		~String();

		// Visszatér a string hosszával
		int getLength() const;

		// Kiírja a stringet a megadott kimeneti adatfolyamba (a 'cout' ostream típusú):
		void print(std::ostream& os) const;

		// TODO: Visszaadja a megadott pozícióban lévő karaktert, egyébként dobjon std::out_of_range kivételt:
        char& operator[](int position);

		// TODO: Konstans objektumokat is le szeretnénk kérdezni
        const char& operator[](int position) const;

		// TODO: operator+, operator+=, operator=, operator==
		String operator+(const String& theOther) const;
		const String& operator+=(const String& theOther);
		const String& operator=(const String& theOther);
        bool operator==(const String& theOther) const;
		bool operator!=(const String& theOther) const;

		// TODO: Visszaad egy  csak olvasható hozzáférést a stringhez
		operator const char*() const; // Konverziós operátor
	};
}
