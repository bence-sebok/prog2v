#include <string>
#include <iostream>
#include "vector.hpp"

using namespace std;

int main()
{
	Vector<int> v;
	Vector<char> v2;
	// int
	for (int i = 0; i < 10; i++)
	{
		v.insert(i, i);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << v[i] << " ";
	}
	// char
	for (int i = 0; i < 10; i++)
	{
		v2.insert(i, i + 'a');
	}
	for (int i = 0; i < 10; i++)
	{
		cout << v2[i] << " ";
	}
	return 0;
}
