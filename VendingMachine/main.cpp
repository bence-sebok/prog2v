#include "VendingMachine.h"

int main()
{
	// Néhány ital
	std::string Cola("Coca-Cola");
	std::string Fanta("Fanta");

	// Italautomata tesztelése
	VendingMachine coldDrinkMachine; // Alapértelmezett konstruktor
	coldDrinkMachine.refill(Cola, 5); // 5 darab Cola betöltése
	coldDrinkMachine.print(); // Készlet kiírása, elvárás: 5 db Coca-Cola
	coldDrinkMachine.refill(Fanta, 3); // 3 darab Fanta betöltése
	coldDrinkMachine.print(); // Készlet kiírása, elvárás: 5 db Coca-Cola, 3 darab Fanta

	// Másolókonstruktor
	// 5 darab Coca-Cola és 3 darab Fanta másolása az új automatába
	VendingMachine hotDrinkMachine(coldDrinkMachine);

	// 3 darab üdítő vásárlása az első gépből
	coldDrinkMachine.buy(3);

	// Készletek kiíratása
	coldDrinkMachine.print();
	hotDrinkMachine.print();	
}