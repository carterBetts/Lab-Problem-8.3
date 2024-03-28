#include <iostream>
#include <String>
#include <list>
using namespace std;

int romanCharValue(char r);
int convertRomanToInt(string s);



int main(void)
{
	cout << convertRomanToInt("X");
}

int romanCharValue(char r)
{
	switch (r)
	{
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	}
	return 0;
}

int convertRomanToInt(string s)
{
	const char* str = s.c_str();
	list <char> charecters;
	for (int i = 0; i < s.length(); i++)
		charecters.push_back(str[0]);

	int total = 0;
	while (s.length() > 0)
	{
		if ((romanCharValue(s[0]) >= romanCharValue(s[1])) || (s.length() == 1))
		{
			total += romanCharValue(s[0]);
			s.erase(0,1);
		}
		else
		{
			total += romanCharValue(s[1]) - romanCharValue(s[0]);
			s.erase(1,1);
			s.erase(0,1);
		}
	}
	return total;
}

//total = 0
//While the roman number string is not empty
//If the first character has a larger or equal value than the second,
//or the string has length 1
//Add value(first character) to total.
//Remove the character.
//Else
//Add the quantity : value(second character) - value(first character) to total.
//Remove both characters