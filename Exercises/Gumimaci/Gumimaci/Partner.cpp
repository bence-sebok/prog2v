#include "stdafx.h" 
#include "Partner.h"
#include <cstdlib>
#include <iostream>

using namespace std;

// Statikus osztályszintû változó inicializálása a cpp fájl elején!
long Partner::nextId = 0;

void Partner::generatePrivateKey() {
	const char characters[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	const int charsLength = sizeof(characters) - 1; // hasznos karakterek száma
	const int keyLength = sizeof(privateKey);
	for (int i = 0; i < keyLength - 1; i++)
	{
		privateKey[i] = characters[rand() % charsLength];
		//std::cout << i << "th character: " << privateKey[i] << std::endl;
	}
	privateKey[keyLength - 1] = '\0';
}

Partner::Partner(): id(nextId) // id(nextId++)
{
	nextId++;
	generatePrivateKey();
	//cout << privateKey << endl;
}

Partner::Partner(const Partner& theOther) : id(nextId) {
	nextId++;
	generatePrivateKey();
}

long Partner::getId() const {
	return id;
}

const char* Partner::getPrivateKey() const {
	return privateKey;
}

Partner::~Partner()
{
}

std::ostream& operator<<(std::ostream& os, const Partner& p)
{
	os << "ID: " << p.getId() << std::endl << "Private key: " << p.getPrivateKey() << std::endl;
	return os; // cout << p << p2 << p3;
}