#include "utils.h"
using namespace std;

//The function operate the adt function base on the user choice
void chooseAction(newADT& adt, char c)
{
	// the function matches a certain function to the c parameter it gets.
	switch(c) {
		case 'a':
			checkInput();
			adt.Max();
			break;
		case 'b':
			checkInput();
			adt.DeleteMax();
			break;
		case 'c':
			checkInput();
			adt.Min();
			break;
		case 'd':
			checkInput();
			adt.DeleteMin();
			break;
		case 'g':
			checkInput();
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
	cin.get(input);
	if (input != '\n')
		breakProgram();

}

void checkAllocation(Pair* ptr)
{
	if (ptr == nullptr)
	{
		printf("Allocation Error!");
		exit(1); // exit from the program
	}
}

void checkInput()
{
	// check if the input is valid.
	char ch;
	if (cin.get(ch) && ch != '\n')
		breakProgram();
}
