#pragma once // Többszörös beillesztés elleni védelem (Include Guard)

// Kör osztály
class Circle
{
private:
	double r; // kör sugara
public:
	// Konstruktor
	Circle(double = 0);
	// Setter: sugár
	void setr(double r);
	// Getter: sugár
	double getr() const { return r; }
	// Számítást végző függvények
	double getArea() const;
	double getCircumference() const;
	// Kiíró függvény
	void print();

	// Tagfüggvények kifejtése a .cpp fájlban!
};