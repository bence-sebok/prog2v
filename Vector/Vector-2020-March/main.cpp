#include <iostream>
#include "Vector.h"

using namespace std; // std::cout, std::cin

int main()
{
    // Egyszerű konstruktor
    Vector v1; // default: 20
    Vector v2(50); // 50

    // Másoló konstruktor, operator=
    Vector v3 = v1; // másoló konstruktoron belüli operator=
    Vector v4(v1);  // másoló konstruktoron belüli operator=
    Vector v5;
    v5 = v1; // operator=

    // Vektorok kiírása
    // friend std::ostream& operator<<(std::ostream&, const Vector&);
    cout << "v1 Vector: " << v1 << endl;
    cout << "v2 Vector: " << v3 << endl;
    cout << "v3 Vector: " << v4 << endl;
    cout << "v4 Vector: " << v3 << endl;
    cout << "v5 Vector: " << v4 << endl;

    // Érvénytelen index
    v1[19];
    v1[-2]; // unsigned!
    return 0;
}
