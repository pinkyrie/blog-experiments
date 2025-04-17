#include "stack1.hpp"
#include <iostream>
#include <string>
/* created by Matoka in 2025-03-26 20:57:47 */
int main()
{
    Stack<int> intStack; // stack of ints
    Stack<std::string> stringStack; // stack of strings
    // manipulate int stack
    intStack.push(7);
    std::cout << intStack.top() << std::endl;
    intStack.push(1);
    intStack.push(2);
    // manipulate string stack
    stringStack.push("hello");
    std::cout << stringStack.top() << std::endl;
    stringStack.pop();
    std::cout << intStack << std::endl;
}
