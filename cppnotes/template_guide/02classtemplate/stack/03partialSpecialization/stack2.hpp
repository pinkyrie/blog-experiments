//
// Created by Matoka on 2025/3/26.
//
#include <vector>
#include <cassert>
#include <iostream>
#ifndef STACK2_HPP
#define STACK2_HPP

#include "stack1.hpp"
#include <deque>
#include <string>

/* created by Matoka in 2025-03-26 21:43:15 */
/* specialization of class template Stack for type std::string */
#include "stack1.hpp"

// partial specialization of class Stack<> for pointers:
template<typename T>
class Stack<T *> {
private:
    std::vector<T *> elems; // elements
public:
    void push(T *); // push element
    T *pop(); // pop element
    T *top() const; // return top element
    bool empty() const {
        // return whether the stack is empty
        return elems.empty();
    }
};

template<typename T>
void Stack<T *>::push(T *elem) {
    elems.push_back(elem); // append copy of passed elem
}

template<typename T>
T *Stack<T *>::pop() {
    assert(!elems.empty());
    T *p = elems.back();
    elems.pop_back(); // remove last element
    return p; // and return it (unlike in the general case)
}

template<typename T>
T *Stack<T *>::top() const {
    assert(!elems.empty());
    return elems.back(); // return copy of last element
}

#endif //STACK2_HPP
