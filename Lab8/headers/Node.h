#pragma once

#include <memory>

template <typename T>
class Node
{
public:
    T data;
    std::shared_ptr<Node<T>> next = nullptr;
    std::shared_ptr<Node<T>> prev = nullptr;

    explicit Node(const T& value) : data(value) {}
};