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
            std::cout << "Incorrect! Please enter a valid integer: ";
        }
    }
}

void addLeft(Deque<int>& deque) {
    std::cout << "Enter value to add to left: ";
    int value = getInputInt();
    deque.push_front(value);
    std::cout << "Element " << value << " added to left.\n";
    printDequeInfo(deque);
}

void addRight(Deque<int>& deque) {
    std::cout << "Enter value to add to right: ";
    int value = getInputInt();
    deque.push_back(value);
    std::cout << "Element " << value << " added to right.\n";
    printDequeInfo(deque);
}

void removeLeft(Deque<int>& deque) {
    if (deque.empty()) {
        std::cout << "Deque is empty!\n";
    }
    else {
        int frontValue = deque.get_front();
        deque.pop_front();
        std::cout << "Element " << frontValue << " removed from left.\n";
        printDequeInfo(deque);
    }
}

void removeRight(Deque<int>& deque) {
    if (deque.empty()) {
        std::cout << "Deque is empty!\n";
    }
    else {
        int backValue = deque.get_back();
        deque.pop_back();
        std::cout << "Element " << backValue << " removed from right.\n";
        printDequeInfo(deque);
    }
}

void clear(Deque<int>& deque) {
    if (deque.empty()) {
        std::cout << "Deque is empty.\n";
    }
    else {
        deque.clear();
        std::cout << "Deque cleared.\n";
        printDequeInfo(deque);
    }
}

void search(Deque<int>& deque) {
    if (deque.empty()) {
        std::cout << "Deque is empty!\n";
        return;
    }

    std::cout << "Enter value to search: ";
    int value = getInputInt();

    auto result = DequeAlgorithm<int>::linear_search(deque, value);

    if (result != deque.end()) {
        std::cout << "Element " << value << " found in deque.\n";

        int position = 0;
        for (auto it = deque.begin(); it != deque.end(); ++it) {
            if (it == result) {
                break;
            }
            position++;
        }

        std::cout << "Element position (starting from 0): " << position << std::endl;
    }
    else {
        std::cout << "Element " << value << " not found in deque.\n";
    }
}

void sort(Deque<int>& deque) {
    if (deque.empty()) {
        std::cout << "Deque is empty!\n";
        return;
    }

    if (deque.size() == 1) {
        std::cout << "Deque has only one element.\n";
        printDequeInfo(deque);
        return;
    }

    std::cout << "Deque before sorting: ";
    deque.print();

    DequeAlgorithm<int>::insertion_sort(deque);

    std::cout << "Deque after insertion sort: ";
    deque.print();
}

void reversePrint(Deque<int>& deque) {
    if (deque.empty()) {
        std::cout << "Deque is empty.\n";
    }
    else {
        std::cout << "Reverse deque: ";
        deque.print_reverse();
    }
}