#pragma once
class Equipment
{
private:
	unsigned serialNumber;
	unsigned price;
public:
	Equipment(unsigned _serialNumber, unsigned _price) : serialNumber(_serialNumber), price(_price) {};
	// Getterek:
	unsigned getSerialNumber() const { return serialNumber; }
	unsigned getPrice() const { return price; }
	// Setterek:
	void setSerialNumber(unsigned _serialNumber) { serialNumber = _serialNumber; }
	void setPrice(unsigned _price) { price = _price; }
	~Equipment();
	// TODO: print
	virtual void print() const = 0; // Tisztán virtuális függvény --> Absztrakt osztály --> Nem leht példányosítani
};

