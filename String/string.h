#pragma once

#include <iostream>

namespace HomeMadeString
{
	class String
	{
		// A karakterek aktuális száma. A NULL terminátor nem számít bele, de ugyanúgy tároljuk.
		unsigned elementNum; // unsigned === unsigned int

		// A karaktereket tartalmazó memóriaterületre mutató pointer
		char* pData;
	public:
		// Összefűz két stringet, és visszatér vele
		static String concatenate(const String&, const String&);

		// Összehasonlít két stringet
		static bool compare(const String&, const String&);

		// A második stringet az első stringbe másolja
		static void copy(String&, const String&);

		// Argumentum nélküli konstruktor:
		String();

		// Másoló konstruktor
		String(const String&);

		// Egy NULL végű stringet váró konstruktor
		String(const char*);

		// Egy karaktert és egy előjel nélküli egészet (times) váró konstruktor,
		// amely times darab c karakterrel inicializálja a stringet
		String(char, unsigned);

		// A destruktor
		~String();

		// Visszaadja a tárolt C stringet
		const char* getCString() const;

		// Visszatér a string hosszával
		int getLength() const;

		// Kiírja a stringet a megadott kimeneti adatfolyamba (A 'cout' ostream típusú.
		// A .h állományban nem használunk using namespace-t, mert nem tudjuk, hova lesz
		// beépítve, és ott milyen hatása lesz. Ezért kiíjuk az std::-t. Ez a .cpp állományban
		// már nem kell, ott használhatjuk a using namespace std utasítást):
		void print(std::ostream&) const;

		// Visszaadja a megadott pozícióban lévo karaktert, egyébként nullát:
		char at(unsigned) const;
	};
}