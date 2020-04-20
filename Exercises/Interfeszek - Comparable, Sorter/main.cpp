#include <iostream>
#include "Person.h"
#include "Sorter.h"

using namespace std;

int main()
{
    // Példa személyek létrehozása
    Person * people[10];
    for(int i = 0; i < 10; i ++)
    {
        people[i] = new Person((unsigned int)20-i);
    }
    // Egyes életkorok: 20-i, ha i 0...20, akkor ez csökkenő életkorok szerint hozza létre őket
    // Rendezettlen tömb
    cout << "Unsorted people: ";
    for(int i = 0; i < 10; i ++)
    {
        cout << people[i]->getAge() << " ";
    }
    cout << endl;

    // Rendezés
    cout << "Sorting..." << endl;
    Sorter::bubbleSort((Comparable**)people, 10);

    // Növekvő életkor szerint rendezett személyek
    cout << "Sorted people: ";
    for(int i = 0; i < 10; i ++)
    {
        cout << people[i]->getAge() << " ";
    }

    // Takarítás
    for(int i = 10; i < 20; i++)
    {
        delete people[i];
    }
    return 0;
}
