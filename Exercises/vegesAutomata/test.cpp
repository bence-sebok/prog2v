#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

extern void vectorTest();
extern void finiteAutomatonTest();

int main()
{
	cout << "1. feladat - Vector osztaly teszt" << endl;
	vectorTest();

	cout << endl << "2. feladat - Vector osztallyal megvalositott veges automata" << endl;
	finiteAutomatonTest();

	getchar();

	return 0;
}
