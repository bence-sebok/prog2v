#include "rectangle.h"
#include <stdio.h>

// Paraméter nélküli / négyzet konstruktor
Rectangle::Rectangle(double a): a(a), b(a) {}
// 2 paraméterű konstruktor
Rectangle::Rectangle(double a, double b): a(a), b(b) {}
// Setter: egyik oldal (a)
void Rectangle::seta(double a)
{
	// Csak értelmes értékre lehessen beállítani!
	if(a >= 0)
	{
		this->a = a;
	}
}
// Setter: másik oldal (b)
void Rectangle::setb(double b)
{
	// Csak értelmes értékre lehessen beállítani!
	if (b >= 0)
	{
		this->b = b;
	}
}
// Terület számító függvény
double Rectangle::getArea() const
{
	return (a * b);
}
// Kerület számító függvény
double Rectangle::getPerimeter() const
{
	return (2 * (a + b));
}
// Kiíró függvény
void Rectangle::print()
{
	printf("a = %.2lf, b = %.2lf\n", a, b);
}