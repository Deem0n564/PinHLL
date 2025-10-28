#include "functions.h"

void startMenu(int chosenType)
{
	int choice;

	switch (chosenType)
	{
	case 1:
	{
		char* arr = nullptr;
		int size = 0;

		std::cout << "\n 1. Char.\n";

		do
		{
			std::cout << "\n\tChar MENU\n"
				<< " 1. Add char.\n"
				<< " 2. Print.\n"
				<< " 3. Find by key.\n"
				<< " 0. EXIT to Main MENU.\n"
				<< " Your choice is: ";

			choice = getInputInt();

			charMenu(choice, &size, &arr);
		}

		while (choice != 0);

		std::cout << "\n 0. EXIT to Main MENU.\n";

		break;
	}

	case 2:
	{
		int size = 0;
		int* arr = nullptr;

		std::cout << "\n 2. Int.\n";

		do
		{
			std::cout << "\n\tInt MENU\n"
				<< " 1. Add int.\n"
				<< " 2. Print.\n"
				<< " 3. Find by key.\n"
				<< " 0. EXIT to Main MENU.\n"
				<< " Your choice is: ";

			choice = getInputInt();

			intMenu(choice, &size, &arr);
		}

		while (choice != 0);

		std::cout << "\n 0. EXIT to Main MENU.\n";

		break;
	}

	case 3:
	{
		int size = 0;
		float* arr = nullptr;

		std::cout << "\n 3. Float.\n";

		do
		{
			std::cout << "\n\tFloat MENU\n"
				<< " 1. Add float.\n"
				<< " 2. Print.\n"
				<< " 3. Find by key.\n"
				<< " 0. EXIT to Main MENU.\n"
				<< " Your choice is: ";

			choice = getInputInt();

			floatMenu(choice, &size, &arr);
		}

		while (choice != 0);

		std::cout << "\n 0. EXIT to Main MENU.\n";

		break;
	}

	case 4:
	{
		int size = 0;
		double* arr = nullptr;

		std::cout << "\n 4. Double.\n";

		do
		{
			std::cout << "\n\tDouble MENU\n"
				<< " 1. Add double.\n"
				<< " 2. Print.\n"
				<< " 3. Find by key.\n"
				<< " 0. EXIT to Main MENU.\n"
				<< " Your choice is: ";

			choice = getInputInt();

			doubleMenu(choice, &size, &arr);
		}

		while (choice != 0);

		std::cout << "\n 0. EXIT to Main MENU.\n";

		break;
	}

	case 0:
	{
		break;
	}

	default:
	{
		std::cout << "\n Incorrect choice( -- please, try again...\n";

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

float getInputFloat()
{
	float input = 0;

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

			std::cout << " Incorrect! Please enter a valid float: ";
		}
	}
}

double getInputDouble()
{
	double input = 0;

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

			std::cout << " Incorrect! Please enter a valid double: ";
		}
	}
}

void charMenu(int choice, int* size, char** arr)
{
	char* temp = nullptr;
	char* newArr = nullptr;
	char key;

	switch (choice)
	{
	case 1:
	{
		std::cout << " 1. Add char:\n";

		temp = *arr;
		newArr = new char[*size + 1];

		for (int i = 0; i < *size; i++)
		{
			newArr[i] = temp[i];
		}

		newArr[*size] = getchar();
		delete[]temp;
		*arr = newArr;
		(*size)++;

			break;
	}

	case 2:
	{
		std::cout << " 2. Print:\n";

		for (int i = 0; i < *size; i++)
		{
			std::cout << " Arr[" << i
				<< "] is " << (*arr)[i] << "\n";
		}

		break;
	}

	case 3:
	{
		std::cout << " 3. Find by key:\n\n Enter key: ";

		key = getchar();

		findByKeyTemplate(*arr, *size, key);

		break;
	}

	case 0:
	{
		delete[] * arr;

		break;
	}

	default:
	{
		std::cout << "\n Incorrect choice( -- please, try again...\n";

		break;
	}
	}
}

void intMenu(int choice, int* size, int** arr)
{
	int* temp = nullptr;
	int* newArr = nullptr;
	int key;

	switch (choice)
	{
	case 1:
	{
		std::cout << " 1. Add int:\n";

		temp = *arr;
		newArr = new int[*size + 1];

		for (int i = 0; i < *size; i++)
		{
			newArr[i] = temp[i];
		}

		newArr[*size] = getInputInt();
		delete[]temp;
		*arr = newArr;
		(*size)++;

		break;
	}

	case 2:
	{
		std::cout << " 2. Print:\n";

		for (int i = 0; i < *size; i++)
		{
			std::cout << " Arr[" << i
				<< "] is " << (*arr)[i] << "\n";
		}

		break;
	}

	case 3:
	{
		std::cout << " 3. Find by key:\n\n Enter key: ";

		key = getInputInt();

		findByKeyTemplate(*arr, *size, key);

		break;
	}

	case 0:
	{
		delete[] * arr;

		break;
	}

	default:
	{
		std::cout << "\n Incorrect choice( -- please, try again...\n";

		break;
	}
	}
}

void floatMenu(int choice, int* size, float** arr)
{
	float* temp = nullptr;
	float* newArr = nullptr;
	float key;

	switch (choice)
	{
	case 1:
	{
		std::cout << " 1. Add float:\n";

		temp = *arr;
		newArr = new float[*size + 1];

		for (int i = 0; i < *size; i++)
		{
			newArr[i] = temp[i];
		}

		newArr[*size] = getInputFloat();
		delete[]temp;
		*arr = newArr;
		(*size)++;

		break;
	}

	case 2:
	{
		std::cout << " 2. Print:\n";

		for (int i = 0; i < *size; i++)
		{
			std::cout << " Arr[" << i
				<< "] is " << (*arr)[i] << "\n";
		}

		break;
	}

	case 3:
	{
		std::cout << " 3. Find by key:\n\n Enter key: ";

		key = getInputFloat();

		findByKeyTemplate(*arr, *size, key);

		break;
	}

	case 0:
	{
		delete[] * arr;

		break;
	}

	default:
	{
		std::cout << "\n Incorrect choice( -- please, try again...\n";

		break;
	}
	}
}

void doubleMenu(int choice, int* size, double** arr)
{
	double* temp = nullptr;
	double* newArr = nullptr;
	double key;

	switch (choice)
	{
	case 1:
	{
		std::cout << " 1. Add double:\n";

		temp = *arr;
		newArr = new double[*size + 1];

		for (int i = 0; i < *size; i++)
		{
			newArr[i] = temp[i];
		}

		newArr[*size] = getInputDouble();
		delete[]temp;
		*arr = newArr;
		(*size)++;

		break;
	}

	case 2:
	{
		std::cout << " 2. Print:\n";

		for (int i = 0; i < *size; i++)
		{
			std::cout << " Arr[" << i
				<< "] is " << (*arr)[i] << "\n";
		}

		break;
	}

	case 3:
	{
		std::cout << " 3. Find by key:\n\n Enter key: ";

		key = getInputDouble();

		findByKeyTemplate(*arr, *size, key);

		break;
	}

	case 0:
	{
		delete[] * arr;

		break;
	}

	default:
	{
		std::cout << "\n Incorrect choice( -- please, try again...\n";

		break;
	}
	}
}