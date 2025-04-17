//
// Created by Matoka on 2025/3/26.
//
#include <iostream>
using namespace std;

// 通用类模板
template <typename T>
class MyClass {
public:
    void print() {
        cout << "Generic print function" << endl;
    }
};

// 对 MyClass<int> 进行类模板专门化
template <>
class MyClass<int> {
public:
    void print() {
        cout << "Specialized print function for int" << endl;
    }
};

// // 再次尝试对 MyClass<int> 进行专门化（会导致错误）
// template <>
// class MyClass<int> {  // 错误：已对 MyClass<int> 进行了专门化
// public:
//     void print() {
//         cout << "Another specialized print for int" << endl;
//     }
// };

int main() {
    MyClass<double> obj1;
    obj1.print();  // 输出 "Generic print function"

    MyClass<int> obj2;
    obj2.print();  // 输出 "Specialized print function for int"

    return 0;
}