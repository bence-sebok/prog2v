#pragma once

#include <string> // --> std::string használatához

class VendingMachine
{
	int drinkNumber; // Italok száma
	std::string* drinks; // Tárolt italok
public:
	// Konstruktorok
	VendingMachine(); // Alapértelmezett konstruktor
	VendingMachine(const VendingMachine&); // Másoló konstruktor
		
	// Getter: italok száma
	int getDrinkNumber();

	// Italok kezelése
	std::string removeOne(); // Első ital kivétele
	bool buy(int = 1); // Ital vásárlása, alapból egy darabot vásárol a vevő
	bool refill(std::string, int); // Automata újratöltése

	// Kiíró függvény
	void print();
	
	// Destruktor
	~VendingMachine();
};

