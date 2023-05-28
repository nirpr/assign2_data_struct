#include "newADT.h"
#include <iostream>
using namespace std;

void chooseAction(newADT& adt, char c, Pair item);


int main()
{
	int numberOfActs;
	cin >> numberOfActs;
	if (numberOfActs < 1)
	{
		cout << "wrong input";
		exit(1);
	}

	char ch;
	cin >> ch;
	if (ch != 'e')
	{
		cout << "wrong input";
		exit(1);
	}
	newADT adt;
	string input;
	for (int i = 1; i < numberOfActs; i++)
	{
		int priority;
		string value;
		cin >> ch >> priority;
		std::getline(std::cin, value);
		Pair item;
		item.priority = priority;
		item.data = value;
		chooseAction(adt, ch, item);
	}


	return 0;
}

void chooseAction(newADT& adt, char c, Pair item)
{
	switch (c) {
	case 'a':
		adt.Max();
		break;
	case 'b':
		adt.DeleteMax();
		break;
	case 'c':
		adt.Min();
		break;
	case 'd':
		adt.DeleteMin();
		break;
	case 'f':
		adt.Insert(item);
		break;
	case 'g':
		adt.Median();
		break;
	default:
		cout << "wrong input";
		exit(1);
	}
}


