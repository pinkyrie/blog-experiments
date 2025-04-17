#include "stack1.hpp"
#include <iostream>
#include <string>

void foo(Stack<int> const &s) {
    using IntStack = Stack<int>;
    IntStack istack[10];
    IntStack istack2[10];
    std::cout << istack << std::endl;
}


int main()
{
    Stack<int> intStack; // stack of ints
    Stack<std::string> stringStack; // stack of strings
    // manipulate int stack
    intStack.push(7);
    std::cout << intStack.top() << std::endl;
    // manipulate string stack
    stringStack.push("hello");
    std::cout << stringStack.top() << std::endl;
    // stringStack.pop();

    // foo(intStack);
    stringStack.printOn(std::cout);

    Stack<std::pair<int,int>> ps; // note: std::pair<> has no operator<< defined
    ps.push({4, 5}); // OK
    ps.push({6, 7}); // OK
    std::cout << ps.top().first << std::endl; // OK
    std::cout << ps.top().second << std::endl; // OK

    // ps.printOn(std::cout);
}