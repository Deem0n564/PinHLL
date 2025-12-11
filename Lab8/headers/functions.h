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
void printDequeInfo(Deque<T>& deque) {
    std::cout << "\nCurrent deque state:\n";
    std::cout << "Size: " << deque.size() << std::endl;

    if (!deque.empty()) {
        std::cout << "First element: " << deque.get_front() << std::endl;
        std::cout << "Last element: " << deque.get_back() << std::endl;
        std::cout << "Contents: ";
        deque.print();
    }
    else {
        std::cout << "Deque is empty.\n";
    }
}