//
// Created by Matoka on 2024/11/8.
//
#include<iostream>
#include <type_traits>

// Primary template
template <typename T>
class MyClass {
public:
    void foo() {
        std::cout << "General template foo()\n";
    }
};

// Total specialization for T = int
template <>
void MyClass<int>::foo() {
    std::cout << "Specialized foo() for int\n";
}

int main() {
    MyClass<double> obj1;
    obj1.foo();  // Calls the general template version

    MyClass<int> obj2;
    obj2.foo();  // Calls the specialized version for int

    return 0;
}


