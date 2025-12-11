#pragma once

#include "functions.h"

template <typename T>
class DequeAlgorithm 
{
public:
    static DequeIterator<T> linear_search(Deque<T>& deque, const T& value) 
    {
        for (auto it = deque.begin(); it != deque.end(); ++it) 
        {
            if (*it == value) 
            {
                return it;
            }
        }

        return deque.end();
    }

    static DequeIterator<T> binary_search(Deque<T>& deque, const T& value) 
    {
        if (deque.empty()) 
        {
            return deque.end();
        }

        auto left = deque.begin();
        auto right = deque.begin();

        int count = 0;

        while (right != deque.end() && DequeIterator<T>(right) != deque.end()) 
        {
            ++right;
            count++;
        }

        int left_idx = 0;
        int right_idx = count - 1;

        while (left_idx <= right_idx) 
        {
            int mid_idx = left_idx + (right_idx - left_idx) / 2;
            auto mid = left;

            for (int i = 0; i < mid_idx && mid != deque.end(); i++) 
            {
                ++mid;
            }

            if (mid == deque.end()) 
            {
                break;
            }

            if (*mid == value) 
            {
                return mid;
            }
            else if (*mid < value) 
            {
                left_idx = mid_idx + 1;
                left = mid;
                ++left;
            }
            else 
            {
                right_idx = mid_idx - 1;
                right = mid;

                if (right != deque.begin())
                {
                    --right;
                }
            }
        }

        return deque.end();
    }

    static void bubble_sort(Deque<T>& deque) 
    {
        if (deque.size() <= 1)
        {
            return;
        }

        bool swapped;

        for (size_t i = 0; i < deque.size() - 1; i++) 
        {
            swapped = false;
            auto it1 = deque.begin();
            auto it2 = deque.begin();
            ++it2;

            for (size_t j = 0; j < deque.size() - i - 1 && it2 != deque.end(); j++) 
            {
                if (*it1 > *it2) 
                {
                    std::swap(*it1, *it2);
                    swapped = true;
                }

                ++it1;
                ++it2;
            }

            if (!swapped)
            {
                break;
            }
        }
    }

    static void insertion_sort(Deque<T>& deque) 
    {
        if (deque.size() <= 1)
        {
            return;
        }

        auto current = deque.begin();
        ++current;

        while (current != deque.end()) 
        {
            T key = *current;
            auto j = current;

            auto prev = j;

            if (prev != deque.begin())
            {
                --prev;
            }

            while (j != deque.begin() && *prev > key) 
            {
                *j = *prev;
                --j;

                if (j != deque.begin())
                {
                    --prev;
                }
            }

            *j = key;
            ++current;
        }
    }
};