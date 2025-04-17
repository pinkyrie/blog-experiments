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
template<>
class Stack<std::string> {
private:
    std::deque<std::string> elems; // elements
public:
    void push(std::string const&); // push element
    void pop(); // pop element
    std::string const& top() const; // return top element
    bool empty() const { // return whether the stack is empty
        return elems.empty();
    }
};
void Stack<std::string>::push (std::string const& elem)
{
    elems.push_back(elem); // append copy of passed elem
}

void Stack<std::string>::pop ()
{
    assert(!elems.empty());
    elems.pop_back(); // remove last element
}
std::string const& Stack<std::string>::top () const
{
    assert(!elems.empty());
    return elems.back(); // return copy of last element
}

#endif //STACK2_HPP
