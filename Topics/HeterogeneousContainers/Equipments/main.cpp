#include <iostream>
#include "Equipment.h"
#include "Monitor.h"
#include "Printer.h"

using namespace std;

int main()
{
    cout << "Sima objektumok: " << endl;
    cout << "Equipment: " << endl;
    Equipment e(1, 1000);
    e.print();
    cout << "Monitor: " << endl;
    Monitor m(2, 1500, 3);
    m.print();
    cout << "Printer: " << endl;
    Printer p(3, 1700, 2500);
    p.print();

    // Heterogén kollekció
    Equipment* equipments[3];
    equipments[0] = &e; // ősosztály típusú objektumra mutat
    equipments[1] = &m; // leszármazott típusú (Monitor) objektumra mutat
    equipments[2] = &p; // leszármazott típusú (Printer) objektumra mutat
    cout << endl << "Heterogen kollekcio: " << endl;
    for(int i = 1; i < 3; i++)
    {
        equipments[i]->print();
    }
    return 0;
}






