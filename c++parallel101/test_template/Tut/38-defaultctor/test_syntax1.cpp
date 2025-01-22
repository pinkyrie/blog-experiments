#include <iostream>
#include <vector>

template<typename T>
class Stack {
private:
    std::vector<T> elems;  // 元素存储
public:
    Stack(T const& elem) : elems({elem}) { }  // 带参数构造函数

    // 没有默认构造函数
};

int main() {
    Stack intStack = 0;
    // Stack<int> s;  // 错误！没有默认构造函数
}
