// labor9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Equipment.h"
#include "Monitor.h"
#include "Printer.h"
#include <iostream>

using namespace std;


int main()
{
	Equipment* equipments[10];
	for (int i = 0; i <= 4; i++)
	{
		// Ősosztály típusú pointerekkel mutathatunk leszármazott típusú objektumokra
		equipments[i] = new Monitor(100 * i, 1000 * i, i);
	}
	for (int i = 5; i <= 9; i++)
	{
		// Ősosztály típusú pointerekkel mutathatunk leszármazott típusú objektumokra
		equipments[i] = new Printer(200 * i, 500 * i, 200 * i);
	}
	for (int i = 0; i <= 9; i++)
	{
		equipments[i]->print();
		delete equipments[i];
		cout << endl;
	}
    return 0;
}


