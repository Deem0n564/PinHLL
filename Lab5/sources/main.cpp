#include "functions.h"

int main()
{
	int chosenType;

	std::cout << "\tLab5\n";
	
	do
	{
		std::cout << "\n\tMain MENU\n Select the type that you want to work with:\n"
			<< " 1. Char\n"
			<< " 2. Int\n"
			<< " 3. Float\n"
			<< " 4. Double\n"
			<< " 0. EXIT\n"
			<< " Your choice is: ";

		chosenType = getInputInt();

		startMenu(chosenType);
	}

	while (chosenType != 0);

	std::cout << "\n 0. EXIT...\n";

	return 0;
}