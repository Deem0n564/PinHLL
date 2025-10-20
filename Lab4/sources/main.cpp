#include "functions.h"

int main()
{
	Person** people = nullptr;
	int count = 0;
	int choise;

	do
	{
		std::cout << "\tMENU\n"
			<< " 1. Add girl\n"
			<< " 2. Add man\n"
			<< " 3. Print peoples\n"
			<< " 4. *** react to ###\n"
			<< " 5. Delete person\n"
			<< " 0. Exit\n"
			<< " Your choise is: ";

		choise = getInputInt();

		menu(&people, count, choise);
	} while (choise != 0);

	for (int i = 0; i < count; ++i)
	{
		delete people[i];
	}

	delete[] people;

	std::cout << "\n Exit.\n";

	return 0;
}