#include "utils.h"
using namespace std;

//The function operate the adt function base on the user choice
void chooseAction(newADT& adt, char c)
{
	// the function matches a certain function to the c parameter it gets.
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
	// exit function
	cout << "wrong input";
	exit(1);
}

void endInputHandler()
{
	// a function to check if there are more inputs than the number that was provided
	char input;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get(input);
	if (input != '\n')
		breakProgram();

}
