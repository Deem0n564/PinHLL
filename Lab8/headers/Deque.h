#pragma once

#include "functions.h"

template <typename T>
class Deque 
{
private:
    std::shared_ptr<Node<T>> front;
    std::shared_ptr<Node<T>> back;
    size_t size_;

public:
    Deque() : front(nullptr), back(nullptr), size_(0) {}

    Deque(const Deque& other) : front(nullptr), back(nullptr), size_(0) 
    {
        auto current = other.front;
        while (current) 
        {
            push_back(current->data);
            current = current->next;
        }
    }

    ~Deque()
    {
        clear();
    }

    bool empty() const
    {
        return size_ == 0;
    }

    size_t size() const
    {
        return size_;
    }

    T& get_front() const
    {
        if (empty())
        {
            throw std::out_of_range(" Deque is empty");
        }
        return front->data;
    }

    T& get_back() const
    {
        if (empty())
        {
            throw std::out_of_range(" Deque is empty");
        }

        return back->data;
    }

    void push_front(const T& value)
    {
        auto newNode = std::make_shared<Node<T>>(value);

        if (empty())
        {
            front = back = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        size_++;
    }

    void push_back(const T& value)
    {
        auto newNode = std::make_shared<Node<T>>(value);

        if (empty())
        {
            front = back = newNode;
        }
        else
        {
            newNode->prev = back;
            back->next = newNode;
            back = newNode;
        }

        size_++;
    }

    void pop_front()
    {
        if (empty())
        {
            throw std::out_of_range(" Deque is empty");
        }

        if (front == back)
        {
            front = back = nullptr;
        }
        else
        {
            front = front->next;

            if (front)
            {
                front->prev = nullptr;
            }
        }

        size_--;
    }

    void pop_back()
    {
        if (empty())
        {
            throw std::out_of_range(" Deque is empty");
        }

        if (front == back)
        {
            front = back = nullptr;
        }
        else
        {
            back = back->prev;

            if (back)
            {
                back->next = nullptr;
            }
        }

        size_--;
    }

    void clear()
    {
        while (!empty())
        {
            {
                pop_front();
            }
        }
    }

    DequeIterator<T> begin()
    {
        return DequeIterator<T>(front);
    }

    DequeIterator<T> end()
    {
        return DequeIterator<T>(nullptr);
    }

    DequeIterator<T> rbegin()
    {
        return DequeIterator<T>(back);
    }

    void print() const
    {
        auto current = front;
        std::cout << " Deque (size=" << size_ << "): ";

        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }

    void print_reverse() const
    {
        auto current = back;
        std::cout << " Deque reverse: ";

        while (current)
        {
            std::cout << current->data << " ";
            current = current->prev;
        }

        std::cout << std::endl;
    }
};