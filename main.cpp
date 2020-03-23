#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const char * filename = "input_file.txt"; // Bemeneti fajl neve
char delimiter = ' '; // Sorközi elválasztó karakter a különböző logikai egységek között

class Passive
{
protected:
    char scale;
public:
    Passive(char s): scale(s) {}
    virtual void print(void) const = 0;
};

class Resistor : public Passive
{
private:
    int resistance;
public:
    Resistor(char scale, int value): Passive(scale), resistance(value) {}
    void print(void) const
    {
        cout << "Resistor " << resistance << scale << "Ohm" << endl;
    }
};

class Capacitor : public Passive
{
private:
    int capacitance;
public:
    Capacitor(char scale, int value): Passive(scale), capacitance(value) {}
    void print(void) const
    {
        cout << "Capacitor " << capacitance << scale << "C" << endl;
    }
};

class Inductor : public Passive
{
private:
    int inductance;
public:
    Inductor(char scale, int value): Passive(scale), inductance(value) {}
    void print(void) const
    {
        cout << "Inductor " << inductance << scale << "H" << endl;
    }
};

Passive* processLine(std::string line)
{
    std::string substring;
    size_t length = line.length();
    Passive* passive = NULL;
    cout << "Processing line: [" << line << "] with length: " << length << endl;
    for(int i = 0; i < length; i++)
    {
        //cout << "Char at " << i << ": [" << line[i] << "]" << endl;
        if(line[i] != ' ')
        {
            //cout << "Append char to substring: [" << line[i] << "]" << endl;
            substring.push_back(line[i]);
            //cout << "Actual substring: [" << substring << "]" << endl;
        }

        if(line[i] == ' ' || i == length - 1)
        {
            cout << "Substring: [" << substring << "]" << endl;
            if(substring == "RES")
            {
                passive = new Resistor('M', 1);
            }
            else if(substring == "CAP")
            {
                passive = new Capacitor('n', 100);
            }
            else if(substring == "IND")
            {
                passive = new Inductor('m', 15);
            }
            substring.erase();
        }
    }
    return passive;
}

int main()
{
    string line; // Egyetlen sor a fájlból beolvasva
    size_t position = 0; // Sztring feldolgozásához index változó
    std::string token; // Részstring a soron belüli sztringekhez
   ifstream input_file; // Bemeneti fájl objektum
   input_file.open(filename); // Fajl megnyitasa olvasasra
   Passive * passives[10];
   Passive * p;
   int elements = 0;

   cout << "Reading from file: " << filename << endl; // Információ a felhasználó felé
   while(getline(input_file, line))
   {
       p = processLine(line);
       if(p != NULL)
       {
           passives[elements] = p;
           elements++;
       }
   }

   input_file.close(); // Megnyitott fajl lezarasa

   cout << "Passives:" << endl;
   for(int i = 0; i < elements; i++)
   {
       passives[i]->print();
   }

   return 0;
}
