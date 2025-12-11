#include <iostream>
#include "functions.h"
#include "Deque.h"

int main() {
    Deque<int> deque;
    int choice;

    std::cout << "\tLab 8\n";

    while (true) {
        std::cout << "\n\tMENU\n"
            << " 1. Add element to left (push_front)\n"
            << " 2. Add element to right (push_back)\n"
            << " 3. Remove one element from left (pop_front)\n"
            << " 4. Remove one element from right (pop_back)\n"
            << " 5. Remove all elements (clear)\n"
            << " 6. Search for element\n"
            << " 7. Sort deque (insertion sort)\n"
            << " 8. Show deque information\n"
            << " 9. Print deque in reverse order\n"
            << " 0. Exit\n"
            << " Your choice is: ";

        choice = getInputInt();

        try {
            switch (choice) {
            case 1:
                addLeft(deque);
                break;

            case 2:
                addRight(deque);
                break;

            case 3:
                removeLeft(deque);
                break;

            case 4:
                removeRight(deque);
                break;

            case 5:
                clear(deque);
                break;

            case 6:
                search(deque);
                break;

            case 7:
                sort(deque);
                break;

            case 8:
                printDequeInfo(deque);
                break;

            case 9:
                reversePrint(deque);
                break;

            case 0:
                std::cout << "\nExiting...\n";
                return 0;

            default:
                std::cout << "Invalid choice! Please enter 0 to 9.\n";
                break;
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
}