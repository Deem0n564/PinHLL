#pragma once

#include "Node.h"

template <typename T>
class DequeIterator
{
private:
    std::shared_ptr<Node<T>> current;

public:
    explicit DequeIterator(std::shared_ptr<Node<T>> node = nullptr) : current(node) {}

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

    std::shared_ptr<Node<T>> getNode() const
    {
        return current;
    }

    friend bool operator==(const DequeIterator& lhs, const DequeIterator& rhs)
    {
        return lhs.current == rhs.current;
    }

    friend bool operator!=(const DequeIterator& lhs, const DequeIterator& rhs)
    {
        return lhs.current != rhs.current;
    }
};