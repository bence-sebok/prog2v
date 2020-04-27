#include "Vector.hpp"

using namespace std;

void vectorTest()
{
	Vector<int> v1;

	// Insert tesztel�se
	for (int i = 1; i < 10; i++)
		v1.insert(i, i);


	// A ki�r�s (operator<<) �s az at() f�ggv�ny tesztel�se
	cout << v1 << endl;
	// Elv�rt kimenet: 0 1 2 3 4 5 6 7 8 9

	// M�sol� konstruktor
	Vector<int> v2(v1); // Lehetne: Vector v2=v1;

	// operator=
	Vector<int> v3;
	v3 = v2;

	// Megv�ltoztatjuk v1-t (erase tesztel�se)
	v1.erase(0);

	// v1.erase(9); // false

	cout << endl << v1 << endl << v2 << endl << v3 << endl;
	// Elv�rt kimenet:
	// 1 2 3 4 5 6 7 8 9
	// 0 1 2 3 4 5 6 7 8 9
	// 0 1 2 3 4 5 6 7 8 9

	v2.insert(0, -1);
	cout << endl << v2 << endl;
	// Elv�rt kimenet: -1 0 1 2 3 4 5 6 7 8 9

	v2.insert(10, -1);
	cout << endl << v2 << endl;
	// Elv�rt kimenet: -1 0 1 2 3 4 5 6 7 8 -1 9

	v2.insert(12, -1);
	cout << endl << v2 << endl;
	// Elv�rt kiment: -1 0 1 2 3 4 5 6 7 8 -1 9 -1

	v2.insert(15, -1);
	cout << endl << v2 << endl;
	// Elv�rt kimenet: -1 0 1 2 3 4 5 6 7 8 -1 9 -1 0 0 -1

	v2[15] = -2;
	cout << endl << v2 << endl;
	// Elv�rt kimenet: -1 0 1 2 3 4 5 6 7 8 -1 9 -1 0 0 -2
}
