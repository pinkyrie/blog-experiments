#include<iostream>
using namespace std;

template <typename T>
void foo(T& a) {
    std::cout << a << std::endl;
    std::cout << "Type of T: " << typeid(T).name() << std::endl;  // 打印 T 的类型
    std::cout << "Is T const? " << std::is_const<T>::value << std::endl;
    std::cout << "Is T volatile? " << std::is_volatile<T>::value << std::endl;
}

int main() {
    int x = 5;
    const int& cx = x;
    int arr[3] = {1, 2, 3};

    foo(x);
    foo(cx);
    foo(arr);
}