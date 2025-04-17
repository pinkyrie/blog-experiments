#include <climits>
#include<iostream>
//
// Created by Matoka on 2024/11/8.
//
template<int N> // template param used as the metafctn param
struct absTest {
    static_assert(N != INT_MIN); // C++17-style guard
    static constexpr auto value = (N < 0) ? -N : N; // “return”
};
// 对比template struct和单纯的constexpr function
// 使用示例 (a metafunction call):
// Metafunction arg(s) are supplied as the template’s arg(s).
// “Call” syntax is a request for the template’s published value.

int main() {
//    for(int i = 1; i <= 10; i++) {
//      std::cout << absTest<i>::value << std::endl;
//    }
    int const n = absTest<-5>::value; // could instead declare as constexpr
    int const m = absTest<-10>::value;
    // abs<-2147483648>::value; // This would trigger the static_assert
    std::cout << n << std::endl;
    std::cout << m << std::endl;
    return 0;
}
