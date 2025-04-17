#include "stack1.hpp"
#include <iostream>
#include <string>
#include "stack2.hpp"
/* created by Matoka in 2025-03-26 20:57:47 */
 int main()
 {
     Stack<int*> ptrStack; // stack of pointers (special implementation)
     ptrStack.push(new int{42});
     std::cout << *ptrStack.top() << std::endl;
     delete ptrStack.pop();
 }
