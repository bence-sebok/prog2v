#include "boundingcircle.h"

// Konstruktor
BoundingCircle::BoundingCircle(double side): innerSquare(side), outerCircle(side*sqrt(2)/2) {}
// Getter: Rectangle
Rectangle BoundingCircle::getInnerSquare() const // const!
{
	return innerSquare;
}
// Getter: Circle
Circle BoundingCircle::getOuterCircle() const // const!
{
	return outerCircle;
}
// Területet számító függvény
double BoundingCircle::getArea() const // const!
{
	// Megfelelő tagfüggvények meghívása
	return (outerCircle.getArea() - innerSquare.getArea());
}
// Kerületet számító függvény
double BoundingCircle::getPerimeter() const
{
	return (innerSquare.getPerimeter() + outerCircle.getCircumference());
}
// Kiíró függvény
void BoundingCircle::print()
{
	// Felhasználó tájékoztatása + a megfelelő tagfüggvények meghívása
	printf("Inner square: ");
	innerSquare.print();
	printf("Outer circle: ");
	outerCircle.print();
}