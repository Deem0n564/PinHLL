#include "functions.h"

// Проверка, что строка содержит только латинские буквы, пробел или дефис
bool isEnglishString(const std::string& s)
{
    if (s.empty()) return false;
    for (unsigned char ch : s)
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == ' ' || ch == '-')
            continue;
        return false;
    }
    return true;
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
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << " Неверно! Введите целое число: ";
    }
}

float getInputFloat()
{
    float input = 0.0f;
    while (true)
    {
        if (std::cin >> input)
        {
            std::cin.ignore(100, '\n');
            return input;
        }
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << " Неверно! Введите число (например 4.5): ";
    }
}

void printPersons(int numS, int numE, const Student* s, const Employee* e)
{
    if (s && numS > 0)
    {
        for (int i = 0; i < numS; ++i) s[i].print();
    }
    else
    {
        std::cout << " Нет добавленных студентов.\n";
    }

    if (e && numE > 0)
    {
        for (int i = 0; i < numE; ++i) e[i].print();
    }
    else
    {
        std::cout << " Нет добавленных сотрудников.\n";
    }
}

void addStudent(int* numS, Student** s)
{
    std::string name;
    int year;
    float avg;

    std::cout << " Enter name: ";
    std::getline(std::cin >> std::ws, name);
    if (!isEnglishString(name)) throw NotEnglishException("student name");

    std::cout << " Enter birth year: ";
    year = getInputInt();

    std::cout << " Enter average grade: ";
    avg = getInputFloat();

    int newCount = (*numS) + 1;
    Student* tmp = nullptr;

    try
    {
        tmp = new Student[newCount];
        for (int i = 0; i < *numS; ++i) tmp[i] = (*s)[i];
        tmp[newCount - 1] = Student(name, year, avg);
        delete[] * s;
        *s = tmp;
        *numS = newCount;
    }
    catch (...)
    {
        delete[] tmp;
        throw;
    }
}

void addEmployee(int* numE, Employee** e)
{
    std::string name;
    int year;
    std::string position;
    int salary;

    std::cout << " Enter name: ";
    std::getline(std::cin >> std::ws, name);
    if (!isEnglishString(name)) throw NotEnglishException("employee name");

    std::cout << " Enter birth year: ";
    year = getInputInt();

    std::cout << " Enter position: ";
    std::getline(std::cin >> std::ws, position);
    if (!isEnglishString(position)) throw NotEnglishException("position");

    std::cout << " Enter salary: ";
    salary = getInputInt();

    int newCount = (*numE) + 1;
    Employee* tmp = nullptr;

    try
    {
        tmp = new Employee[newCount];
        for (int i = 0; i < *numE; ++i) tmp[i] = (*e)[i];
        tmp[newCount - 1] = Employee(name, year, position, salary);
        delete[] * e;
        *e = tmp;
        *numE = newCount;
    }
    catch (...)
    {
        delete[] tmp;
        throw;
    }
}

void menu(int* numS, int* numE, Student** s, Employee** e)
{
    int choice = 0;
    do
    {
        std::cout << "\tMENU\n 1. Add student\n 2. Add employee\n 3. Print persons\n 4. Exit\n Your choice: ";
        choice = getInputInt();

        try
        {
            switch (choice)
            {
            case 1:
                addStudent(numS, s);
                break;
            case 2:
                addEmployee(numE, e);
                break;
            case 3:
                printPersons(*numS, *numE, *s, *e);
                break;
            case 4:
                delete[] * s;
                delete[] * e;
                break;
            default:
                std::cout << " Неверный выбор, попробуйте снова.\n";
                break;
            }
        }
        catch (const NotEnglishException& ex)
        {
            std::cout << "Input error: " << ex.what() << '\n';
        }
        catch (const std::bad_alloc&)
        {
            std::cout << " Ошибка: недостаточно памяти\n";
            delete[] * s;
            delete[] * e;
            throw; // пробрасываем дальше в main
        }
        catch (const std::exception& ex)
        {
            std::cout << " Ошибка: " << ex.what() << '\n';
        }

    } while (choice != 4);
}
