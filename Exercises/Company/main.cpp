// vallalati_alkalmazottak.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // Visual Studio miatt kell
#include <iostream>
#include "Company.h"

using namespace std;

int main()
{
	// HETEROGÉN KOLLEKCIÓ
	// Ősosztály típusú pointerek tömbje
	Employee *employees[4];
	// Ősosztály típusú pointerrel rá lehet mutatni a leszármazott típusú objektumok címére
	employees[0] = new Employee("Bence");
	employees[1] = new DivisionManager("Tamas");
	employees[2] = new VicePresident("Berci");
	employees[3] = new President("Adam");

	// Heterogén kollekció feldolgozása
	for (int i = 0; i < 4; i++)
	{
		// Az ősosztály függvénye, vagy a virtual kulcsszó miatt a megfelelő leszármazott függvénye hívódik meg
		cout << employees[i]->getName() << " fizetese: " << employees[i]->getSalary() << endl;
		delete employees[i]; // Memóriaszivárgás elkerülésére
	}

	// Alternatív megoldás a memóriaszivárgás elkerülésére
	/*
	for (int i = 0; i < 4; i++)
	{
		delete employees[i];
	}
	*/

	return 0;
}