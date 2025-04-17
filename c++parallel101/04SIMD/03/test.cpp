//
// Created by Matoka on 2025/2/26.
//
#include <array>
#include <vector>
#include <iostream>
template <int N>
constexpr int func_impl1(){
    std::array<int,N> arr{};
    for (int i = 1; i <= N; i++){
        arr[i-1] = i;
    }
    int res = 0;
    for (int i = 1; i <= N; i++){
        res += arr[i-1];
    }
    return res;
}

int main(){
    constexpr int res = func_impl1<50000>();
    return res;
}