#pragma once // Többszörös beillesztés elleni védelem (Include Guard)

// Téglalap osztály
class Rectangle
{
private:
	double a, b; // Téglalap oldalai
public:
	// Paraméter nélküli / négyzet konstruktor
	Rectangle(double = 0);
	// 2 paraméterű konstruktor
	Rectangle(double, double);
	// Setterek
	void seta(double a);
	void setb(double b);
	// Getterek
	double geta() const { return a; }; // const!
	double getb() const { return b; }; // const!
	// Számítást végző függvények
	double getArea() const; // const!
	double getPerimeter() const; // const!
	// Kiíró függvény
	void print();

	// Tagfüggvények kifejtése a .cpp fájlban!
};