#include "functions.h"

void menu(int choise)
{
	switch (choise)
	{
	case 1:
	{
		std::cout << "\n 1. \n";

		break;
	}

	case 0:
	{
		break;
	}

	default:
	{
		std::cout << "\n Incorrect choise( -- please, try again...\n";

		break;
	}
	}
}

int getInputInt()
{
	int input = 0;

	while (true)
	{
		if (std::cin >> input)
		{
			std::cin.ignore(100, '\n');

			return input;
		}

		else
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');

			std::cout << " Incorrect! Please enter a valid integer: ";
		}
	}
}