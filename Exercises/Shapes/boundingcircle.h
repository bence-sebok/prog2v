#pragma once // Többszörös beillesztés elleni védelem (Include Guard)
#include "circle.h"
#include "math.h"
#include "rectangle.h"

class BoundingCircle
{
private:
	Rectangle innerSquare;
	Circle outerCircle;
public:
	// Egy paraméterű, alapértelmezett paraméterű konstruktor
	BoundingCircle(double = 1.0);
	// Getterek
	Rectangle getInnerSquare() const;
	Circle getOuterCircle() const;
	// Számítást végző függvények
	double getArea() const;
	double getPerimeter() const;
	// Kiíró függvény
	void print();

	// Tagfüggvények kifejtése a .cpp fájlban!
};
