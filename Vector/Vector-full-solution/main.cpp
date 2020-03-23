#include "Vector.h"
using namespace std;

int main()
{
	// Vector feltöltése for ciklussal
	Vector v1;
	for (int i = 1; i<10; i++)
	{
		v1.insert(i, i);
	}
	// Kiíró operátor tesztelése
	cout << v1 << endl;
	// Másoló konstruktor
	Vector v2(v1);
	// operator=
	Vector v3;
	v3 = v2;
	// törlés
	v1.erase(0);
	// 3 Vector tartalmának tesztelése
	cout << endl << v1 << endl << v2 << endl << v3 << endl;
	// insert-ek tesztelése
	v2.insert(0, -1);
	cout << v2 << endl;
	v2.insert(10, -1);
	cout << v2 << endl;
	v2.insert(12, -1);
	cout << v2 << endl;
	v2.insert(15, -1);
	cout << v2 << endl;
	// operator[]
	v2[15] = -2;
	cout << v2 << endl;
	// operator*=
	v2 *= 10;
	cout << v2 << endl;
	// Beolvasó operátor tesztelése
	Vector v4(5);
	cin >> v4;
	cout << endl << v4 << endl;
	return 0;
}