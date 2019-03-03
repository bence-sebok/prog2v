#include "VendingMachine.h"
#include <cstdio>

// Alapértelmezett konstruktor
VendingMachine::VendingMachine()
{
	drinkNumber = 0; // Kezdetben 0 italt tárol
	drinks = nullptr; // Nincsenek még italok
}

// Másoló konstruktor
// Egy már meglévő másik VendingMachine adataival inicializálok egy új VendingMachine-t
VendingMachine::VendingMachine(const VendingMachine & other)
{
	drinkNumber = other.drinkNumber; // Italok számának mentése
	drinks = nullptr;
	if (drinkNumber > 0) // Ha vannak másolandó italok (legalább 1 darab)
	{
		// drinkNumber darabnyi std:string-nek való helyfoglalás (~sztringek tömbje)
		drinks = new std::string[drinkNumber]; // Memória foglalása a másolandó italoknak
		// Italok másolása
		for (int i = 0; i < drinkNumber; i++)
			drinks[i] = other.drinks[i];
	}
}

// Getter: italok száma
int VendingMachine::getDrinkNumber()
{
	return drinkNumber;
}

// Destruktor
VendingMachine::~VendingMachine()
{
	// Dinamikusan foglaltuk az italoknak a memóriát --> FELSZABADÍTÁS!
	delete[] drinks; // new[] párja: delete[], new párja: delete
}

// Első ital kivétele
std::string VendingMachine::removeOne()
{
	// Van-e egyáltalán ital a gépben?
	if (drinkNumber < 1)
	{
		return "Ures a gep :-(";
	}

	// Első elem visszaadása a függvény végén
	std::string value = drinks[0];

	// Maradék italok tárolása
	std::string* remaining;
	remaining = new std::string[drinkNumber - 1]; // Eggyel kisebb méretű tömb foglalása

	// Italok másolása az első elem kivételével
	for (int i = 1; i < drinkNumber; i++)
	{
		remaining[i-1] = drinks[i];
	}

	// Eggyel kevesebb ital marad
	drinkNumber = drinkNumber - 1;

	// Régi memóriaterület felszabadítása
	delete[] drinks;

	// Pointer átállítása az új tömbre
	drinks = remaining;

	// Első ital visszaadása
	return value;
}

// Ital vásárlása
// - Alapértelmezetten 1 darab ital vásárlása, de lehet többet is
// - Ha többet vennénk, mint amennyi van: return false, amúgy return true
bool VendingMachine::buy(int num) // num = vásárolandó italok száma
{
	// Ha többet vennénk, mint amennyi van
	if (num > drinkNumber)
	{
		return false;
	}
	// Ha van elég ital, akkor egyesével visszaadjuk őket
	for (int i = 0; i < num; i++)
	{
		printf("Ital megvasarlasa: %s\n", removeOne().c_str()); // c_str() a std::string miatt kell
	}
	// Vásárlás sikerült:
	return true;
}

// Automata újratöltése: ital neve és darabszáma
bool VendingMachine::refill(std::string pName, int pQty)
{
	// Nem teszünk be nulla vagy negatív darab italt...
	if (pQty <= 0)
	{
		return false;
	}

	// Italoknak memóriafoglalás
	std::string* tmp;
	tmp = new std::string[drinkNumber + pQty]; // Eddigi italok + új adag összedarabszáma

	// Eddigi italok másolása
	for (int i = 0; i < drinkNumber; i++)
	{
		tmp[i] = drinks[i];
	}

	// Új adag tárolása
	// Eddigiek után helyezzük el őket!
	for (int i = drinkNumber; i < (drinkNumber + pQty); i++)
	{
		tmp[i] = pName;
	}

	// Darabszám módosítása: eddigiek + újak
	drinkNumber = drinkNumber + pQty;

	// Régi memóriaterület felszabadítása
	delete[] drinks;

	// Italok pointer módosítása: kibővített tömb (eddigiek + újak)
	drinks = tmp;
}

// Kiíró függvény
void VendingMachine::print()
{
	printf("Italok szama: %d\n", drinkNumber);
	printf("Italok felsorolasa:\n");
	for (int i = 0; i < drinkNumber; i++)
	{
		printf("%s\n", drinks[i].c_str()); // std:string miatt c_str()!
	}
}


