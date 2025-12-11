#include "functions.h"

template <typename T>
void printDequeInfo(Deque<T>& deque) 
{
    std::cout << "\n Current deque state:\n";
    std::cout << " Size: " << deque.size() << std::endl;

    if (!deque.empty()) 
    {
        std::cout << " First element: " << deque.get_front() << std::endl;
        std::cout << " Last element: " << deque.get_back() << std::endl;
        std::cout << " Contents: ";
        deque.print();
    }
    else 
    {
        std::cout << "Deque is empty.\n";
    }
}

int main() 
{
    Deque<int> deque;
    int choice;
    int value;

    std::cout << "\tLab 8\n";

    while (true) 
    {
        std::cout << "\n\tMENU\n"
            << " 1. Add element to left (push_front)\n"
            << " 2. Add element to right (push_back)\n"
            << " 3. Remove one element from left (pop_front)\n"
            << " 4. Remove one element from right (pop_back)\n"
            << " 5. Remove all elements (clear)\n"
            << " 6. Search for element (linear search)\n"
            << " 7. Sort deque (insertion sort)\n"
            << " 8. Show deque information\n"
            << " 9. Print deque in reverse order\n"
            << " 0. Exit\n"
            << " Your choice is: ";

        choice = getInputInt();

        try 
        {
            switch (choice) 
            {
            case 1: 
            {
                std::cout << " Enter value to add to left: ";
                value = getInputInt();
                deque.push_front(value);
                std::cout << " Element " << value << " added to left.\n";
                printDequeInfo(deque);

                break;
            }

            case 2: 
            {
                std::cout << " Enter value to add to right: ";
                value = getInputInt();
                deque.push_back(value);
                std::cout << " Element " << value << " added to right.\n";
                printDequeInfo(deque);

                break;
            }

            case 3: 
            {
                if (deque.empty()) 
                {
                    std::cout << " Deque is empty!\n";
                }
                else 
                {
                    int frontValue = deque.get_front();
                    deque.pop_front();
                    std::cout << " Element " << frontValue << " removed from left.\n";
                    printDequeInfo(deque);
                }

                break;
            }

            case 4: 
            {
                if (deque.empty()) 
                {
                    std::cout << " Deque is empty!\n";
                }
                else 
                {
                    int backValue = deque.get_back();
                    deque.pop_back();
                    std::cout << " Element " << backValue << " removed from right.\n";
                    printDequeInfo(deque);
                }

                break;
            }

            case 5: 
            {
                if (deque.empty()) 
                {
                    std::cout << " Deque is empty.\n";
                }
                else 
                {
                    deque.clear();
                    std::cout << " Deque cleared.\n";
                    printDequeInfo(deque);
                }

                break;
            }

            case 6: 
            {
                if (deque.empty()) 
                {
                    std::cout << " Deque is empty!\n";
                }
                else 
                {
                    std::cout << " Enter value to search: ";
                    value = getInputInt();

                    auto result = DequeAlgorithm<int>::linear_search(deque, value);

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

                        std::cout << " Element position (starting from 0): " << position << std::endl;
                    }
                    else 
                    {
                        std::cout << " Element " << value << " not found in deque.\n";
                    }
                }

                break;
            }

            case 7: 
            {
                if (deque.empty()) 
                {
                    std::cout << " Deque is empty!\n";
                }

                else if (deque.size() == 1) 
                {
                    std::cout << " Deque has only one element.\n";
                    printDequeInfo(deque);
                }
                else 
                {
                    std::cout << " Deque before sorting: ";
                    deque.print();

                    DequeAlgorithm<int>::insertion_sort(deque);

                    std::cout << " Deque after insertion sort: ";
                    deque.print();
                }

                break;
            }

            case 8: 
            {
                printDequeInfo(deque);

                break;
            }

            case 9: 
            {
                if (deque.empty()) 
                {
                    std::cout << " Deque is empty.\n";
                }
                else 
                {
                    std::cout << " Reverse deque: ";
                    deque.print_reverse();
                }

                break;
            }

            case 0: 
            {
                std::cout << "\n Exiting...\n";

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