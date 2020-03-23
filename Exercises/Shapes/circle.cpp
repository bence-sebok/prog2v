#include <stdio.h>
#include "circle.h"

// Matematikai konstans a számításokhoz
const double pi = 3.14;

// Konstruktor
Circle::Circle(double r): r(r) {}
// Setter: sugár
void Circle::setr(double r)
{
	// Csak értelmes értékre lehessen beállítani!
	if(r >= 0)
	{
		this->r = r;
	}
}
// Terület számító függvény
double Circle::getArea() const
{
	return (r * r * pi);
}
// Kerület számító függvény
double Circle::getCircumference() const
{
	return (2 * r * pi);
}
// Kiíró függvény
void Circle::print()
{
	printf("r=%.2lf\n", r);
}