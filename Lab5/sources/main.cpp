#include "functions.h"

int main()
{
	int choise;

	std::cout << "\tLab5\n";
	
	do
	{
		std::cout << "\n\tMENU\n"
			<< " 1. \n"
			<< " 0. Exit\n"
			<< " Your choise is: ";

		choise = getInputInt();

		menu(choise);
	}

	while (choise != 0);

	std::cout << "\n 0. EXIT...\n";

	return 0;
}