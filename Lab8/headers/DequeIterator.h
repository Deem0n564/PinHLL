#pragma once

#include "functions.h"

template <typename T>
class DequeIterator 
{
private:
    std::shared_ptr<Node<T>> current;

public:
    DequeIterator(std::shared_ptr<Node<T>> node = nullptr) : current(node) {}

    DequeIterator& operator++() 
    {
        if (current)
        {
            current = current->next;
        }

        return *this;
    }

    DequeIterator operator++(int) 
    {
        DequeIterator temp = *this;
        ++(*this);

        return temp;
    }

    DequeIterator& operator--() 
    {
        if (current)
        {
            current = current->prev;
        }

        return *this;
    }

    DequeIterator operator--(int) 
    {
        DequeIterator temp = *this;
        --(*this);

        return temp;
    }

    T& operator*() const 
    {
        return current->data;
    }

    T* operator->() const 
    {
        return &current->data;
    }

    bool operator==(const DequeIterator& other) const 
    {
        return current == other.current;
    }

    bool operator!=(const DequeIterator& other) const 
    {
        return current != other.current;
    }

    std::shared_ptr<Node<T>> getNode() const 
    {
        return current;
    }
};