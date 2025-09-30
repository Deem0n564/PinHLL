#include "Object.h"
#include "functions.h"

int Object::quantity = 0;

int main()
{
	int choise;
	int size;
	Object *objects = nullptr;

	size = 0;

	do
	{
		std::cout << "\tMENU\n 1. Add object.\n 2. Print serial numbers.\n 3. Exit\n Your choise is: ";

		choise = checkInputInt();

		switch (choise)
		{
		case 1:
			addObject(objects, size);

			break;

		case 2:
			printObjects(objects, &size);

			break;

		case 3:
			if (objects)
			{
				delete[]objects;
			}

			objects = nullptr;

			break;

		default:
			std::cout << " Incorrect! Please, try again\n";

			break;
		}
		
	} while (choise != 3);


	return 0;
}
