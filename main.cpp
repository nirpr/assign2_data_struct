#include "newADT.h"
#include <iostream>
using namespace std;

void chooseAction(newADT& adt, char c);


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
		cin >> ch;
		if (ch == 'f')
		{
			int priority;
			string value;
			cin >> priority;
			std::getline(std::cin, value);
			Pair item;
			item.priority = priority;
			item.data = value;
			adt.Insert(item);
		}
		else
			chooseAction(adt, ch); // with mama first example the problem is with median(probably before but noticed than)
	}


	return 0;
}

void chooseAction(newADT& adt, char c)
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
	case 'g':
		adt.Median();
		break;
	default:
		cout << "wrong input";
		exit(1);
	}
}



