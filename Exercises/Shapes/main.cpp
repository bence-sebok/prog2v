#include <stdio.h>
#include "boundingcircle.h"

int main()
{
	// -------------------------------------------------------------------------------
	printf("Rectangle class:\n");
	Rectangle r1; // Alapértelmezett paraméterű konstruktor
	Rectangle r2(4); // Egyparaméterű konstruktor (négyzet)
	Rectangle r3(2, 5); // Kétparaméterű konstruktor (Különböző oldaú téglalap)
	// Téglalapok kiírása
	r1.print(); // a és b oldal is 0.0
	r2.print(); // a és b oldal is 4.0
	r3.print(); // a oldal 2.0, b oldal 5.0
	// Területek kiszámítása
	printf("Area of r1 = %.2lf\n", r1.getArea()); // r1 területe: 0.0
	printf("Area of r2 = %.2lf\n", r2.getArea()); // r2 területe: 16.0
	printf("Area of r3 = %.2lf\n", r3.getArea()); // r3 területe 10.0
	// Kerületek kiszámítása
	printf("Perimeter of r1 = %.2lf\n", r1.getPerimeter()); // r1 kerülete: 0.0
	printf("Perimeter of r2 = %.2lf\n", r2.getPerimeter()); // r2 kerülete: 16.0
	printf("Perimeter of r3 = %.2lf\n", r3.getPerimeter()); // r3 kerülete: 14.0
	// Setterek és getterek együttes használata
	r3.seta(r2.geta()); // r3 a oldala legyen akkora, mint r2 a oldala
	r3.setb(r2.getb()); // r3 b oldala legyen akkora, mint r2 b oldala
	r3.print(); // r3 mindkét oldala most már 4.0
	printf("Area of r3 = %.2lf\n", r3.getArea()); // Új területe: 16.0
	printf("Perimeter of r3 = %.2lf\n", r3.getPerimeter()); // Új kerülete: 16.0
	// -------------------------------------------------------------------------------
	printf("\Circle class:\n");
	Circle c1; // Alapértelmezett paraméterű konstruktor
	Circle c2(10); // Egyparaméterű konstruktor
	// Körök kiírása
	c1.print(); // c1 sugara: 0.0
	c2.print(); // c2 sugara: 10.0
	// Területek kiszámítása
	printf("Area of c1 = %.2lf\n", c1.getArea()); // c1 területe: 0.0
	printf("Area of c2 = %.2lf\n", c2.getArea()); // c2 területe: 314.16
	// Kerületek kiszámítása
	printf("Circumference of c1 = %.2lf\n", c1.getCircumference()); // c1 kerülete: 0.0
	printf("Circumference of c2 = %.2lf\n", c2.getCircumference()); // c2 kerülete: 62.83
	// Sugár megváltoztatása
	c1.setr(c2.getr()); // c1 sugara legyen annyi, mint c2 sugara
	// Módosult c1 kiíratása
	c1.print();
	// Módosult c1 adatainak kiíratása
	printf("Radius of c1 = %.2lf\n", c1.getr()); // c1 sugara: 10.0
	printf("Area of c1 = %.2lf\n", c1.getArea()); // c1 területe: 314.16
	printf("Circumference of c1 = %.2lf\n", c1.getCircumference()); // c1 kerülete: 62.83
	// -------------------------------------------------------------------------------
	printf("\BoundingCircle class:\n");
	BoundingCircle b1; // Alapértelmezett paraméterű konstruktor
	BoundingCircle b2(10); // Egyparaméterű konstruktor
	// Kiíratás
	b1.print();
	b2.print();
	// Területek és kerületek számítása és kiíratása
	printf("Area of c1=%.2lf\n", b1.getArea());
	printf("Area of c2=%.2lf\n", b2.getArea());
	printf("Perimeter of c1=%.2lf\n", b1.getPerimeter());
	printf("Perimeter of c2=%.2lf\n", b2.getPerimeter());
	// Részegységek kiíratása
	b1.getInnerSquare().print();
	b1.getOuterCircle().print();
	// -------------------------------------------------------------------------------
	return 0;
}