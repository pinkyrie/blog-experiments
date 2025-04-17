#include <iostream>

// 模板函数声明
template <typename T>
T factorial(T n);

template <typename T>
T factorial(T n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1); // 递归调用
}

int main() {
    int n = 5;
    std::cout << "Factorial of " << n << " is " << factorial(n) << std::endl;
    return 0;
}
