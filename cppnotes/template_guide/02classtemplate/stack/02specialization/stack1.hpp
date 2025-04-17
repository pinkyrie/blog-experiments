//
// Created by Matoka on 2025/3/26.
//
#include <vector>
#include <cassert>
#include <iostream>
#ifndef STACK1_HPP
#define STACK1_HPP


template<typename T>
class Stack {
private:
    std::vector<T> elems; // elements
public:
    void push(T const &); // push element
    void pop();

    T const& top() const;

    bool empty() const {
        return elems.empty();
    }
    friend std::ostream &operator<<(std::ostream &os, const Stack &stack) {
        for (const auto &elem : stack.elems) {
            os << elem << " ";
        }
        return os;
    }
};

template<typename T>
void Stack<T>::push(T const &elem) {
    elems.push_back(elem); // append copy of passed elem
}

template<typename T>
void Stack<T>::pop() {
    assert(!elems.empty());
    elems.pop_back(); // remove last element
}

template<typename T>
T const& Stack<T>::top() const {
    assert(!elems.empty());
    return elems.back(); // return copy of last element
}

#endif //STACK1_HPP
