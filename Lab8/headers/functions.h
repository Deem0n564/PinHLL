#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>
#include "Node.h"
#include "DequeIterator.h"
#include "Deque.h"
#include "DequeAlgorythm.h"

int getInputInt();
void addLeft(Deque<int>& deque);
void addRight(Deque<int>& deque);
void removeLeft(Deque<int>& deque);
void removeRight(Deque<int>& deque);
void clear(Deque<int>& deque);
void search(Deque<int>& deque);
void sort(Deque<int>& deque);
void reversePrint(const Deque<int>& deque);

template <typename T>
void printDequeInfo(Deque<T>& deque)
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