//
// Created by Matoka on 2025/2/26.
//
#include <iostream>
#include "func.h"
int other(int a);

int func(){
    return other(233);
}

int main(){
    int res = func();
    std::cout << res << std::endl;
    return 0;
}