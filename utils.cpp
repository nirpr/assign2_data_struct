#include "utils.h"
using namespace std;

//The function operate the adt function base on the user choice
void chooseAction(newADT& adt, char c)
{
	switch(c) {
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
		case 'f': {
			int priority;
			string value;
			cin >> priority;
			getline(cin, value);
			Pair item;
			item.priority = priority;
			item.data = value;
			adt.Insert(item);
			break;
		}
		default:
			breakProgram();
			break;
	}
}

void breakProgram()
{
	cout << "wrong input";
	exit(1);
}

void endInputHandler()
{
	char input;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get(input);
	if (input != '\n')
		breakProgram();

}
