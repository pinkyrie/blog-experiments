#include <climits>
#include<iostream>
#include <limits>
//
// Created by Matoka on 2024/11/8.
//


// constexpr 绝对值函数
constexpr int abs(int N) {
    // C++17 风格的 guard，用来处理最小值的情况
    static_assert(N != std::numeric_limits<int>::min(), "Value cannot be INT_MIN");
    return (N < 0) ? -N : N;
}

int main() {
    constexpr int n = abs(5);      // 可以作为编译时常量
    constexpr int m = abs(-10);    // 同样支持负值的编译时常量计算
    // constexpr int p = abs(std::numeric_limits<int>::min()); // 会触发 static_assert

    std::cout << n << std::endl;   // 输出: 5
    std::cout << m << std::endl;   // 输出: 10

    return 0;
}