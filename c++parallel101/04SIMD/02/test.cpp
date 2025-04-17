//
// Created by Matoka on 2025/2/26.
//
#include <iostream>
int func(){
    return 42;
}
int main(){
    int a = 1;
    int b = 3;
    int *pa = &a;
    int *pb = &b;

    // *&(a+b)
    // int add = *pa + *pb;
    // std::cout << add << std::endl;
    // auto res = &add;
    // auto star_res = *res;
    // std::cout << star_res << std::endl;

    // &*(a+b)
    int add = a + b;
    auto res = *(int*)add;
    auto amper_res = &res;
    std::cout << res << std::endl;
    std::cout << amper_res << std::endl;

    // test
    // int add = a + b;
    // auto res = &(*(int*)add);
    // std::cout << res << std::endl;
}