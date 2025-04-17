//
// Created by Matoka on 2024/11/6.
//
#include<iostream>
struct Pig {
    std::string m_name;
    int m_weight;

     Pig(std::string name, int weight)
        : m_name(name)
        , m_weight(weight)
    {}

    Pig(Pig const &other) = default;
};

void show(Pig pig) {
    std::cout << "name: " << pig.m_name << std::endl;
    std::cout << "weight: " << pig.m_weight << std::endl;
}
int main() {
    show({"pig1",20}); //编译不通过 如果去掉explicit 可以执行
    return 0;
}