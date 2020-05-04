#include <iostream>
#include "string.h"

using namespace std;
using namespace TheUltimateString;

void stringTest()
{
	cout << "=== STRING TEST ===" << endl;

	//String str1 = "Hello Moneypenny."; // Ez ne működjön
	String str1("Hello Moneypenny.");

	cout << "Indexing: " << str1[1] << endl;

	cout << str1 << endl;
	cout << static_cast<const char*>(str1) << endl;

	//str1 = "My name is Bond. "; // Ez ne működjön
	//str1 += "James Bond."; // Ez ne működjön

	str1 = static_cast<String>("My name is Bond. ");
	str1 += static_cast<String>("James Bond.");

	cout << static_cast<const char*>(str1) <<endl;

	if (str1 == static_cast<String>("My name is Bond. James Bond.") &&
	  !(str1 != String("My name is Bond. James Bond.")) &&
	    str1 == (String)"My name is Bond. James Bond.")
		cout << "Oh, Mr. Bond!" << endl;
}

