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
    Test* rawPtr = new Test(1); // 分配对象
    std::shared_ptr<Test> sp1(rawPtr);
    std::weak_ptr<Test> wp2;
    wp2 = sp1;
    sp1.reset();
    std::cout << wp2.lock()->value <<std::endl; //访问不到
    return 0;
}
