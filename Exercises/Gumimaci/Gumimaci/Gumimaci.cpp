// Gumimaci.cpp : Defines the entry point for the console application.
//


// Standard libraries
#include <ctime>
#include <iostream>
// Visual Studio related header
#include "stdafx.h"
// Own headers
#include "Partner.h"
#include "Company.h"
#include "Person.h"

using namespace std;

int main()
{
	time(NULL); // seeding for rand()
	Company ceg1;	// ID: 0
	Company ceg2("Cegem", "1234567890"); // ID: 1
	ceg2.setVATIN("12345678901");
	Company ceg3("Ceg 2 Kft.", "00000000000"); // ID: 2
	Company ceg4(ceg3); // ID: 3
	ceg4.setBusinessName("Uj nevu cegem");
	Person m1("Ferenc", "Puskas", "0123456789"); // ID: 4
	Person m2(m1); // ID: 5
	m2.setFirstName("Kovacs");
	cout << endl << ceg3 << m2 << endl;
	return 0;
}

