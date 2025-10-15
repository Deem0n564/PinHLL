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

float getInputFloat()
{
	float input = 0.00f;

	while (true)
	{
		if (std::cin >> input)
		{
			std::cin.ignore(100, '\n');

			return input;
		}
		std::cin.clear();
		std::cin.ignore(100, '\n');

		std::cout << " Incorrect! Please enter a valid number: ";
	}
}

void menu(int* numS, int* numE, Student** s, Employee** e)
{
	int choise;
	std::string name;
	std::string position;
	int year;
	int salary;
	float avg;

	do
	{
		std::cout << "\tMENU\n 1. Add student\n 2. Add employee\n 3. Print persons\n 4. Exit\n Your choise is: ";

		choise = getInputInt();

		switch (choise)
		{
		case 1:
		{
			std::cout << " Enter name: ";
			std::cin >> name;
			std::cout << " Enter birth year: ";
			year = getInputInt();
			std::cout << " Enter average grade: ";
			avg = getInputFloat();

			int newCount = (*numS) + 1;
			auto* tmp = new Student[newCount];

				for (int i = 0; i < *numS; ++i)
				{
					tmp[i] = (*s)[i];
				}

			tmp[newCount - 1] = Student(name, year, avg);

			delete[] * s;

			*s = tmp;
			*numS = newCount;

			break;
		}
		case 2:
		{
			std::cout << " Enter name: ";
			std::cin >> name;
			std::cout << " Enter birth year: ";
			year = getInputInt();
			std::cout << " Enter position: ";
			std::cin >> position;
			std::cout << " Enter salary: ";
			salary = getInputInt();

			int newCount = (*numE) + 1;
			auto * tmp = new Employee[newCount];

			for (int i = 0; i < *numE; ++i)
			{
				tmp[i] = (*e)[i];
			}

			tmp[newCount - 1] = Employee(name, year, position, salary);

			delete[] * e;

			*e = tmp;
			*numE = newCount;

			break;
		}

		case 3:
			printPersons(*numS, *numE, *s, *e);

			break;

		case 4:
				delete[] *s;
				delete[] *e;
			
			break;

		default:
			std::cout << " Incorrect! Please, try again\n";

			break;
		}

	} while (choise != 4);
}

void printPersons(int numS, int numE, const Student* s, const Employee* e)
{
	if (s)
	{
		for (int i = 0; i < numS; i++)
		{
			s[i].print();
		}
	}

	else
	{
		std::cout << " There's no students added.\n";
	}

	if (e)
	{

		for (int i = 0; i < numE; i++)
		{
			e[i].print();
		}
	}

	else
	{
		std::cout << " There's no employees added.\n";
	}
}