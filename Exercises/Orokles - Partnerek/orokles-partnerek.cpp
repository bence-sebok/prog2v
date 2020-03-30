/*
    Öröklés első gyakorló feladata: Partner ősosztály + Magányszemély és Vállalkozás leszármazottak
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ------------------------------------------------------------------
// Partner
// ------------------------------------------------------------------
class Partner {
  protected: // protected: leszármazott osztályokban még elérjük őket
    char privateKey[2001];
    long id;
    static long nextId;
  public:
    Partner();
    long getId() const;
};

long Partner::nextId = 0;

Partner::Partner() {
    id = nextId;
    nextId++;
    cout << "Partner konstruktor: " << id << endl;
}

long Partner::getId() const {
    return id;
}
// ------------------------------------------------------------------
// Partner vége
// ------------------------------------------------------------------

// ------------------------------------------------------------------
// Maganszemely
// ------------------------------------------------------------------
class Maganszemely : public Partner {
    private:
        string firstName;
        string lastName;
        string taxNumber;
    public:
        // Leszármazott konstruktorában az ősosztály konstruktorát inic. listán hívjuk!
        Maganszemely(string fN, string lN): Partner(), firstName(fN), lastName(lN)
        {
            cout << "Maganszemely konstruktor" << endl;
            // Partner::id ez egy long típus
            string tN = to_string(Partner::id); // id: 2 --> tN: "2"
            // tN egy string típus, aminek értéke a long -> string konverzió után egy string
            taxNumber = tN;
        }
        string getFirstName() const {
            return firstName;
        }
        string getLastName() const {
            return lastName;
        }
        string getTaxNumber() const {
            return taxNumber;
        }
};
// ------------------------------------------------------------------
// Maganszemely vége
// ------------------------------------------------------------------

// ------------------------------------------------------------------
// Vallalkozas
// ------------------------------------------------------------------
class Vallalkozas : public Partner {
    private:
        string businessName;
        string VATIN;
    public:
        // Leszármazott konstruktorában az ősosztály konstruktorát inic. listán hívjuk!
        Vallalkozas(string bN): Partner(), businessName(bN)
        {
            cout << "Vallalkozas konstruktor" << endl;
            VATIN = to_string(Partner::id * 1000);
        }
        string getBusinessName() const
        {
            return businessName;
        }
        string getVATIN() const
        {
            return VATIN;
        }
};
// ------------------------------------------------------------------
// Vallalkozas vége
// ------------------------------------------------------------------

// ------------------------------------------------------------------
// main függvény: osztályok tesztelése
// ------------------------------------------------------------------
int main()
{
    // Partner osztály tesztelése
    Partner p; // id: 0
    Partner p2; // id: 1
    Partner p3; // id: 2
    cout << "p2 id: " << p2.getId() << endl; // p2 id: 1

    // Magánszemély osztály tesztelése
    Maganszemely m("Bence", "Sebők"); // id: 3
    cout << m.getFirstName() << " " << m.getLastName() << endl; // Bence Sebők
    cout << "Maganszemely taxNumber: " << m.getTaxNumber() << endl;// 3
    
    // Vállalkozás osztály tesztelése
    Vallalkozas v("Bence Kft."); // id: 4
    cout << v.getBusinessName() << endl; // Bence Kft.
    cout << "Vallalkozas VATIN: " << v.getVATIN() << endl; // 4000 (4 * 1000)
}
