//
// Created by Matoka on 2024/11/8.
//
#include <iostream>
#include <string>

// Primary template

void silly(int t) {
    if(t > 0) {
        std::cout << "hi" << t << std::endl;
    }
    else {
        std::cout<< t * "3" <<std::endl;
    }
}

int main() {
    int i = 1;
    int j = -1;
    silly(j);
}


