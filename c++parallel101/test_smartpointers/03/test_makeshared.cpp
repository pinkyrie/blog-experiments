//
// Created by Matoka on 2024/11/6.
//
#include <iostream>
#include <memory>
struct Test {
    int value;
    explicit Test(int val) {
        value = val;
        std::cout << "Test object created.\n";
    }
    ~Test() {
        std::cout << "Test object destroyed.\n";
    }
};

 int main() {
     std::shared_ptr<Test> sp3 = std::make_shared<Test>(1);
     std::weak_ptr<Test> w4 = sp3;
     sp3.reset();
     std::cout << w4.lock()->value << std::endl; //访问不到
     return 0;
 }