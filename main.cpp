#include "utils.h"
#include <iostream>
using namespace std;

//void chooseAction(newADT& adt, char c);


int main()
{
	int numberOfActs;
	cin >> numberOfActs;

	if (numberOfActs < 1)
		breakProgram();

	char userChoice;
	cin >> userChoice;

	if (userChoice != 'e')
		breakProgram();

	newADT adt;
	for (int i = 1; i < numberOfActs; i++)
	{
		cin >> userChoice;
		chooseAction(adt, userChoice);
	}

	endInputHandler();
	return 0;
}




