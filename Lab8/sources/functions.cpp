#include "functions.h"
#include <iostream>
#include "Deque.h"

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

template <typename T>
void printDequeInfo(const Deque<T>& deque)
{
    std::cout << "\n Current deque state:\n";
    std::cout << " Size: " << deque.size() << "\n";

    if (!deque.empty())
    {
        std::cout << " First element: " << deque.getFront() << "\n";
        std::cout << " Last element: " << deque.getBack() << "\n";
        std::cout << " Contents: ";
        deque.print();
    }
    else
    {
        std::cout << " Deque is empty.\n";
    }
}

void addLeft(Deque<int>& deque)
{
    std::cout << " Enter value to add to left: ";
    int value = getInputInt();
    deque.pushFront(value);
    std::cout << " Element " << value << " added to left.\n";
    printDequeInfo(deque);
}

void addRight(Deque<int>& deque)
{
    std::cout << " Enter value to add to right: ";
    int value = getInputInt();
    deque.pushBack(value);
    std::cout << " Element " << value << " added to right.\n";
    printDequeInfo(deque);
}

void removeLeft(Deque<int>& deque)
{
    if (deque.empty())
    {
        std::cout << " Deque is empty!\n";
    }
    else
    {
        int frontValue = deque.getFront();
        deque.popFront();
        std::cout << " Element " << frontValue << " removed from left.\n";
        printDequeInfo(deque);
    }
}

void removeRight(Deque<int>& deque)
{
    if (deque.empty())
    {
        std::cout << " Deque is empty!\n";
    }
    else
    {
        int backValue = deque.getBack();
        deque.popBack();
        std::cout << " Element " << backValue << " removed from right.\n";
        printDequeInfo(deque);
    }
}

void clear(Deque<int>& deque)
{
    if (deque.empty())
    {
        std::cout << " Deque is empty.\n";
    }
    else
    {
        deque.clear();
        std::cout << "Deque cleared.\n";
        printDequeInfo(deque);
    }
}

void search(Deque<int>& deque)
{
    if (deque.empty())
    {
        std::cout << " Deque is empty!\n";

        return;
    }

    std::cout << " Enter value to search: ";
    int value = getInputInt();

    auto result = DequeAlgorithm<int>::linearSearch(deque, value);

    if (result != deque.end())
    {
        std::cout << " Element " << value << " found in deque.\n";

        int position = 0;

        for (auto it = deque.begin(); it != deque.end(); ++it)
        {
            if (it == result)
            {
                break;
            }

            position++;
        }

        std::cout << " Element position (starting from 0): " << position << "\n";
    }
    else
    {
        std::cout << " Element " << value << " not found in deque.\n";
    }
}

void sort(Deque<int>& deque)
{
    if (deque.empty())
    {
        std::cout << " Deque is empty!\n";

        return;
    }

    if (deque.size() == 1)
    {
        std::cout << " Deque has only one element.\n";
        printDequeInfo(deque);

        return;
    }

    std::cout << " Deque before sorting: ";
    deque.print();

    DequeAlgorithm<int>::insertSort(deque);

    std::cout << " Deque after insertion sort: ";
    deque.print();
}

void reversePrint(const Deque<int>& deque)
{
    if (deque.empty())
    {
        std::cout << " Deque is empty.\n";
    }
    else
    {
        std::cout << " Reverse deque: ";
        deque.printReverse();
    }
}