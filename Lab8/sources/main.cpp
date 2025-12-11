#include <iostream>
#include "functions.h"
#include "Deque.h"

int main()
{
    Deque<int> deque;
    int choice;

    std::cout << "\tLab 8\n";

    while (true)
    {
        std::cout << "\n\tMENU\n"
            << " 1. Add element to left (pushFront)\n"
            << " 2. Add element to right (pushBack)\n"
            << " 3. Remove one element from left (popFront)\n"
            << " 4. Remove one element from right (popBack)\n"
            << " 5. Clear all\n"
            << " 6. Search for element\n"
            << " 7. Sort deque (insertion sort)\n"
            << " 8. Show deque info\n"
            << " 9. Print deque in reverse order\n"
            << " 0. EXIT\n"
            << " Your choice is: ";

        choice = getInputInt();

        try
        {
            switch (choice)
            {
            case 1:
            {
                addLeft(deque);

                break;
            }
            case 2:
            {
                addRight(deque);

                break;
            }
            case 3:
            {
                removeLeft(deque);

                break;
            }
            case 4:
            {
                removeRight(deque);

                break;
            }
            case 5:
            {
                clear(deque);

                break;
            }
            case 6:
            {
                search(deque);

                break;
            }
            case 7:
            {
                sort(deque);

                break;
            }
            case 8:
            {
                printDequeInfo(deque);

                break;
            }
            case 9:
            {
                reversePrint(deque);

                break;
            }
            case 0:
            {
                std::cout << "\n EXIT...\n";

                return 0;
            }
            default:
            {
                std::cout << " Invalid choice! Please enter 0 to 9.\n";

                break;
            }
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << " Error: " << e.what() << "\n";
        }
    }
}