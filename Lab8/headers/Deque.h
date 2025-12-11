#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>
#include "Node.h"
#include "DequeIterator.h"

template <typename T>
class Deque {
private:
    std::shared_ptr<Node<T>> front = nullptr;
    std::shared_ptr<Node<T>> back = nullptr;
    size_t size_ = 0;

public:
    Deque() = default;

    Deque(const Deque& other) {
        auto current = other.front;
        while (current) {
            push_back(current->data);
            current = current->next;
        }
    }

    Deque& operator=(const Deque& other) {
        if (this != &other) {
            clear();
            auto current = other.front;
            while (current) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    Deque(Deque&& other)
        : front(std::move(other.front)), back(std::move(other.back)), size_(other.size_) {
        other.size_ = 0;
    }

    Deque& operator=(Deque&& other) {
        if (this != &other) {
            clear();
            front = std::move(other.front);
            back = std::move(other.back);
            size_ = other.size_;
            other.size_ = 0;
        }
        return *this;
    }

    ~Deque() {
        clear();
    }

    bool empty() const {
        return size_ == 0;
    }

    size_t size() const {
        return size_;
    }

    T& get_front() const {
        if (empty()) {
            throw std::out_of_range("Deque is empty");
        }
        return front->data;
    }

    T& get_back() const {
        if (empty()) {
            throw std::out_of_range("Deque is empty");
        }
        return back->data;
    }

    void push_front(const T& value) {
        auto newNode = std::make_shared<Node<T>>(value);

        if (empty()) {
            front = back = newNode;
        }
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size_++;
    }

    void push_back(const T& value) {
        auto newNode = std::make_shared<Node<T>>(value);

        if (empty()) {
            front = back = newNode;
        }
        else {
            newNode->prev = back;
            back->next = newNode;
            back = newNode;
        }
        size_++;
    }

    void pop_front() {
        if (empty()) {
            throw std::out_of_range("Deque is empty");
        }

        if (front == back) {
            front = back = nullptr;
        }
        else {
            front = front->next;
            if (front) {
                front->prev = nullptr;
            }
        }
        size_--;
    }

    void pop_back() {
        if (empty()) {
            throw std::out_of_range("Deque is empty");
        }

        if (front == back) {
            front = back = nullptr;
        }
        else {
            back = back->prev;
            if (back) {
                back->next = nullptr;
            }
        }
        size_--;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    DequeIterator<T> begin() {
        return DequeIterator<T>(front);
    }

    DequeIterator<T> end() {
        return DequeIterator<T>(nullptr);
    }

    DequeIterator<T> rbegin() {
        return DequeIterator<T>(back);
    }

    void print() const {
        auto current = front;
        std::cout << "Deque (size=" << size_ << "): ";
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void print_reverse() const {
        auto current = back;
        std::cout << "Deque reverse: ";
        while (current) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
};