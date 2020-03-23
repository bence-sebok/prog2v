#pragma once

#include <iostream>

// Egy dinamikus tömb osztály
class Vector
{
	// ---------------------------------------------
	// Tagváltozók
	// ---------------------------------------------
	// A tömb mérete
	unsigned elementNum;
	// A tömb maximális mérete; alapértelmezetten 20
	unsigned maxElementsNum;
	// Az adatokra mutató pointer
	int *pData;
	// ---------------------------------------------
	
	// ---------------------------------------------
	// Globális operátorok
	// ---------------------------------------------
	// Diagnosztikai célú globális kiiratóoperátor
	friend std::ostream& operator<<(std::ostream&, const Vector&);
	// Tömbfeltöltés operátor túlterheléssel
	friend std::istream& operator>>(std::istream&, Vector&);
	// ---------------------------------------------
public:
	// ---------------------------------------------
	// Konstruktorok, destruktor
	// ---------------------------------------------
	Vector(unsigned = 20);
	Vector(const Vector&);
	~Vector();
	// ---------------------------------------------

	// ---------------------------------------------
	// Publikus tagfüggvények
	// ---------------------------------------------
	// Visszatér a tömb méretével.
	unsigned size() const;
	// Visszatér a tömb maximális méretével.
	unsigned getMaxElementsNum() const;
	// Törli a tömböt.
	void clear();	
	// Törli a megadott indexű elemet. A 0 és size()-1 közötti indexek érvényesek.
	bool erase(unsigned);
	// Visszatér a megadott indexű elemmel, amely módosítható is egyben.
	// A 0 és size()-1 közötti indexek érvényesek.
	int& at(unsigned);
	// Visszatér a megadott indexű elemmel, amely csak olvasható.
	// A 0 és size()-1 közötti indexek érvényesek. Az int típus esetén nem kellene
	// const referencia (mert olcsó művelet a beépített típusú
	// változók másolása), de saját típus esetén igen.
	const int& at(unsigned) const;
	// Beszúr egy elemet a megadott indexű helyre.
	// Ha az index nagyobb, mint a tömb mérete, megnöveli a tömb méretét,
	// és a szükséges új helyeket nullákkal tölti fel.
	bool insert(unsigned, int);
	// ---------------------------------------------

	// ---------------------------------------------
	// Osztályon belüli operátorok
	// ---------------------------------------------
	// operator=
	Vector& operator=(const Vector&);
	// Két operator[]. Az at() tagfüggvény operator formában is.
	int& operator[](unsigned);
	const int& operator[](unsigned) const;
	// Minden elem megszorzása a jobb oldali operandussal.
	void operator*=(unsigned);
	// A jobb oldali operandus hozzáadása minden elemhez.
	void operator+=(unsigned);
	// ---------------------------------------------
};

// ---------------------------------------------
// Globális operátorok
// ---------------------------------------------
// Diagnosztikai célú kiiratás
std::ostream& operator<<(std::ostream&, const Vector&);
// Tömbfeltöltés operátor túlterheléssel
std::istream& operator>>(std::istream&, Vector&);
// ---------------------------------------------