#pragma once
#include <iostream>
class Partner
{
protected:
	char privateKey[2001];
	long id;
	static long nextId;
public:
	Partner();
	~Partner();
	Partner(const Partner&);
	long getId() const;
	const char* getPrivateKey() const;
	void generatePrivateKey();
	friend std::ostream& operator<<(std::ostream& os, const Partner& p);
	//friend std::ostream& operator<<(std::ostream&, const Partner&);
};

