#pragma once
#include "Equipment.h"
class Printer :
	public Equipment
{
private:
	unsigned cartridgePrice;
public:
	Printer(unsigned _serialNumber = 0, unsigned _price = 0, unsigned _cartridgeprice = 0);
	unsigned getCartridgePrice() const { return cartridgePrice; }
	void setCartridgePrice(unsigned _cartridgePrice) { cartridgePrice = _cartridgePrice; }
	~Printer();
	void print() const;
};

