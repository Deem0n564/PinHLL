#include "Object.h"
#include "functions.h"

int Object::getSerialNumber() const
{
	return serialNumber;
}

int checkInputInt()
{
	int input;

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

void addObject(Object*& obj, int& size)
{
	Object* temp;

	Object::quantity++;
	temp = new Object[size + 1];

	for (int i = 0; i < size; i++)
	{
		temp[i] = obj[i];
	}

	delete[] obj;
	obj = temp;
	size++;

	std::cout << " Added object with serial number = " << obj[size - 1].getSerialNumber() << "\n";

}

void printObjects(const Object *obj, const int* size)
{
	for (int i = 0; i < *size; i++)
	{
		std::cout << " My serial number is " << obj[i].getSerialNumber() << "\n";
	}
}
