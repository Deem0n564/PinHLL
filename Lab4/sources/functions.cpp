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

void allocPerson(Person*** arr, int count) 
{
	int newSize = count + 1;

	Person** newArr = new Person * [newSize];

	if (*arr != nullptr) 
	{
		for (int i = 0; i < count; ++i) 
		{
			newArr[i] = (*arr)[i];
		}

		delete[] * arr;
	}

	newArr[count] = nullptr;

	*arr = newArr;
}

void menu(Person*** people, int& count, int& choice) 
{
    switch (choice)
    {
    case 1:
    {
        std::cout << " Enter name: ";
        std::string name;
        std::getline(std::cin, name);

        if (name.empty())
        {
            std::getline(std::cin, name);
        }

        std::cout << " Enter age: ";
        int age = getInputInt();
        allocPerson(people, count);
        (*people)[count] = new Girl(name, age);
        std::cout << " Added girl #" << count << " (" << name << ")\n";
        ++count;

        break;
    }

    case 2:
    {
        std::cout << " Enter name: ";
        std::string name;
        std::getline(std::cin, name);

        if (name.empty())
        {
            std::getline(std::cin, name);
        }

        std::cout << " Enter age: ";
        int age = getInputInt();
        allocPerson(people, count);
        (*people)[count] = new Man(name, age);
        std::cout << " Added man #" << count << " (" << name << ")\n";
        ++count;

        break;
    }

    case 3:
    {
        if (count == 0)
        {
            std::cout << " List is empty(\n";
        }

        else
        {
            std::cout << " People list:\n";

            for (int i = 0; i < count; ++i)
            {
                std::cout << i << ": " << (*people)[i]->getName()
                    << ", " << (*people)[i]->getAge() << " years\n";
            }
        }

        break;
    }

    case 4:
    {
        if (count < 2)
        {
            std::cout << " Need at least 2 people(\n";

            break;
        }

        std::cout << " Who sees (index): ";
        int a = getInputInt();
        std::cout << " Who is seen (index): ";
        int b = getInputInt();

        if (a == b)
        {
            std::cout << " Cannot react to oneself(\n";
        }

        else
        {
            (*people)[a]->reactTo(*(*people)[b]);
        }

        break;
    }

    case 5:
    {
        if (count == 0)
        {
            std::cout << " List is empty(\n";

            break;
        }

        std::cout << " Index to delete: ";
        int idx = getInputInt();
        delete (*people)[idx];

        for (int i = idx; i < count - 1; ++i)
        {
            (*people)[i] = (*people)[i + 1];
        }

        --count;

        std::cout << " Deleted.\n";

        break;
    }

    case 6:
    {
        for (int i = 0; i < count; ++i)
        {
            delete (*people)[i];
        }

        delete[] * people;
        *people = nullptr;
        count = 0;

        std::cout << " Cleared all.\n";

        break;
    }

    case 0:
    {
        break;
    }

    default:
    {
        break;
    }
    }
}