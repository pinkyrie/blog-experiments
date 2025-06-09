#include<thread>
#include<iostream>
using namespace std;

void hello() {
    cout << "Hello, World!" << endl;
}

int main() {
    thread t (hello); // 创建一个线程，执行 hello 函数
    t.join(); // 等待线程 t 完成
}