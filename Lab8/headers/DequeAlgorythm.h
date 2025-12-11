#pragma once

#include "Deque.h"

template <typename T>
class DequeAlgorithm {
public:
    static DequeIterator<T> linear_search(Deque<T>& deque, const T& value) {
        for (auto it = deque.begin(); it != deque.end(); ++it) {
            if (*it == value) {
                return it;
            }
        }
        return deque.end();
    }

    static void insertion_sort(Deque<T>& deque) {
        if (deque.size() <= 1) {
            return;
        }

        auto current = deque.begin();
        ++current;

        while (current != deque.end()) {
            T key = *current;
            auto j = current;

            if (j == deque.begin()) {
                ++current;
                continue;
            }

            auto prev = j;
            --prev;

            while (j != deque.begin() && *prev > key) {
                *j = *prev;
                --j;
                if (j != deque.begin()) {
                    --prev;
                }
            }

            *j = key;
            ++current;
        }
    }
};