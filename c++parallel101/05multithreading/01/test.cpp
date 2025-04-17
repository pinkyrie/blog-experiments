//
// Created by Matoka on 2025/2/26.
//
#include<iostream>
#include<thread>
#include<chrono>


int main() {
    auto t0 = std::chrono::steady_clock::now();
    int temp = 0;
    for(int i = 0; i < 1000000; i++) {
        temp += i;
        // do nothing
    }
    auto t1 = std::chrono::steady_clock::now();
    auto dt = t1 - t0;
    int64_t ns = std::chrono::duration_cast<std::chrono::nanoseconds>(dt).count();
    std::cout <<"time elapsed:" << ns << std::endl;
    std::cout << temp << std::endl;
    return 0;
}
