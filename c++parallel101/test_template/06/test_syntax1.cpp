//
// Created by Matoka on 2024/11/8.
//
#include <iostream>
#include <type_traits>
#include <string>

// Primary template
template <typename T>
auto func(T t) {
    if (std::is_same_v<T,int>) {
      return t + 1;
    }
    else{
      return t.substr(1);
    }
}

int main() {
    int i = 0;
    std::cout << func(i) << std::endl;
    std::string s = "hello";
    std::cout << func(s) << std::endl;
}


