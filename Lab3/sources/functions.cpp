#include "functions.h"

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

void menu(int* numS, int* numE, Student** s, Employee** e)
{
	int choise;
	int studentOrEmployee;

	do
	{
		std::cout << "\tMENU\n 1. Add person\n 2. Print persons\n 3. Exit\n Your choise is: ";

		choise = getInputInt();

		switch (choise)
		{
		case 1:
			do
			{
				std::cout << " 1 -- to enter student, 2 to enter employee. ";

				studentOrEmployee = getInputInt();

				if (studentOrEmployee == 1)
				{
					(*numS)++;
					*s = new Student[*numS];

				}

				else if (studentOrEmployee == 2)
				{
					(*numE)++;
					*e = new Employee[*numE];
				}

				else
				{
					std::cout << " Incorrect input! Try again.\n";
				}
			} while (studentOrEmployee < 1 || studentOrEmployee > 2);

			break;

		case 2:
			if (!(*s) && !(*e))
			{
				std::cout << " There's no students or employees added.\n";
			}

			for (int i = 0; i < *numS; i++)
			{
				(*s)[i].print();
			}

			for (int i = 0; i < *numE; i++)
			{
				(*e)[i].print();
			}

			break;

		case 3:
				delete[] *s;
				delete[] * e;
			
			break;

		default:
			std::cout << " Incorrect! Please, try again\n";

			break;
		}

	} while (choise != 3);
}